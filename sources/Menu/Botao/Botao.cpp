#include "../../../include/Menu/Botao/Botao.hpp"

Botao::Botao(sf::Vector2f pos, TipoBotao tp, string txt):
tipo(tp),
texto()
{
    corpo.setPosition(pos);
    corpo.setSize(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y));
    corpo.setFillColor(sf::Color::White);

    texto.setInfo(txt);
    texto.setTamanhoFonte(48);
    texto.setCor(sf::Color::Black);
    sf::Vector2f posTexto;
    posTexto.x = pos.x + TAMANHO_BOTAO_X / 2.0f - texto.getTamanho().x / 2.0f;
    posTexto.y = pos.y + TAMANHO_BOTAO_Y / 2.0f - texto.getTamanho().y / 1.2f;
    texto.setPos(posTexto);
}

Botao::Botao()
{
}

Botao::~Botao()
{
}

TipoBotao Botao::getTipo()
{
    return tipo;
}

void Botao::setSelecionado(const bool selecionado)
{
    if(selecionado)
    {
        corpo.setFillColor(sf::Color::Green);
        //corpo.setTexture(&texturaSelecionado);
    }
    else
    {
        corpo.setFillColor(sf::Color::White);
        //corpo.setTexture(&texturaPadrao);
    }
}

void Botao::desenhar()
{
    pGraf->desenhar(corpo);
    texto.desenhar();
}
