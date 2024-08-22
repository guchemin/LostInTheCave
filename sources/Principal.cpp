#include "../include/Principal.hpp"

using namespace Gerenciadores;

Principal::Principal():
pGraf(GerenciadorGrafico::getInstancia()),
fase()
{
    pGraf->getJanela()->setFramerateLimit(60);
    fase.inicializar();
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
        fase.executar();
    }
}