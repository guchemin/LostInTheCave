#include "../../../include/Entidades/Obstaculos/Obstaculo.hpp"
#include "../../../include/Entidades/Obstaculos/Pedra.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
        Entidade(pos, tam, tp)
        {
            velY = 0.0f;
            if(tp == TIPO::ESPINHO)
            {
                danoso = true;
            }
            else
            {
                danoso = false;
            }
        }

        Obstaculo::Obstaculo()
        {
        }

        Obstaculo::~Obstaculo()
        {
        }

        nlohmann::json Obstaculo::salvarJogo()
        {
            nlohmann::json j = Entidade::salvarJogo();
            j["danoso"] = danoso;
            j["velY"] = velY;
            return j;
        }

        bool Obstaculo::getDanoso()
        {
            return danoso;
        }

        void Obstaculo::colide(Entidade *ent, const sf::Vector2f intersec)
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
                    }
                    velY = 0.0f;
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

            case TIPO::ESPINHO:
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
            
            case TIPO::TEIA:
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
            
            case TIPO::PEDRA:
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

        void Obstaculo::executar(const float dt)
        {
            velY += GRAVIDADE * dt;
            corpo.move(0.0f, velY * dt);
        }
    }
}