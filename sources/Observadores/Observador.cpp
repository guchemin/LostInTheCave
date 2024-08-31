#include "../../include/Observadores/Observador.hpp"

namespace Observadores
{
    Observador::Observador():
        pInp(Gerenciadores::GerenciadorInputs::getInstancia()),
        pEstados(Gerenciadores::GerenciadorEstados::getInstancia()),
        teclado(),
        tecladoEspecial()
    {
        pInp->adicionarObservador(this);
        inicializaTeclado();
    }

    Observador::~Observador()
    {
        pInp->removerObservador(this);
    }

    void Observador::inicializaTeclado()
    {
        teclado[sf::Keyboard::A] = "a";
        teclado[sf::Keyboard::B] = "b";
        teclado[sf::Keyboard::C] = "c"; 
        teclado[sf::Keyboard::D] = "d";
        teclado[sf::Keyboard::E] = "e";
        teclado[sf::Keyboard::F] = "f";
        teclado[sf::Keyboard::G] = 'g';
        teclado[sf::Keyboard::H] = "h";
        teclado[sf::Keyboard::I] = "i";
        teclado[sf::Keyboard::J] = "j";
        teclado[sf::Keyboard::K] = "k";
        teclado[sf::Keyboard::L] = "l";
        teclado[sf::Keyboard::M] = "m";
        teclado[sf::Keyboard::N] = "n";
        teclado[sf::Keyboard::O] = "o";
        teclado[sf::Keyboard::P] = "p";
        teclado[sf::Keyboard::Q] = "q";
        teclado[sf::Keyboard::R] = "r";
        teclado[sf::Keyboard::S] = "s";
        teclado[sf::Keyboard::T] = "t";
        teclado[sf::Keyboard::U] = "u";
        teclado[sf::Keyboard::V] = "v";
        teclado[sf::Keyboard::W] = "w";
        teclado[sf::Keyboard::X] = "x";
        teclado[sf::Keyboard::Y] = "y";
        teclado[sf::Keyboard::Z] = "z";
        
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::BackSpace, "BackSpace"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Space, "Space"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Return, "Enter"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Up, "Cima"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Down, "Baixo"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Left, "Esquerda"));
        tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Right, "Direita"));
    }
}