#pragma once

#include <vector>
#include "Lista.hpp"
#include "../Entidades/Entidade.hpp"
#include "../Gerenciadores/GerenciadorEstados.hpp"

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> lista;
        Gerenciadores::GerenciadorEstados* pEstados;

    public:
        class IteradorEntidades 
        {
        public:
            Lista<Entidades::Entidade>::Iterador iterador;

        public:
            IteradorEntidades(Lista<Entidades::Entidade>::Iterador it) : iterador(it) {}

            IteradorEntidades& operator++() 
            {
                ++iterador;
                return *this;
            }

            bool operator!=(const IteradorEntidades& outro) const 
            {
                return iterador != outro.iterador;
            }

            Entidades::Entidade* operator*() const 
            {
                return *iterador;
            }

            IteradorEntidades getProx() const 
            {
                return IteradorEntidades(iterador.getProx());
            }

            friend class ListaEntidades;
        };

        ListaEntidades();
        ~ListaEntidades();
        
        void adicionar(Entidades::Entidade* entidade);
        IteradorEntidades remover(IteradorEntidades it);
        int getTam();
        void limpar();
        Entidades::Entidade* operator[](int pos);  
        void executar(const float dt);
        void desenhar();

        IteradorEntidades inicio() { return IteradorEntidades(lista.inicio()); }
        IteradorEntidades fim() { return IteradorEntidades(lista.fim()); }
    };
}




// #pragma once

// #include <vector>
// #include "Lista.hpp"
// #include "../Entidades/Entidade.hpp"

// namespace Listas
// {
//     class ListaEntidades
//     {
//     private:
//         Lista<Entidades::Entidade> lista;
//         Lista<Entidades::Entidade>::Iterador it;

//     public:
//         ListaEntidades();
//         ~ListaEntidades();
        
//         void adicionar(Entidades::Entidade* entidade);
//         Lista<Entidades::Entidade>::Iterador remover(Lista<Entidades::Entidade>::Iterador it);
//         int getTam();
//         void limpar();
//         Entidades::Entidade* operator[](int pos);  
//         void executar(const float dt);
//         void desenhar();


//         Lista<Entidades::Entidade>::Iterador inicio() { return lista.inicio(); }
//         Lista<Entidades::Entidade>::Iterador fim() { return lista.fim(); }
//     };
// };