#include "../../../include/Entidades/Personagem/Inimigo.hpp"

namespace Entidades
{
    namespace Personagem
    {

        Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
            Personagem(pos, tam, tp),
            posInicial(pos),
            pJogador(NULL)
        {
        }

        Inimigo::Inimigo()
        {
            pJogador = NULL;
        }

        Inimigo::~Inimigo()
        {
            pJogador = NULL;
        }

        nlohmann::json Inimigo::salvarJogo() // salva apenas o que é exclusivamente da classe e chama o salvarJogo da classe mãe
        {
            nlohmann::json j = Personagem::salvarJogo();
            j["posInicial"] = {posInicial.x, posInicial.y};
            return j;
        }
        
        void Inimigo::setJogador(Jogador *jog)
        {
            if(jog)
            {        
                pJogador = jog;
            }
        }

        void Inimigo::setPosInicial(const sf::Vector2f pos)
        {
            posInicial = pos;
        }

        sf::Vector2f Inimigo::getPosJogador()
        {
            return pJogador->getPosicao();
        }
    }
}