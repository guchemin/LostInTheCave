#include "../../../include/Entidades/Obstaculos/Pedra.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Pedra::Pedra(sf::Vector2f pos):
        Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::PEDRA),
        peso(float(rand() % 6 + 15) / 10.0f)
        {
            dx = 300.0f / peso / 60.0f;
            textura.loadFromFile(CAMINHO_TEXTURA_PEDRA);
            corpo.setTexture(&textura);
            corpo.setScale(1.2f, 1.0f);
            corpo.setOrigin(5.0f, 0.0f);
        }

        Pedra::Pedra():
        Obstaculo(),
        peso(10.0f)
        {
        }

        Pedra::~Pedra()
        {
        }

        nlohmann::json Pedra::salvarJogo()
        {
            nlohmann::json j = Obstaculo::salvarJogo();
            j["peso"] = peso;
            j["dx"] = dx;
            return j;
        }

        void Pedra::setDx(const float x)
        {
            dx = x;
        }

        void Pedra::setPeso(const float p)
        {
            peso = p;
        }

        const float Pedra::getPeso() const
        {
            return peso;
        }

        void Pedra::arrastar(const bool direita)
        {
            if(direita)
                corpo.move(dx, 0.0f);
            else
                corpo.move(-dx, 0.0f);
        }

        void Pedra::colide(Entidade *ent, const sf::Vector2f intersec)
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

            case TIPO::PEDRA:
            {
                if(getPosicao().x > ent->getPosicao().x)
                {
                    arrastar(true);
                }
                else
                {
                    arrastar(false);
                }
                break;
            }
            
            default:
                break;
            }
            
        }
    }
}