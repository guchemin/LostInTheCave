#include "../../include/Observadores/Observador.hpp"

Observadores::Observador::Observador():
pInp(GerenciadorInputs::getInstancia()),
pEstados(GerenciadorEstados::getInstancia()),
keys(),
tecladoEspecial()
{
    pInp->adicionarObservador(this);
    inicializaTeclado();
}

Observadores::Observador::~Observador()
{
    pInp->removerObservador(this);
}

void Observadores::Observador::inicializaTeclado()
{
        keys [sf::Keyboard::A] = "a";
        keys [sf::Keyboard::B] = "b";
        keys [sf::Keyboard::C] = "c"; 
        keys [sf::Keyboard::D] = "d";
        keys [sf::Keyboard::E] = "e";
        keys [sf::Keyboard::F] = "f";
        keys [sf::Keyboard::G] = 'g';
        keys [sf::Keyboard::H] = "h";
        keys [sf::Keyboard::I] = "i";
        keys [sf::Keyboard::J] = "j";
        keys [sf::Keyboard::K] = "k";
        keys [sf::Keyboard::L] = "l";
        keys [sf::Keyboard::M] = "m";
        keys [sf::Keyboard::N] = "n";
        keys [sf::Keyboard::O] = "o";
        keys [sf::Keyboard::P] = "p";
        keys [sf::Keyboard::Q] = "q";
        keys [sf::Keyboard::R] = "r";
        keys [sf::Keyboard::S] = "s";
        keys [sf::Keyboard::T] = "t";
        keys [sf::Keyboard::U] = "u";
        keys [sf::Keyboard::V] = "v";
        keys [sf::Keyboard::W] = "w";
        keys [sf::Keyboard::X] = "x";
        keys [sf::Keyboard::Y] = "y";
        keys [sf::Keyboard::Z] = "z";

    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::BackSpace, "BackSpace"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Space, "Space"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Return, "Enter"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Up, "Cima"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Down, "Baixo"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Left, "Esquerda"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Right, "Direita"));
}