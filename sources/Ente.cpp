#include "../include/Ente.hpp"

int Ente::contId = 0;

Ente::Ente():
pGraf(Gerenciadores::GerenciadorGrafico::getInstancia()),
id(contId++)
{
    srand(Ente::id * (unsigned)time(0)); // usando id apenas para melhorar a semente
}

Ente::~Ente()
{
}

void Ente::executar(const float dt)
{
}