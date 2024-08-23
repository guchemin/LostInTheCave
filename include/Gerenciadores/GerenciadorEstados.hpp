#pragma once

#include <stack>
#include "../Estados/Estado.hpp"

using namespace std;

namespace Gerenciadores
{
    class GerenciadorEstados
    {
    private:
        stack<Estados::Estado*> estados;

        // padrão de projeto Singleton
        static GerenciadorEstados* instancia;
        GerenciadorEstados();

    public:
        ~GerenciadorEstados();
        
        static GerenciadorEstados* getInstancia();
        void executar();
        void adicionar(Estados::EstadoID estadoID);
        void remover();
        Estados::Estado* getEstadoAtual();
    };
}