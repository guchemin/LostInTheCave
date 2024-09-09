#include "../../include/Entidades/Entidade.hpp"

namespace Entidades
{
    Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
        Ente(),
        tipo(tp),
        corpo(sf::RectangleShape(tam))
    {
        corpo.setPosition(pos);
    }

    Entidade::Entidade()
    {
    }

    Entidade::~Entidade()
    {
    }

    void Entidade::setPosicao(sf::Vector2f pos)
    {
        corpo.setPosition(pos);
    }

    void Entidade::desenhar()
    {
        pGraf->desenhar(corpo);
    }

    nlohmann::json Entidade::salvarJogo() // salva apenas o que é exclusivamente da classe
    {
        nlohmann::json j;
        j["pos"] = {getPosicao().x, getPosicao().y};
        j["tipo"] = tipo;
        return j;
    }

    const sf::RectangleShape Entidade::getCorpo() const
    {
        return corpo;
    }

    const sf::Vector2f Entidade::getCentro() const
    {
        return sf::Vector2f(getPosicao() + getTamanho() / 2.0f);
    }

    const sf::Vector2f Entidade::getTamanho() const
    {
        return corpo.getSize();
    }

    const sf::Vector2f Entidade::getPosicao() const
    {
        return corpo.getPosition();
    }
}