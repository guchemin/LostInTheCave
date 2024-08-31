/*
Texto.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../Gerenciadores/GerenciadorGrafico.hpp"

#define CAMINHO_FONTE "../assets/fonts/fonteJogo.ttf"
#define TAMANHO_CARACTER 24

using namespace std;

class Texto
{
private:
    sf::Text texto;
    sf::Font fonte;
    Gerenciadores::GerenciadorGrafico* pGraf;

public: 
    Texto(const char* caminhoFonte = CAMINHO_FONTE);
    ~Texto();

    void operator=(string informacao);
    void setPos(sf::Vector2f pos);
    void setCor(sf::Color cor);
    void setTamanhoFonte(int tam);
    string getInfo();
    const sf::Vector2f getTamanho() const;
    const sf::Vector2f getPos() const;
    void desenhar();
};