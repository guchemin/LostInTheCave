#include "../../include/Listas/ListaEntidades.hpp"

using namespace Gerenciadores;
using namespace Listas;

ListaEntidades::ListaEntidades():
lista()
{
    limpar();
}

ListaEntidades::~ListaEntidades()
{
    limpar();
}

void ListaEntidades::adicionar(Entidades::Entidade *entidade)
{
    lista.adicionar(entidade);
}

void ListaEntidades::remover(Entidades::Entidade *entidade)
{
    lista.remover(entidade);
}

int Listas::ListaEntidades::getTam()
{
    return lista.getTam();
}

void Listas::ListaEntidades::limpar()
{
    lista.limparLista();
}

void Listas::ListaEntidades::atualizar(const float dt)
{
    int tam = lista.getTam();
    Entidades::Entidade* ent = NULL;
    for(int i = 0; i < tam; i++)
    {
        ent = lista[i];
        if(ent)
        {
            ent->atualizar(dt);
            if(ent->getTipo() == TIPO::JOGADOR || ent->getTipo() == TIPO::INIMIGO)
            {
                Personagem* pPer = static_cast<Personagem*>(ent);
                if(pPer->getVida() <= 0 || pPer->getPosicao().y > 900.0f)
                {
                    lista.remover(ent);
                    if(tam > 0)
                    {
                        tam--;
                        i--;
                    }
                }
            }
        }
        ent = NULL;
    }
}

void ListaEntidades::desenhar()
{
    int tam = lista.getTam();
    Entidades::Entidade* ent = NULL;
    for(int i = 0; i < tam; i++)
    {
        ent = lista[i];
        if(ent)
        {
            ent->desenhar();
        }
        ent = NULL;
    }
}

Entidades::Entidade* Listas::ListaEntidades::operator[](int pos)
{
    return lista[pos];
}