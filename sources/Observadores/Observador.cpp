#include "../../include/Observadores/Observador.hpp"

Observadores::Observador::Observador():
pInp(GerenciadorInputs::getInstancia()),
pEstados(GerenciadorEstados::getInstancia())
{
    pInp->adicionarObservador(this);
}

Observadores::Observador::~Observador()
{
    pInp->removerObservador(this);
}