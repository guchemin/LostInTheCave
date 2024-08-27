#include "../../include/Observadores/Observador.hpp"

Observadores::Observador::Observador():
pInp(GerenciadorInputs::getInstancia()),
pEstados(GerenciadorEstados::getInstancia()),
teclado()
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
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num0, '0'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num1, '1'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num2, '2'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num3, '3'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num4, '4'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num5, '5'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num6, '6'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num7, '7'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num8, '8'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Num9, '9'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::A, 'a'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::B, 'b'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::C, 'c'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::D, 'd'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::E, 'e'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::F, 'f'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::G, 'g'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::H, 'h'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::I, 'i'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::J, 'j'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::K, 'k'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::L, 'l'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::M, 'm'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::N, 'n'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::O, 'o'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::P, 'p'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Q, 'q'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::R, 'r'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::S, 's'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::T, 't'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::U, 'u'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::V, 'v'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::X, 'x'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Y, 'y'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::W, 'w'));
    teclado.insert(std::pair<sf::Keyboard::Key,char>(sf::Keyboard::Z, 'z'));

    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::BackSpace, "BackSpace"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Space, "Space"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Return, "Enter"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Up, "Cima"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Down, "Baixo"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Left, "Esquerda"));
    tecladoEspecial.insert(std::pair<sf::Keyboard::Key,string>(sf::Keyboard::Right, "Direita"));
}