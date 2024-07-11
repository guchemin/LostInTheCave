#pragma once

#include "../../SFML/Graphics.hpp"

namespace Gerenciadores
{
    class Graficos
    {
    private:
        sf::RenderWindow* window;
        
        //padrao de projeto Singleton
        static Graficos* instancia;
        Graficos();
        
    public:
        ~Graficos();

        static Graficos* getInstancia();
        sf::RenderWindow* getJanela();
        void limpar();
        void desenhar(sf::RectangleShape desenho);
        void mostrar();
        bool estaAberta();
        void fecharJanela();
        void verificaSeFechou();
    };
};