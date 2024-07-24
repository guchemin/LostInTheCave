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

void Listas::ListaEntidades::limpar()
{
    std::vector<Entidades::Entidades*>::iterator it;
    for(it = lista.begin(); it != lista.end(); ++it)
    {
        delete (*it);
    }
    lista.clear();
}

void Listas::ListaEntidades::atualizar(float dt)
{
    std::vector<Entidades::Entidades*>::iterator it;
    for(it = lista.begin();!lista.empty() && it != lista.end(); ++it)
    {
        Personagem* p = dynamic_cast<Personagem*>(*it);
        p->atualizar(dt);
    }
}

// utilizando o padrao iterator para percorrer a lista de entidades
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

std::vector<Entidades::Entidades *>::iterator ListaEntidades::getInicio()
{
    return lista.begin();
}

std::vector<Entidades::Entidades *>::iterator ListaEntidades::getFim()
{
    return lista.end() ;
}
