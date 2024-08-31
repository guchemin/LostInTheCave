/*
Estado.hpp
----------------------------------------------------
 * Classe responsável por gerenciar os estados do jogo.
 * Padrao de projeto State.
*/

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
        FaseDois,
        MenuPrincipal,
        MenuJogarUm,
        MenuJogarDois,
        MenuPausa,
        MenuColocacao,
        MenuFim,
        MenuSalvarPontuacao,
    };

    class Estado
    {
    protected:
        EstadoID estadoID;
        Gerenciadores::GerenciadorEstados* pEstados;
        bool remover;

    protected:
        void adicionar(EstadoID estadoID);

    public:
        Estado(EstadoID id);
        Estado();
        virtual ~Estado();

        EstadoID getEstadoID();

        void setRemover(const bool rmv);
        virtual void executar() = 0;
        virtual void desenhar();
    };
    
}