#include "../../../include/Menu/Botao/Botao.hpp"

Botao::Botao(sf::Vector2f pos, TipoBotao tp, string txt):
    tipo(tp),
    texto(),
    texturaPadrao(pGraf->carregarTextura(CAMINHO_BOTAO)),
    texturaSelecionado(pGraf->carregarTextura(CAMINHO_BOTAO_SELECIONADO))
{
    corpo.setPosition(pos);
    corpo.setSize(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y));
    corpo.setTexture(&texturaPadrao);
    corpo.setFillColor(sf::Color(120, 120, 120));

    texto = string(txt);
    texto.setTamanhoFonte(48);
    texto.setCor(sf::Color(0, 0, 50));
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

void Botao::setPosicao(const sf::Vector2f pos)
{
    corpo.setPosition(pos);
    sf::Vector2f posTexto;
    posTexto.x = pos.x + TAMANHO_BOTAO_X / 2.0f - texto.getTamanho().x / 2.0f;
    posTexto.y = pos.y + TAMANHO_BOTAO_Y / 2.0f - texto.getTamanho().y / 1.2f;
    texto.setPos(posTexto);
}

sf::Vector2f Botao::getPosicao()
{
    return corpo.getPosition();
}

void Botao::setSelecionado(const bool selecionado)
{
    if(selecionado)
    {
        corpo.setTexture(&texturaSelecionado);
    }
    else
    {
        corpo.setTexture(&texturaPadrao);
    }
}

void Botao::desenhar()
{
    pGraf->desenhar(corpo);
    texto.desenhar();
}

void Botao::executar(const float dt) // nao usado para essa classe
{
}