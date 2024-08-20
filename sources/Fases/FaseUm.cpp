#include "../../include/Fases/FaseUm.hpp"
#include "FaseUm.hpp"

Fases::FaseUm::FaseUm():
Fase()
{
    pGraf->getJanela()->setFramerateLimit(60);
    inicializar();
    executar();
}

Fases::FaseUm::~FaseUm()
{
}

void Fases::FaseUm::inicializar()
{
    inicializarInimigos();
    inicializarJogadores();
    inicializarObstaculos();
}

void Fases::FaseUm::inicializarJogadores()
{
}

void Fases::FaseUm::inicializarInimigos()
{
    
}

void Fases::FaseUm::inicializarObstaculos()
{
}

void Fases::FaseUm::atualizar(float dt)
{
    listaInimigos->atualizar(dt);
    listaJogadores->atualizar(dt);
    listaObstaculos->atualizar(dt);
}

void Fases::FaseUm::desenhar()
{

}

void Fases::FaseUm::executar()
{
}
