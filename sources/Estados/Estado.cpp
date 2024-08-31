#include "../../include/Estados/Estado.hpp"
#include "../../include/Gerenciadores/GerenciadorEstados.hpp"

namespace Estados
{
    Estado::Estado(EstadoID id):
        estadoID(id),
        pEstados(Gerenciadores::GerenciadorEstados::getInstancia())
    {
    }

    Estado::Estado()
    {

    }

    Estado::~Estado()
    {

    }

    EstadoID Estado::getEstadoID()
    {
        return estadoID;
    }

    void Estado::adicionar(EstadoID estadoID)
    {
        pEstados->adicionar(estadoID);
    }

    void Estado::setRemover(const bool rmv)
    {
        remover = rmv;
    }

    void Estado::desenhar()
    {
    }
}