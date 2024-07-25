#pragma once

#include "Graficos.hpp"
#include "../Entidades/Personagem/Jogador/Jogador.hpp"

namespace Gerenciadores
{
    class Eventos
    {
    private:
        Graficos* pGraf;
        Jogador::Jogador* pJog1;
        Jogador::Jogador* pJog2;
        float dt;

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
        void verificarEventos(float t);
    };
};