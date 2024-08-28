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

    nlohmann::json Entidade::salvarJogo()
    {
        nlohmann::json j;
        j["pos"] = {getPosicao().x, getPosicao().y};
        j["tipo"] = tipo;
        return j;
    }

    sf::RectangleShape Entidade::getCorpo()
    {
        return corpo;
    }

    sf::Vector2f Entidade::getCentro()
    {
        return sf::Vector2f(getPosicao() + getTamanho() / 2.0f);
    }

    sf::Vector2f Entidade::getTamanho()
    {
        return corpo.getSize();
    }

    sf::Vector2f Entidade::getPosicao()
    {
        return corpo.getPosition();
    }
}