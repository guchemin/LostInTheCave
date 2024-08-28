#pragma once

#include "Menu.hpp"
#include "../Observadores/ObsMenu.hpp"
#include "../Fases/FaseUm.hpp"

namespace Estados
{
    namespace Menu
    {
        class MenuJogar : public Menu
        {
        private: 
            sf::Texture cenario;
            sf::Texture umJog;
            sf::Texture doisJog;
            
        public:
            MenuJogar(Estados::EstadoID faseID);
            ~MenuJogar();

            void mudarBackground(TipoBotao tipo);
            void criarBotoes();
            void selecionar(TipoBotao tipo);
            void executar();
        };

    }
}