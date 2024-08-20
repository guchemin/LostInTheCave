#include "../../include/Fases/Fase.hpp"

Fases::Fase::Fase():
Ente(),
pEventos(GerenciadorEventos::getInstancia())
{
}

Fases::Fase::~Fase()
{
}