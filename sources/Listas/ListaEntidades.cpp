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

Listas::Lista<Entidades::Entidade>::Iterador ListaEntidades::remover(Listas::Lista<Entidades::Entidade>::Iterador it)
{
    return lista.remover(it);
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
    Lista<Entidades::Entidade>::Iterador it = lista.inicio();
    while(it != lista.fim())
    {
        Entidades::Entidade* ent = *it;
        if (ent)
        {
            ent->atualizar(dt);
            if (ent->getTipo() == TIPO::JOGADOR || ent->getTipo() == TIPO::INIMIGO)
            {
                Personagem* pPer = static_cast<Personagem*>(ent);
                if (pPer->getVida() <= 0 || pPer->getPosicao().y > 900.0f)
                {
                    it = lista.remover(it);  // Use o iterador retornado para continuar a iteração corretamente
                }
                else
                {
                    ++it;
                }
            }
            else
            {
                ++it;
            }
        }
        else
        {
            ++it;
        }
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