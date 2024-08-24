#include "../../include/Estados/Estado.hpp"
#include "../../include/Gerenciadores/GerenciadorEstados.hpp"

Estados::Estado::Estado(Estados::EstadoID id):
estadoID(id),
pEstados(Gerenciadores::GerenciadorEstados::getInstancia())
{
}

Estados::Estado::Estado()
{

}

Estados::Estado::~Estado()
{

}

Estados::EstadoID Estados::Estado::getEstadoID()
{
    return estadoID;
}

void Estados::Estado::adicionar(EstadoID estadoID)
{
    pEstados->adicionar(estadoID);
}

void Estados::Estado::desenhar()
{
}