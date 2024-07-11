#include "../../include/Listas/ListaEntidades.hpp"

using namespace Gerenciadores;
using namespace Listas;

ListaEntidades::ListaEntidades():
pGraf(Graficos::getInstancia())
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::adicionar(Entidades::Entidades *entidade)
{
    lista.push_back(entidade);
}

void ListaEntidades::remover(Entidades::Entidades *entidade)
{
    lista.erase(std::remove(lista.begin(), lista.end(), entidade), lista.end());
}

void ListaEntidades::atualizar()
{
}

//utilizando o padrao iterator para percorrer a lista de entidades
void ListaEntidades::desenhar(sf::RenderWindow *janela)
{
    std::vector<Entidades::Entidades*>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it)
    {
        pGraf->desenhar((*it)->getCorpo());
    }
}

std::vector<Entidades::Entidades*> ListaEntidades::getLista()
{
    return lista;
}
