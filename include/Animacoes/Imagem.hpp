/*
Imagem.hpp
---------------------------------------------------- 
 * Classe criada para facilitar a manipulação de animações de personagens
 * Inspirado em: https://github.com/Giovanenero/JogoPlataforma2D-Jungle
 * Classe responsável pelas imagens de uma animação de um personagem
*/

#pragma once

#include "../../SFML/Graphics.hpp"
#include "../Gerenciadores/GerenciadorGrafico.hpp"

namespace Animacoes
{
    class Imagem
    {
    private:
        Gerenciadores::GerenciadorGrafico* pGraf;
        sf::Texture textura;
        sf::IntRect tamanho;
        const bool horizontal;
        const sf::Vector2f escala;
        const int qtdImagem;
        int imgAtual;
        const float tempoTroca;
        float tempoTotal;
        const sf::Vector2f origem;
        bool terminouAnimacao;

    public:
        Imagem(const char* caminhoTextura, const unsigned int qtd, const float tempo, const sf::Vector2f esc, const sf::Vector2f org, const bool hor);
        ~Imagem();

        void resetar();
        const bool getTerminouAnimacao();
        void setTerminouAnimacao(const bool terminou);
        const int getQuadroAtual() const;
        void setQuadroAtual(const unsigned int img);
        const float getTempoTotal() const;
        void setTempoTotal(const float tempo);
        const sf::IntRect getTamanho() const;
        const sf::Texture* getTextura() const;
        const sf::Vector2f getEscala() const;
        const sf::Vector2f getOrigin() const;
        void atualizar(const bool paraDireita, const float dt);
    };
}