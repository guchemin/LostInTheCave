#include "../../include/Observadores/ObsJogadores.hpp"
#include "../../include/Entidades/Personagem/Jogador.hpp"

namespace Observadores
{
    ObsJogadores::ObsJogadores(Entidades::Personagem::Jogador* pJ):
    Observador(),
    pJog(pJ)
    {
        if(pJog->getId() == Entidades::Personagem::ID::JOGADOR1)
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
        pausa = sf::Keyboard::Key::P;
    }

    ObsJogadores::ObsJogadores():
    Observador()
    {
    }

    ObsJogadores::~ObsJogadores()
    {
        pJog = NULL;
    }


    void ObsJogadores::notificarPressionada(const sf::Keyboard::Key tecla)
    {
        if(!(pEstados->getEstadoAtual()->getEstadoID() == Estados::EstadoID::FaseUm || 
             pEstados->getEstadoAtual()->getEstadoID() == Estados::EstadoID::FaseDois))
        {
            return;
        }

        if(tecla == pausa)
        {
            pEstados->adicionar(Estados::EstadoID::MenuPausa);
        }

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
        else if(tecla == ataque)
        {
            pJog->setAtacando(true);
        }
    }

    void ObsJogadores::notificarSolta(const sf::Keyboard::Key tecla)
    {
        if(!(pEstados->getEstadoAtual()->getEstadoID() == Estados::EstadoID::FaseUm || 
             pEstados->getEstadoAtual()->getEstadoID() == Estados::EstadoID::FaseDois))
        {
            return;
        }
        
        if(pJog == NULL)
        {
            cout << "ERRO = JOGADOR NULO" << endl;
            return;
        }

        if(tecla == pulo)
        {
            pJog->autorizarPulo(true);
        }
        if(tecla == ataque)
        {
            pJog->parouDeAtacar();
        }
        if(!(sf::Keyboard::isKeyPressed(direita) || sf::Keyboard::isKeyPressed(esquerda)))
        {
            pJog->parar();
        }
    }
}