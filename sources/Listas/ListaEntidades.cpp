#include "../../include/Listas/ListaEntidades.hpp"
#include "../../include/Entidades/Personagem/Inimigo.hpp"

namespace Listas
{
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

    void Listas::ListaEntidades::executar(const float dt)
    {
        int tam = lista.getTam();
        Entidades::Entidade* ent = NULL;
        Lista<Entidades::Entidade>::Iterador it = lista.inicio();
        while(it != lista.fim())
        {
            Entidades::Entidade* ent = *it;
            if (ent)
            {
                ent->executar(dt);
                if (ent->getTipo() == Entidades::TIPO::JOGADOR || ent->getTipo() == Entidades::TIPO::INIMIGO)
                {
                    Entidades::Personagem::Personagem* pPer = static_cast<Entidades::Personagem::Personagem*>(ent);
                    if (pPer->getVida() <= 0 || pPer->getPosicao().y > 900.0f)
                    {
                        it = lista.remover(it); 
                        if(pPer->getTipo() == TIPO::INIMIGO)
                        {
                            Entidades::Personagem::Inimigo* inimigo = static_cast<Entidades::Personagem::Inimigo*>(pPer);
                            Entidades::Personagem::Jogador::somaPontos(inimigo->getPontuacao());
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
}