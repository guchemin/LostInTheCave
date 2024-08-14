#pragma once

#include "Graficos.hpp"
#include "Inputs.hpp"
#include "../Entidades/Personagem/Jogador/Jogador.hpp"

namespace Gerenciadores
{
    class Eventos
    {
    private:
        Graficos* pGraf;
        Inputs* pInp;
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
        void verificaSeParou();
        void verificarEventos();
    };
};