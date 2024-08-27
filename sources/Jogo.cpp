#include "../include/Jogo.hpp"

using namespace Gerenciadores;

Jogo::Jogo():
pGraf(GerenciadorGrafico::getInstancia()),
pEventos(GerenciadorEventos::getInstancia()),
pEstados(GerenciadorEstados::getInstancia())
{
    pGraf->getJanela()->setFramerateLimit(60);
    pEstados->adicionar(Estados::EstadoID::MenuPrincipal);
    executar();
}

Jogo::~Jogo()
{
    pGraf = NULL;
}

void Jogo::executar()
{
    while(pGraf->estaAberta())
    {
        pGraf->limpar();
        pEventos->verificarEventos();
        pEstados->executar();
        pGraf->mostrar();
    }
}