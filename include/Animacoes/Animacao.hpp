/*
Animacao.hpp
----------------------------------------------------
 * Animações retiradas de: https://craftpix.net
 * Classe criada para facilitar a manipulação de animações de personagens
 * Inspirado em: https://github.com/Giovanenero/JogoPlataforma2D-Jungle
*/

#pragma once

#include "Imagem.hpp"
#include <iostream>
#include <map>
using namespace std;

namespace Animacoes
{
    class Animacao
    {
    private:
        sf::RectangleShape* corpo;
        map<string, Imagem*> imagens;
        sf::Clock relogio;
        string imagemAtual;
    
    private:
        void setImgAtual(const string imgAtual);

    public:
        Animacao(sf::RectangleShape* crp);
        Animacao();
        ~Animacao();

        const string getImagemAtual() const;
        const int getQuadroAtual();
        void setQuadroAtual(const unsigned int imgAtual);
        const bool getTerminouAnimacao();
        const float getTempoTotal();
        void setTempoTotal(const float tempoTotal);
        void atualizar(const bool paraDireita, string imgAtual);
        void addAnimacao(const char* caminhoTextura, string nomeAnimacao, const int qtdImagem, const float tempoTroca, const sf::Vector2f escala, const sf::Vector2f origin = sf::Vector2f(0.0f, 0.0f), const bool horizontal = true);
    };
}