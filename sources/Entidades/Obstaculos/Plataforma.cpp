#include "../../../include/Entidades/Obstaculos/Plataforma.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam):
            Obstaculo(pos, tam, Entidades::TIPO::PLATAFORMA),
            ehFalsa(!(bool)(rand() % 20 || tam.x == 50.0f)),
            empuxo(GRAVIDADE)
        {
            if(tam.x == 50.0f)
            {
                textura.loadFromFile(CAMINHO_TEXTURA_PAREDE);
                corpo.setTexture(&textura);
                corpo.setScale(1.8f, 1.8f);
                corpo.setOrigin(8.0f, 12.0f);
            }
            else if(tam.x == 100.0f)
            {
                if(!ehFalsa)
                {
                    textura.loadFromFile(CAMINHO_TEXTURA_CHAO);
                    corpo.setTexture(&textura);
                    corpo.setScale(1.1f, 1.5f);
                    corpo.setOrigin(8.0f, 8.0f);
                }
                else
                {
                    textura.loadFromFile(CAMINHO_TEXTURA_FALSO);
                    corpo.setTexture(&textura);
                    corpo.setScale(1.1f, 1.5f);
                    corpo.setOrigin(8.0f, 11.0f);
                }
            }
        }

        Plataforma::Plataforma():
        ehFalsa(false),
        empuxo(GRAVIDADE)
        {
        }

        Plataforma::~Plataforma()
        {
        }

        nlohmann::json Plataforma::salvarJogo() // salva apenas o que é exclusivamente da classe e chama o salvarJogo da classe mãe
        {
            nlohmann::json j = Obstaculo::salvarJogo();
            j["tamanho"] = {corpo.getSize().x, corpo.getSize().y};
            j["ehFalsa"] = ehFalsa;
            return j;
        }

        void Plataforma::setFalsa(const bool falsa)
        {
            ehFalsa = falsa;
            if(getTamanho().x == 50.0f)
            {
                textura.loadFromFile(CAMINHO_TEXTURA_PAREDE);
                corpo.setTexture(&textura);
                corpo.setScale(1.8f, 1.8f);
                corpo.setOrigin(8.0f, 12.0f);
            }
            else if(getTamanho().x == 100.0f)
            {
                if(!ehFalsa)
                {
                    textura.loadFromFile(CAMINHO_TEXTURA_CHAO);
                    corpo.setTexture(&textura);
                    corpo.setScale(1.1f, 1.5f);
                    corpo.setOrigin(8.0f, 8.0f);
                }
                else
                {
                    textura.loadFromFile(CAMINHO_TEXTURA_FALSO);
                    corpo.setTexture(&textura);
                    corpo.setScale(1.1f, 1.5f);
                    corpo.setOrigin(8.0f, 11.0f);
                }
            }
        }

        const bool Plataforma::getFalsa() const
        {
            return ehFalsa;
        }

        void Plataforma::executar(const float dt)
        {
            velY += GRAVIDADE * dt - empuxo * dt;
            corpo.move(sf::Vector2f(0.0f, velY * dt));
        }
    }
}
