/*
GerenciadorGrafico.hpp
----------------------------------------------------
 * Classe que gerencia a janela e a renderização de objetos gráficos.
 * Padrão de projeto Singleton.
*/

#pragma once

#include "../../SFML/Graphics.hpp"

namespace Gerenciadores
{
    class GerenciadorGrafico
    {
    private:
        sf::RenderWindow* janela;
        sf::View camera;
        
        static GerenciadorGrafico* instancia;
        GerenciadorGrafico();
        
    public:
        ~GerenciadorGrafico();

        static GerenciadorGrafico* getInstancia();
        sf::RenderWindow* getJanela();
        void centralizarCamera(sf::Vector2f pos);
        sf::Texture carregarTextura(const char* caminho);
        const sf::Vector2f getCentro() const;
        const sf::Vector2f getTamanho() const;
        void limpar();
        void desenhar(sf::RectangleShape desenho);
        void desenhar(sf::CircleShape desenho);
        void desenhar(sf::Text texto);
        void mostrar();
        void fecharJanela();
        void verificaSeFechou();
        bool estaAberta();
    };
};