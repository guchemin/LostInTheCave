#pragma once

#include "Graficos.hpp"
#include "../Listas/ListaEntidades.hpp"

namespace Gerenciadores
{
    class Colisoes
    {
    private:
        Listas::ListaEntidades* listaPersonagem;
        Listas::ListaEntidades* listaPlataforma;

    public:
        Colisoes(Listas::ListaEntidades* lPersonagem, Listas::ListaEntidades* lPlataforma);
        ~Colisoes();

        void verificarColisoes();
    };
};