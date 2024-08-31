#include "../../../include/Entidades/Obstaculos/Teia.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Teia::Teia(sf::Vector2f pos):
            Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::TEIA),
            densidade(float(rand() % 11 + 25) / 10.0f)
        {
            textura = pGraf->carregarTextura(CAMINHO_TEXTURA_TEIA);
            corpo.setTexture(&textura);
        }

        Teia::Teia():
        densidade(3.0f)
        {
        }

        Teia::~Teia()
        {
        }

        nlohmann::json Teia::salvarJogo() // salva apenas o que é exclusivamente da classe e chama o salvarJogo da classe mãe
        {
            nlohmann::json j = Obstaculo::salvarJogo();
            j["densidade"] = densidade;
            return j;
        }

        void Teia::setDensidade(float den)
        {
            densidade = den;
        }

        const float Teia::getDensidade() const
        {
            return densidade;
        }

        void Teia::colide(Entidade *ent, const sf::Vector2f intersec)
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
            
            default:
                break;
            }
        }
    }
}