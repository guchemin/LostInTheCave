#include "../../include/Observadores/ObsJogadores.hpp"
#include "../../include/Entidades/Personagem/Jogador/Jogador.hpp"

using namespace Observadores;

Observadores::ObsJogadores::ObsJogadores(Jogador::Jogador* pJ):
Observador(),
pJog(pJ)
{
    if(pJog->getId() == Jogador::ID::JOGADOR1)
    {
        direita = sf::Keyboard::Key::D;
        esquerda = sf::Keyboard::Key::A;
        pulo = sf::Keyboard::Key::W;
        ataque = sf::Keyboard::Key::Space;
    }
    else
    {
        direita =  sf::Keyboard::Key::Right;
        esquerda = sf::Keyboard::Key::Left;
        pulo = sf::Keyboard::Key::Up;
        ataque = sf::Keyboard::Key::K;
    }
}

Observadores::ObsJogadores::~ObsJogadores()
{
    pJog = NULL;
}


void Observadores::ObsJogadores::notificarPressionada(sf::Keyboard::Key tecla)
{
    if(pJog == NULL)
    {
        cout << "ERRO = Jogador nulo" << endl;
        return;
    }

    if(tecla == pulo && pJog->podePular())
    {
        pJog->autorizarPulo(false);
        pJog->pular();
    }
    if(tecla == direita)
    {
        pJog->andar(DIREITA);
    }
    else if(tecla == esquerda)
    {
        pJog->andar(ESQUERDA);
    }
    
    if(tecla == ataque)
    {
        pJog->atacar();
    }
}

void Observadores::ObsJogadores::notificarSolta(sf::Keyboard::Key tecla)
{
    if(pJog == NULL)
    {
        cout << "ERRO = JOGADOR NULO" << endl;
        return;
    }

    if(tecla == pulo)
    {
        pJog->autorizarPulo(true);
    }
}