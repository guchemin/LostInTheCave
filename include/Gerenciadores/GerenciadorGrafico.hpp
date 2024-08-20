#pragma once

#include "../../SFML/Graphics.hpp"

namespace Gerenciadores
{
    class GerenciadorGrafico
    {
    private:
        sf::RenderWindow* janela;
        sf::View camera;
        
        //padrao de projeto Singleton
        static GerenciadorGrafico* instancia;
        GerenciadorGrafico();
        
    public:
        ~GerenciadorGrafico();

        static GerenciadorGrafico* getInstancia();
        sf::RenderWindow* getJanela();
        void centralizarCamera(sf::Vector2f pos);
        sf::Vector2f getCentro();
        void limpar();
        void desenhar(sf::RectangleShape desenho);
        void desenhar(sf::CircleShape desenho);
        void mostrar();
        void fecharJanela();
        void verificaSeFechou();
        bool estaAberta();
    };
};