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
        FaseUm,
        MenuPrincipal,
        MenuJogar
    };

    class Estado
    {
    protected:
        EstadoID estadoID;
        Gerenciadores::GerenciadorEstados* pEstados;

    public:
        Estado(EstadoID id);
        Estado();
        virtual ~Estado();

        EstadoID getEstadoID();

        void adicionar(EstadoID estadoID);
        virtual void setDoisJogadores(const bool doisJog){}; // usada apenas para a fase
        virtual void executar() = 0;
        virtual void desenhar();
    };
    
}