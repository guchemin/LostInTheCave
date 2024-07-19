#pragma once

#include <vector>
#include "../Gerenciadores/Graficos.hpp"
#include "../Entidades/Personagem/Personagem.hpp"


namespace Listas
{
    class ListaEntidades
    {
    private:
        Gerenciadores::Graficos* pGraf;
        std::vector<Entidades::Entidades*> lista;

    public:
        ListaEntidades();
        ~ListaEntidades();
        
        void adicionar(Entidades::Entidades* entidade);
        void remover(Entidades::Entidades* entidade);
        void atualizar();
        void limpar();
        void mover(float dt);
        void desenhar(sf::RenderWindow* janela);

        std::vector<Entidades::Entidades*> getLista();
        std::vector<Entidades::Entidades*>::iterator getInicio();
        std::vector<Entidades::Entidades*>::iterator getFim();
    };
};