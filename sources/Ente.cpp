#include "../include/Ente.hpp"

int Ente::contId = 0;

Ente::Ente():
pGraf(Gerenciadores::GerenciadorGrafico::getInstancia()),
id(contId++)
{
    time_t t;
    srand((unsigned) time(&t));
}

Ente::~Ente()
{

}