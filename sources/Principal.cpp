#include "../include/Principal.hpp"

using namespace Gerenciadores;

Principal::Principal():
pGraf(GerenciadorGrafico::getInstancia()),
pEventos(GerenciadorEventos::getInstancia()),
pEstados(GerenciadorEstados::getInstancia())
{
    pGraf->getJanela()->setFramerateLimit(60);
    pEstados->adicionar(Estados::EstadoID::MenuPrincipal);
    executar();
}

Principal::~Principal()
{
    pGraf = NULL;
}

void Principal::executar()
{
    while(pGraf->estaAberta())
    {
        pGraf->limpar();

        pEventos->verificarEventos();

        pEstados->executar();

        pGraf->mostrar();
    }
}