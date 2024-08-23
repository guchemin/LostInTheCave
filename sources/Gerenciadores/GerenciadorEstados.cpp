#include "../../include/Gerenciadores/GerenciadorEstados.hpp"
#include "../../include/Fases/FaseUm.hpp"

using namespace Gerenciadores;

// padrao Singleton
GerenciadorEstados* GerenciadorEstados::instancia = NULL;

GerenciadorEstados *GerenciadorEstados::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new GerenciadorEstados();
    }
    return instancia;
}

GerenciadorEstados::GerenciadorEstados():
estados()
{
}

GerenciadorEstados::~GerenciadorEstados()
{
    while(!estados.empty())
    {
        delete(estados.top());
        estados.top() = NULL;
        estados.pop();
    }
}

void GerenciadorEstados::executar()
{
    if(estados.empty()){
        return;
    }
    estados.top()->executar();
}

void GerenciadorEstados::adicionar(Estados::EstadoID estadoID)
{
    switch(estadoID)
    {
    case Estados::EstadoID::FaseUm:
    {
        Fases::FaseUm* fase = new Fases::FaseUm();
        Estados::Estado* est = static_cast<Estados::Estado*>(fase);
        estados.push(est);
        break;
    }
    
    default:
        break;
    }
}

void GerenciadorEstados::remover()
{
    if(estados.top())
    {
        delete(estados.top());
        estados.top() = NULL;
        estados.pop();
    }
    if(estados.empty())
    {
        GerenciadorGrafico* pGraf = GerenciadorGrafico::getInstancia();
        pGraf->fecharJanela();
    }
}

Estados::Estado *GerenciadorEstados::getEstadoAtual()
{
    return estados.top();
}