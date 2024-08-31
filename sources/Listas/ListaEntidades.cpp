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

    ListaEntidades::IteradorEntidades ListaEntidades::remover(IteradorEntidades it)
    {
        return IteradorEntidades(lista.remover(it.iterador));
    }

    const int ListaEntidades::getTam() const
    {
        return lista.getTam();
    }

    void ListaEntidades::limpar()
    {
        lista.limparLista();
    }

    void ListaEntidades::executar(const float dt) // executa cada entidade e remove as que não estão mais vivas (se forem personagens)
    {
        IteradorEntidades it = inicio();
        while(it != fim())
        {
            Entidades::Entidade* ent = *it;
            if (ent)
            {
                ent->executar(dt);
                if (ent->getTipo() == Entidades::TIPO::JOGADOR || ent->getTipo() == Entidades::TIPO::ATIRADOR ||
                    ent->getTipo() == Entidades::TIPO::CHEFAO || ent->getTipo() == Entidades::TIPO::VOADOR)
                {
                    Entidades::Personagem::Personagem* pPer = static_cast<Entidades::Personagem::Personagem*>(ent);
                    if(pPer->getVida() <= 0 || pPer->getPosicao().y > 900.0f)
                    {
                        it = remover(it); 
                        if(pPer->getTipo() != TIPO::JOGADOR)
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
        IteradorEntidades it = inicio();
        while(it != fim())
        {
            Entidades::Entidade* ent = *it;
            if(ent)
            {
                ent->desenhar();
            }
            ++it;
        }
    }

    Entidades::Entidade* ListaEntidades::operator[](int pos)
    {
        return lista[pos];
    }
}