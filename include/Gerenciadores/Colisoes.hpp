#pragma once

#include "../Listas/ListaEntidades.hpp"

using namespace Listas;

namespace Gerenciadores
{
    class Colisoes
    {
    private:
        Listas::ListaEntidades* listaJogadores;
        Listas::ListaEntidades* listaInimigos;
        Listas::ListaEntidades* listaPlataformas;

    public:
        Colisoes(Listas::ListaEntidades* lJogadores, Listas::ListaEntidades* lInimigos, Listas::ListaEntidades* lPlataformas);
        Colisoes();
        ~Colisoes();

        void verificarColisoes();
    };
};