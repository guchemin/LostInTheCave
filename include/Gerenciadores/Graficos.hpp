#pragma once

#include "../../SFML/Graphics.hpp"

namespace Gerenciadores
{
    class Graficos
    {
    private:
        sf::RenderWindow* janela;
        
        //padrao de projeto Singleton
        static Graficos* instancia;
        Graficos();
        
    public:
        ~Graficos();

        static Graficos* getInstancia();
        sf::RenderWindow* getJanela();
        void limpar();
        void desenhar(sf::RectangleShape desenho);
        void desenhar(sf::CircleShape desenho);
        void mostrar();
        void fecharJanela();
        void verificaSeFechou();
        bool estaAberta();
    };
};