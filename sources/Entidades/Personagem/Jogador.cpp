#include "../../../include/Entidades/Personagem/Jogador.hpp"
#include "../../../include/Entidades/Personagem/Inimigo.hpp"

namespace Entidades
{
    namespace Personagem
    {
        float Jogador::pontuacao = 0.0f;

        Jogador::Jogador(sf::Vector2f pos, const ID i):
            id(i),
            obs(this),
            Personagem(pos, sf::Vector2f(50.0f, 70.0f), TIPO::JOGADOR),
            pulou(false),
            estaNaTeia(false),
            foiEspinhado(false),
            aceleracaoTeia(1.0f)
        {
            raioAtaque = 100.0f;
            vida = 100.0f;
            dano = DANO_JOGADOR;

            inicializarAnimacao();
        }

        Jogador::Jogador():
            id(JOGADOR1)
        {
        }

        Jogador::~Jogador()
        {
        }

        nlohmann::json Jogador::salvarJogo() // salva apenas o que é exclusivamente da classe e chama o salvarJogo da classe mãe
        {
            nlohmann::json j = Personagem::salvarJogo();
            j["id"] = id;
            j["pulou"] = pulou;
            j["estaNaTeia"] = estaNaTeia;
            j["foiEspinhado"] = foiEspinhado;
            j["pontuacao"] = pontuacao;
            return j;
        }

        void Jogador::inicializarAnimacao()
        {
            sf::Vector2f origem = sf::Vector2f(getTamanho().x / 3.5, getTamanho().y / 3.5);

            if(id == JOGADOR1)
            {
                animacao.addAnimacao(CAMINHO_JOG1_ANDANDO, "andando", 12, 0.05f, sf::Vector2f(2.4f, 1.8f), origem);
                animacao.addAnimacao(CAMINHO_JOG1_PARADO, "parado", 9, 0.1f, sf::Vector2f(2.4f, 1.8f), origem);
                animacao.addAnimacao(CAMINHO_JOG1_ATACANDO, "atacando", 12, 0.035f, sf::Vector2f(2.4f, 1.8f), origem);
                animacao.addAnimacao(CAMINHO_JOG1_NO_AR, "no_ar", 6, 0.1f, sf::Vector2f(2.4f, 1.8f), origem);

            }
            else if(id == JOGADOR2)
            {
                animacao.addAnimacao(CAMINHO_JOG2_ANDANDO, "andando", 12, 0.05f, sf::Vector2f(2.4f, 1.8f), origem);
                animacao.addAnimacao(CAMINHO_JOG2_PARADO, "parado", 9, 0.1f, sf::Vector2f(2.4f, 1.8f), origem);
                animacao.addAnimacao(CAMINHO_JOG2_ATACANDO, "atacando", 12, 0.035f, sf::Vector2f(2.4f, 1.8f), origem);
                animacao.addAnimacao(CAMINHO_JOG2_NO_AR, "no_ar", 6, 0.1f, sf::Vector2f(2.4f, 1.8f), origem);
            }

        }

        void Jogador::atualizarAnimacao()
        {
            if(vel.x != 0.0f && estaNoChao && !atacando)
            {
                animacao.atualizar(vel.x > 0.0f, "andando");
            }
            else if(atacando)
            {
                animacao.atualizar(direcao, "atacando");
            }
            else if(!estaNoChao && pulou)
            {
                animacao.atualizar(direcao, "no_ar");
            }
            else
            {
                animacao.atualizar(direcao, "parado");
            }
        }

        void Jogador::autorizarPulo(const bool autoriza) // para que o jogador não pule enquanto está no ar ou enquanto não soltar a tecla
        {
            pulou = !autoriza;
        }

        const bool Jogador::podePular()
        {
            return estaNoChao && !pulou;
        }

        void Jogador::parouDeAtacar() // função usada para melhorar animação, sem interferência importante na funcionalidade
        {
            iniciouAtaque = false;
        }

        const bool Jogador::podeAtacar(bool direita)
        {
            if(tempoAtaque >= COOLDOWN_ATAQUE)
            {
                if(iniciouAtaque && (direcao == direita))
                {
                    tempoAtaque = 0.0f;
                    iniciouAtaque = false;
                    return true;
                }
            }
            return false;
        }

        void Jogador::executar(const float dt)
        {
            tempoAtaque += dt;

            if(atacando)
            {
                tempoAnimacaoAtaque += dt;
                if(tempoAnimacaoAtaque >= TEMPO_TOTAL_ATAQUE)
                {
                    atacando = false;
                    tempoAnimacaoAtaque = 0.0f;
                }
            }

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

            if(estaNaTeia)
            {
                desacelerarTeia();
                estaNaTeia = false;
            }

            ds.y = vel.y * dt;
            ds.x = vel.x * dt;

            if(vel.y > GRAVIDADE * dt * 3)
                estaNoChao = false;
            
            corpo.move(ds);

            // acao da gravidade para a proxima iteracao
            vel.y += GRAVIDADE * dt;

            atualizarAnimacao();
        }

        void Jogador::pular()
        {
            if(id == JOGADOR1)
            {
                vel.y = -PULO_JOG1;
                vel.x *= 1.5f;
            } 
            else if(id == JOGADOR2)
            {
                vel.y = -PULO_JOG2;
                vel.x *= 1.5f;
            }
            estaNoChao = false;
        }

        void Jogador::setPulou(const bool p)
        {
            pulou = p;
        }

        void Jogador::andar(const bool direita)
        {
            if(foiEspinhado)
                return;

            if(id == JOGADOR1)
            {
                vel.x = VEL_JOG1;
                if(!estaNoChao)
                    vel.x *= 1.5f;
            }
            else if(id == JOGADOR2)
            {
                vel.x = VEL_JOG2;
                if(!estaNoChao)
                    vel.x *= 1.5f;
            }

            if(!direita)
                vel.x *= -1.0f;
            
            direcao = direita;
        }

        void Jogador::parar()
        {
            vel.x = 0.0f;
        }

        void Jogador::ajustarVelocidade() // apos cair de um pulo, ajusta a velocidade para a velocidade normal
        {
            if(vel.x < 0.0f)
            {
                if(id == JOGADOR1)
                {
                    vel.x = -VEL_JOG1;
                }
                else if(id == JOGADOR2)
                {
                    vel.x = -VEL_JOG2;
                }
            }
            else if(vel.x > 0.0f)
            {
                if(id == JOGADOR1)
                {
                    vel.x = VEL_JOG1;
                }
                else if(id == JOGADOR2)
                {
                    vel.x = VEL_JOG2;
                }
            }
        }

        void Jogador::setEspinhado(const bool esp)
        {
            foiEspinhado = esp;
        }

        void Jogador::setNaTeia(const bool teia)
        {
            estaNaTeia = teia;
        }

        void Jogador::desacelerarTeia()
        {
            if(id == JOGADOR1)
            {
                if(fabs(vel.x) > VEL_JOG1 * 0.35)
                {
                    vel.x *= aceleracaoTeia;
                }
            }
            else if(id == JOGADOR2)
            {
                if(fabs(vel.x) > VEL_JOG2 * 0.35f)
                {
                    vel.x *= aceleracaoTeia;
                }
            }
        }

        void Jogador::colide(Entidade *ent, const sf::Vector2f intersec)
        {
            switch (ent->getTipo())
            {
            case TIPO::PLATAFORMA:
            {
                if(intersec.x > intersec.y || vel.x == 0.0f)
                {
                    if(getPosicao().y > ent->getPosicao().y)
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
                    }
                    else
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                        estaNoChao = true;
                        ajustarVelocidade();
                    }
                    vel.y = 0.0f;
                    
                    if(foiEspinhado)
                    {
                        vel.x = 0.0f;
                        foiEspinhado = false;
                    }
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

            case TIPO::TEIA: // teia é um obstaculo que diminui a velocidade do jogador
            {
                estaNaTeia = true;
                Obstaculos::Teia* teia = static_cast<Obstaculos::Teia*>(ent);
                aceleracaoTeia = 1.0f / teia->getDensidade();
                vel.y *= 2 * aceleracaoTeia;
                break;
            }

            case TIPO::ESPINHO: // espinho é um obstaculo que danifica o jogador e o joga para cima
            {
                Obstaculos::Espinho* espinho = static_cast<Obstaculos::Espinho*>(ent);
                foiEspinhado = true;
                vel.y = -1000.0f;
                if(getCentro().x > ent->getCentro().x)
                {
                    vel.x = 300.0f;
                }
                else
                {
                    vel.x = -300.0f;
                }
                break;
            }

            case TIPO::CHEFAO:
            {
                if((intersec.x > intersec.y || vel.x == 0.0f))
                {
                    if(getPosicao().y <= ent->getPosicao().y)
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                        estaNoChao = true;
                    }
                    vel.y = 0.0f;

                    if(foiEspinhado)
                    {
                        vel.x = 0.0f;
                        foiEspinhado = false;
                    }
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

            case TIPO::VOADOR:
            {
                if((intersec.x > intersec.y || vel.x == 0.0f))
                {
                    if(getPosicao().y <= ent->getPosicao().y)
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                        estaNoChao = true;
                    }
                    vel.y = 0.0f;

                    if(foiEspinhado)
                    {
                        vel.x = 0.0f;
                        foiEspinhado = false;
                    }
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
                if((intersec.x > intersec.y || vel.x == 0.0f))
                {
                    if(getPosicao().y <= ent->getPosicao().y)
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                        estaNoChao = true;
                    }
                    vel.y = 0.0f;

                    if(foiEspinhado)
                    {
                        vel.x = 0.0f;
                        foiEspinhado = false;
                    }
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

            case TIPO::PEDRA:
            {
                if(intersec.x > intersec.y || vel.x == 0.0f)
                {
                    if(getPosicao().y > ent->getPosicao().y)
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
                    }
                    else
                    {
                        if(getPosicao().y + getTamanho().y >= ent->getPosicao().y + ent->getTamanho().y)
                        {
                            if(getPosicao().x > ent->getPosicao().x)
                            {
                                setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y)); 
                            }
                            else
                            {
                                setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
                            }
                            
                            Obstaculos::Pedra* pedra = static_cast<Obstaculos::Pedra*>(ent);
                            if(vel.x > 0.0f)
                                pedra->arrastar(true);
                            else if(vel.x < 0.0f)
                                pedra->arrastar(false);
                            pedra = NULL;
                            return;
                        }
                        else
                        {
                            setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                            estaNoChao = true;
                            ajustarVelocidade();
                        }
                    }
                    vel.y = 0.0f;
                    
                    if(foiEspinhado)
                    {
                        vel.x = 0.0f;
                        foiEspinhado = false;
                    }
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
                    Obstaculos::Pedra* pedra = static_cast<Obstaculos::Pedra*>(ent);
                    if(vel.x > 0.0f)
                        pedra->arrastar(true);
                    else if(vel.x < 0.0f)
                        pedra->arrastar(false);
                    pedra = NULL;
                }
                break;
            }
            
            default:
                break;
            }
        }

        const float Jogador::getPontuacao()
        {
            return pontuacao;
        }

        void Jogador::somaPontos(const float p)
        {
            pontuacao += p;
        }

        void Jogador::setPontuacao(const float p)
        {
            pontuacao = p;
        }
    }
}