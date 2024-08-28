#include "../../../include/Entidades/Obstaculos/Espinho.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(sf::Vector2f pos):
        Obstaculo(pos, sf::Vector2f(100.0f, 50.0f), TIPO::ESPINHO),
        afiado(float(rand() % 101 + 50) / 10.0f)
        {
            textura.loadFromFile(CAMINHO_TEXTURA_ESPINHO);
            corpo.setTexture(&textura);
            corpo.setScale(1.2f, 1.2f);
            corpo.setOrigin(10.0f, 8.0f);
        }

        Espinho::Espinho():
        afiado(10.0f)
        {
        }

        Espinho::~Espinho()
        {
        }

        nlohmann::json Espinho::salvarJogo()
        {
            nlohmann::json j = Obstaculo::salvarJogo();
            j["afiado"] = afiado;
            return j;
        }

        void Espinho::setAfiado(float afd)
        {
            afiado = afd;
        }

        const float Espinho::getAfiado() const
        {
            return afiado;
        }
    }
}