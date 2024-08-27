#include "../../../include/Menu/Botao/Texto.hpp"

Texto::Texto(const char *caminhoFonte):
pGraf(Gerenciadores::GerenciadorGrafico::getInstancia())
{
    fonte.loadFromFile(caminhoFonte);
    texto.setFont(fonte);
    setInfo("");
}

Texto::~Texto()
{
}

void Texto::setInfo(string informacao)
{
    info = informacao;
    texto.setString(informacao);
}

void Texto::setPos(sf::Vector2f pos)
{
    texto.setPosition(pos);
}

void Texto::setCor(sf::Color cor)
{
    texto.setFillColor(cor);
}

void Texto::setTamanhoFonte(int tam)
{
    texto.setCharacterSize(tam);
}

const string Texto::getInfo()
{
    return info;
}

const sf::Vector2f Texto::getTamanho()
{
    sf::FloatRect textoRect = texto.getLocalBounds();
    return sf::Vector2f(textoRect.width, textoRect.height);
}

void Texto::desenhar()
{
    pGraf->desenhar(texto);
}
