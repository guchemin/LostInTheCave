/*
MenuJogar.hpp - Filha da classe Menu
*/

#pragma once

#include "Menu.hpp"
#include "../Observadores/ObsMenu.hpp"
#include "../Fases/FaseUm.hpp"

#define CAMINHO_TEXT_JOG1 "../assets/sprites/MenuJogar/jogador1_menu_jogar.png"
#define CAMINHO_TEXT_JOG2 "../assets/sprites/MenuJogar/jogador2_menu_jogar.png"

namespace Estados
{
    namespace Menu
    {
        class MenuJogar : public Menu
        {
        private:
            sf::RectangleShape jog1;
            sf::RectangleShape jog2;
            sf::Texture cenario;
            sf::Texture textJog1;
            sf::Texture textJog2;

        private:
            void desenharJogadores();
            void criarBotoes();
            
        public:
            MenuJogar(Estados::EstadoID faseID);
            MenuJogar();
            ~MenuJogar();

            void selecionar(TipoBotao tipo);
            void executar();
        };

    }
}