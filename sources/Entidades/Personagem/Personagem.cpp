#include "../../../include/Entidades/Personagem/Personagem.hpp"

#include <SFML/Graphics.hpp>

namespace Entidades
{
    namespace Personagem
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
            Entidade(pos, tam, tp),
            animacao(&corpo),
            atacando(false),
            iniciouAtaque(false),
            estaNoChao(false),
            direcao(true),
            tomouDano(false),
            tempoAnimacaoAtaque(0.0f),
            tempoTomouDano(0.0f),
            tempoAtaque(0.0f),
            vel(0.0f, 0.0f)
        {
        }

        Personagem::Personagem()
        {
        }

        Personagem::~Personagem()
        {
        }

        nlohmann::json Personagem::salvarJogo() // salva apenas o que é exclusivamente da classe e chama o salvarJogo da classe mãe
        {
            nlohmann::json j = Entidade::salvarJogo();
            j["vel"] = {vel.x, vel.y};
            j["direcao"] = direcao;
            j["vida"] = vida;
            return j;
        }

        void Personagem::setDirecao(const bool dir) // true = direita, false = esquerda
        {
            direcao = dir;
        }

        void Personagem::setVida(const float vd)
        {
            vida = vd;
        }

        void Personagem::setVelocidade(const sf::Vector2f v)
        {
            vel = v;
        }

        void Personagem::setAtacando(const bool atk)
        {
            if(atk)
            {
                iniciouAtaque = true;
            }
            atacando = atk;
        }

        const float Personagem::getVida() const
        {
            return vida;
        }

        void Personagem::operator-=(const float dano)
        {
            tomouDano = true;
            vida -= dano;
        }

        const float Personagem::getRaioAtaque() const
        {
            return raioAtaque;
        }

        const float Personagem::getDano() const
        {
            return dano;
        }
    }
}
