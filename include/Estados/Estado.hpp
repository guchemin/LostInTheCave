#pragma once

#include "../Ente.hpp"

namespace Gerenciadores
{
    class GerenciadorEstados;
}

namespace Estados
{
    enum EstadoID
    {
        FaseUm
    };

    class Estado
    {
    private:
        EstadoID estadoID;
        Gerenciadores::GerenciadorEstados* pEstados;

    public:
        Estado(EstadoID id);
        Estado();
        virtual ~Estado();

        EstadoID getEstadoID();

        void adicionar(EstadoID estadoID);
        virtual void executar() = 0;
        virtual void desenhar();
    };
    
}