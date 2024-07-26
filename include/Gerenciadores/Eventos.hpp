#pragma once

#include "Graficos.hpp"
#include "../Entidades/Personagem/Jogador/Jogador.hpp"

#define DIREITA 1
#define ESQUERDA 0

namespace Gerenciadores
{
    class Eventos
    {
    private:
        Graficos* pGraf;
        Jogador::Jogador* pJog1;
        Jogador::Jogador* pJog2;
        sf::Event evento;

        //padrao de projeto Singleton
        static Eventos* instancia;
        Eventos();

    public:
        ~Eventos();
    
        static Eventos* getInstancia();
        void setJogador(Jogador::Jogador* pJog);
        void verificarTeclaPessionada(sf::Keyboard::Key tecla);    
        void verificarTeclaSolta(sf::Keyboard::Key tecla);
        void verificaSeParou();
        void verificarEventos();
    };
};