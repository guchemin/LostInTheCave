#include "../../../include/Entidades/Personagem/Atirador.hpp"

namespace Entidades
{
    namespace Personagem
    {
        Atirador::Atirador(sf::Vector2f pos):
            Inimigo(pos, sf::Vector2f(50.0f, 70.0f), TIPO::ATIRADOR),
            pProjetil(NULL)
        {
            raioAtaque = RAIO_ATIRADOR;
            vida = 60.0f;
            dano = DANO_ATIRADOR;

            inicializarAnimacao();
        }

        Atirador::Atirador():
            pProjetil(NULL)
        {
        }

        Atirador::~Atirador()
        {
            pProjetil = NULL;
        }

        nlohmann::json Atirador::salvarJogo() // salva apenas o que é exclusivamente da classe e chama o salvarJogo da classe mãe
        {
            nlohmann::json j = Inimigo::salvarJogo();
            return j;
        }

        void Atirador::inicializarAnimacao()
        {
            sf::Vector2f origem = sf::Vector2f(getTamanho().x / 3.5, getTamanho().y / 3.5);

            animacao.addAnimacao(CAMINHO_ATIRADOR_PARADO, "parado", 12, 0.07f, sf::Vector2f(2.4f, 1.8f), origem);
            animacao.addAnimacao(CAMINHO_ATIRADOR_ATACANDO, "atacando", 9, 0.05f, sf::Vector2f(2.4f, 1.8f), origem);
        }

        void Atirador::atualizarAnimacao()
        {
            if(atacando)
            {
                animacao.atualizar(direcao, "atacando");
            }
            else
            {
                animacao.atualizar(direcao, "parado");
            }
        }

        void Atirador::setProjetil(Projetil *proj) 
        {
            if(proj)
            {
                pProjetil = proj;
            }
        }

        bool Atirador::consegueAtacar()
        {
            // verifica cooldown
            if(tempoAtaque >= COOLDOWN_ATIRADOR)
            {
                if(pProjetil->getPosicao().x <= -800.0f && pProjetil->getPosicao().y <= -800.0f)
                {
                    iniciouAtaque = false;
                    tempoAtaque = 0.0f;
                    return true;
                }
            }
            return false;
        }

        void Atirador::atacar() // puxa o projetil "de fora da tela" e o atira
        {
            setAtacando(true);
            sf::Vector2f velProj = calcVel();
            sf::Vector2f posProj = sf::Vector2f(getCentro().x, getPosicao().y + getTamanho().y / 2.8f);
            pProjetil->setPosicao(posProj);
            pProjetil->setVelocidade(velProj);
        }

        void Atirador::agir()
        {
            if(pJogador->getPosicao().x > getPosicao().x)
            {
                direcao = true;
            }
            else
            {
                direcao = false;
            }

            if(consegueAtacar())
            {
                atacar();
            }
        }

        void Atirador::executar(const float dt)
        {
            if(atacando)
            {
                tempoAnimacaoAtaque += dt;
                if(tempoAnimacaoAtaque >= TEMPO_TOTAL_ATAQUE_ATIRADOR)
                {
                    atacando = false;
                    tempoAnimacaoAtaque = 0.0f;
                }
            }

            if(tomouDano)
            {
                tempoTomouDano += dt;
                corpo.setFillColor(sf::Color(255, 0, 0, 200));
                if(tempoTomouDano >= TEMPO_TOMOU_DANO)
                {
                    corpo.setFillColor(sf::Color(255, 255, 255, 255));
                    tomouDano = false;
                    tempoTomouDano = 0.0f;
                }
            }
            float dy;
            
            //acao da gravidade
            vel.y += GRAVIDADE * dt;
            dy = vel.y * dt;
            corpo.move(0.0f, dy);

            tempoAtaque += dt;
            
            if(pProjetil->saiuDaTela())
            {
                pProjetil->setPosicao(sf::Vector2f(-1000.0f, -1000.0f));
                pProjetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
            }

            atualizarAnimacao();
        }

        sf::Vector2f Atirador::calcVel() // calcula velocidade em x e y do projetil com base na posição do jogador
        {
            if(pJogador == NULL)
            {
                return sf::Vector2f(0.0f, 0.0f);
            }
            
            float Dx;
            float Dy;
            float theta;
            sf::Vector2f velProj;

            if(pJogador->getCentro().x > getCentro().x)
            {    
                Dx = pJogador->getPosicao().x - getCentro().x;
            }
            else
            {    
                Dx = getCentro().x - (pJogador->getPosicao().x + pJogador->getTamanho().x);
            }
            
            Dy = (pJogador->getPosicao().y - pJogador->getTamanho().y / 5.0f) - (getPosicao().y + getTamanho().y / 2.0f);
            

            theta = atan(fabs(Dy / Dx));

            if(pJogador->getCentro().x > getCentro().x)
            {    
                velProj.x = VEL_PROJ * cos(theta);
            }
            else
            {
                velProj.x = -VEL_PROJ * cos(theta);
            }

            if(pJogador->getPosicao().y > getPosicao().y)
            {
                velProj.y = VEL_PROJ * sin(theta);
            }
            else
            {
                velProj.y = -VEL_PROJ * sin(theta);
            }
            return velProj;
        }

        const float Atirador::getPontuacao() const
        {
            return PONTUACAO_ATIRADOR;
        }
        
        void Atirador::colide(Entidade *ent, const sf::Vector2f intersec)
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
                else
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
            
            default:
                break;
            }
            
        }       
    }
}