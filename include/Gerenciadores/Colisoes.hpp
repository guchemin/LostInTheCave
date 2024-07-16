#pragma once

#include "../Listas/ListaEntidades.hpp"

using namespace Listas;

namespace Gerenciadores
{
    class Colisoes
    {
    private:
        Listas::ListaEntidades* listaPersonagem;
        Listas::ListaEntidades* listaPlataforma;

    public:
        Colisoes(Listas::ListaEntidades* lPersonagem, Listas::ListaEntidades* lPlataforma);
        Colisoes();
        ~Colisoes();

        void verificarColisoes();
    };
};