#pragma once

#include "Menu.hpp"
#include "../Observadores/ObsMenu.hpp"
#include "../Fases/FaseUm.hpp"

namespace Menu
{
    class MenuJogar : public Menu
    {
    private: 
        
    public:
        MenuJogar();
        ~MenuJogar();

        void criarBotoes();
        void selecionar(TipoBotao tipo);
    };

}