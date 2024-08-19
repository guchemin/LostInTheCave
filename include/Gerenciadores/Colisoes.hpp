#pragma once

#include "../Listas/ListaEntidades.hpp"
#include "../Entidades/Personagem/Inimigo/Inimigo.hpp"
#include "../Entidades/Personagem/Jogador/Jogador.hpp"

using namespace Listas;

namespace Gerenciadores
{
    class Colisoes
    {
    private:
        Listas::ListaEntidades* listaJogadores;
        Listas::ListaEntidades* listaInimigos;
        Listas::ListaEntidades* listaObstaculos;

    public:
        Colisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li, Listas::ListaEntidades* lp);
        Colisoes();
        ~Colisoes();

        void verificarColisoes();
    };
};