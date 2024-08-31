#include "../../../include/Entidades/Personagem/Voador.hpp"

namespace Entidades
{
    namespace Personagem
    {
        Voador::Voador(sf::Vector2f pos):
            Inimigo(pos, sf::Vector2f(35.0f, 50.0f), TIPO::VOADOR),
            endiabrado(bool(rand() % 2))
        {
            vel = sf::Vector2f(VEL_VOADOR, VEL_VOADOR);
            dano = DANO_VOADOR;
            if(endiabrado)
            {
                vel.x *= 2.5f;
                dano *= 1.5f;
            }

            raioAtaque = 74.0f;
            vida = 25.0f;

            inicializarAnimacao();
        }

        Voador::Voador():
            endiabrado(false)
        {
        }

        Voador::~Voador()
        {
        }

        nlohmann::json Voador::salvarJogo() // salva apenas o que é exclusivamente da classe e chama o salvarJogo da classe mãe
        {
            nlohmann::json j = Inimigo::salvarJogo();
            j["endiabrado"] = endiabrado;
            return j;
        }

        void Voador::inicializarAnimacao()
        {
            sf::Vector2f origem = sf::Vector2f(getTamanho().x / 3.5, getTamanho().y / 3.5);

            animacao.addAnimacao(CAMINHO_VOADOR, "voando", 18, 0.1f, sf::Vector2f(2.4f, 1.8f), origem);
        }

        void Voador::atualizarAnimacao()
        {
            animacao.atualizar(vel.x >= 0, "voando");
        }

        bool Voador::consegueAtacar()
        {
            if(tempoAtaque >= COOLDOWN_VOADOR)
            {
                if(atingiuJogador())
                {
                    tempoAtaque = 0.0f;
                    return true;
                }
            }
            return false;
        }

        bool Voador::atingiuJogador()
        {
            return corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds());
        }

        void Voador::atacar()
        { 
            (*pJogador)-=dano;
        }

        void Voador::agir()
        {
            if(consegueAtacar())
            {   
                atacar();
            }
        }

        void Voador::executar(const float dt)
        {
            sf::Vector2f ds;

            tempoAtaque += dt;

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

            if(getPosicao().y < posInicial.y - 70.0f)
            {
                vel.y = 0.0f;
            }
            else if(getPosicao().y > posInicial.y + 70.0f)
            {
                vel.y = -VEL_VOADOR;
            }

            if(getPosicao().x < posInicial.x - 300.0f || getPosicao().x > posInicial.x + 300.0f)
            {
                vel.x = -vel.x;
            }

            if(vel.y < 0)
            {
                vel.y -= 1000.0f * dt;
            }

            //acao da gravidade
            vel.y += 1000.0f * dt;
            
            ds = vel * dt;
            corpo.move(ds);

            atualizarAnimacao();
        }

        void Voador::colide(Entidade *ent, const sf::Vector2f intersec)
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
                        vel.y = 0.0f;
                    }
                    else
                    {
                        setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                        estaNoChao = true;
                        vel.y = -VEL_VOADOR;    
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
                    vel.x = -vel.x;
                }
                break;
            }

            case TIPO::JOGADOR:
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
                    vel.y = -vel.y;
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
                    vel.x = -vel.x;
                }
                break;
            }
            
            case TIPO::ATIRADOR:
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
                    vel.y = -vel.y;
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
                    vel.x = -vel.x;
                }
                break;
            }
            case TIPO::VOADOR:
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
                    vel.y = -vel.y;
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
                    vel.x = -vel.x;
                }
                break;
            }
            case TIPO::CHEFAO:
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
                    vel.y = -vel.y;
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
                    vel.x = -vel.x;
                }
                break;
            }
            
            default:
                break;
            }
        }

        void Voador::setEndiabrado(const bool endb)
        {
            endiabrado = endb;
        }

        const bool Voador::getEndiabrado() const
        {
            return endiabrado;
        }

        float Voador::getPontuacao()
        {
            if(endiabrado)
            {
                return 2 * PONTUACAO_VOADOR;
            }
            return PONTUACAO_VOADOR;
        }
    }
}