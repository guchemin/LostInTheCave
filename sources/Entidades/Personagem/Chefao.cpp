#include "../../../include/Entidades/Personagem/Chefao.hpp"

namespace Entidades
{
    namespace Personagem
    {
        Chefao::Chefao(sf::Vector2f pos):
            Inimigo(pos, sf::Vector2f(80.0f, 120.0f), TIPO::CHEFAO),
            estaPerseguindo(false),
            tempoMudancaDirecao(0.0f)
        {
            vel = sf::Vector2f(VEL_CHEFAO, 0.0f);
            raioAtaque = RAIO_ATAQUE_CHEFAO;
            vida = 150.0f;
            dano = DANO_CHEFAO;

            inicializarAnimacao();
        }

        Chefao::Chefao()
        {
        }

        Chefao::~Chefao()
        {
        }

        nlohmann::json Chefao::salvarJogo() // salva apenas o que é exclusivamente da classe e chama o salvarJogo da classe mãe
        {
            nlohmann::json j = Inimigo::salvarJogo();
            j["estaPerseguindo"] = estaPerseguindo;
            return j;
        }

        void Chefao::setPerseguindo(bool perseg)
        {
            estaPerseguindo = perseg;
        }

        void Chefao::inicializarAnimacao()
        {
            sf::Vector2f origem = sf::Vector2f(getTamanho().x / 3.5, getTamanho().y / 3.5);

            animacao.addAnimacao(CAMINHO_CHEFAO_ANDANDO, "andando", 12, 0.07f, sf::Vector2f(2.4f, 1.8f), origem);
            animacao.addAnimacao(CAMINHO_CHEFAO_CORRENDO, "correndo", 12, 0.05f, sf::Vector2f(2.4f, 1.8f), origem);
            animacao.addAnimacao(CAMINHO_CHEFAO_ATACANDO, "atacando", 12, 0.035f, sf::Vector2f(2.4f, 1.8f), origem);
        }

        void Chefao::atualizarAnimacao()
        {
            if(fabs(vel.x) > VEL_CHEFAO)
            {
                animacao.atualizar(direcao,"correndo");
            }
            else if(vel.x != 0.0f)
            {
                animacao.atualizar(direcao, "andando");
            }
            else
            {
                animacao.atualizar(direcao, "atacando");
            }
        }

        void Chefao::perseguir(const float dt) // persegue o jogador
        {
            float dx;

            if(pJogador->getPosicao().x > getPosicao().x + getTamanho().x + 1.0)
            {   
                vel.x = VEL_CHEFAO_PERSEG;
                direcao = true;
            }
            else if(pJogador->getPosicao().x + pJogador->getTamanho().x < getPosicao().x - 1.0f)
            {
                vel.x = -VEL_CHEFAO_PERSEG;
                direcao = false;
            }
            else
            {
                vel.x = 0.0f;
            }
            
            dx = vel.x * dt;
            corpo.move(dx, 0.0f);
        }

        void Chefao::moverAleatorio(const float dt) // movimenta o chefão aleatoriamente, mudando de diração a cada 6 segundos
        {
            float dx;
            ajustaVelocidade();
            tempoMudancaDirecao += dt;

            if(tempoMudancaDirecao > TEMPO_MUDANCA_DIRECAO)
            {
                tempoMudancaDirecao = 0.0f;
                vel.x = -vel.x;
            }
            direcao = vel.x > 0.0f;

            dx = vel.x * dt;
            corpo.move(dx, 0.0f);
        }

        void Chefao::ajustaVelocidade() // diminui a velocidade do chefão quando ele deixa de perseguir o jogador
        {
            if(!estaPerseguindo)
            {
                if(vel.x > 0.0f)
                {
                    vel.x = VEL_CHEFAO;
                }
                else
                {
                    vel.x = -VEL_CHEFAO;
                }
            }
        }

        bool Chefao::consegueAtacar()
        {
            if(tempoAtaque >= COOLDOWN_CHEFAO && tempoAnimacaoAtaque >= TEMPO_BATIDA)
            {
                tempoAtaque = 0.0f;
                return true;
            }
            return false;
        }

        void Chefao::atacar()
        {   
            (*pJogador)-=dano;
            if(pJogador->getVida() <= 0.0f)
            {
                pJogador = NULL;
            }
        }

        void Chefao::agir()
        {
            if(consegueAtacar())
            {
                atacar();
            }
        }

        void Chefao::executar(const float dt)
        {
            if(animacao.getImagemAtual() == "atacando")
            {
                tempoAnimacaoAtaque += dt;
            }
            else
            {
                tempoAnimacaoAtaque = 0.0f;
            }
            tempoAtaque += dt;
            
            float dy;
            sf::Vector2f posChefao = getPosicao();
            
            if(tomouDano)
            {
                tempoTomouDano += dt;
                corpo.setFillColor(sf::Color(255, 0, 0, 120));
                if(tempoTomouDano >= TEMPO_TOMOU_DANO)
                {
                    corpo.setFillColor(sf::Color(255, 255, 255, 255));
                    tomouDano = false;
                    tempoTomouDano = 0.0f;
                }
            }

            //acao da gravidade
            vel.y += GRAVIDADE * dt;
            dy = vel.y * dt;
            corpo.move(0.0f, dy);
            
            if(pJogador == NULL)
            {
                estaPerseguindo = false;
                moverAleatorio(dt);
            }    
            else
            {
                sf::Vector2f posJog = pJogador->getPosicao();
                if(fabs(posChefao.x - posJog.x) < RAIO_CHEFAO_X && fabs(posChefao.y - posJog.y) < RAIO_CHEFAO_Y)
                {
                    perseguir(dt);
                    estaPerseguindo = true;
                    posInicial = posChefao;
                }
                else
                {
                    estaPerseguindo = false;
                    moverAleatorio(dt);
                }
            }

            atualizarAnimacao();
        }

        void Chefao::colide(Entidade *ent, const sf::Vector2f intersec)
        {
            switch (ent->getTipo())
            {
            case TIPO::PLATAFORMA:
            {
                if(intersec.x > intersec.y)
                {
                    if(getPosicao().y > ent->getPosicao().y)
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
                    }
                    else
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                        estaNoChao = true;
                    }
                    vel.y = 0.0f;
                }
                else if(intersec.y > 2.0f)
                {
                    if(getPosicao().x > ent->getPosicao().x)
                    {
                        setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));    
                    }
                    else
                    {
                        setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                    }
                }
                break;
            }
            case TIPO::ATIRADOR:
            {
                if(getPosicao().x > ent->getPosicao().x)
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));
                }
                else
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                }
                break;
            }
            case TIPO::VOADOR:
            {
                if(getPosicao().x > ent->getPosicao().x)
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));
                }
                else
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                }
                break;
            }
            case TIPO::CHEFAO:
            {
                if(getPosicao().x > ent->getPosicao().x)
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));
                }
                else
                {
                    setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                }
                break;
            }
            
            default:
                break;
            }

        }
        
        float Chefao::getPontuacao()
        {
            return PONTUACAO_CHEFAO;
        }
    }
}