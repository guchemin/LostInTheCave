#include "../../include/Entidades/Projetil.hpp"

namespace Entidades
{
    Projetil::Projetil(sf::Vector2f pos, sf::Vector2f velocidade):
    Entidade(pos, sf::Vector2f(25.0f, 25.0f), TIPO::PROJETIL)
    {
        vel = velocidade;

        textura.loadFromFile(CAMINHO_TEXTURA_PROJETIL);
        corpo.setTexture(&textura);
    }

    Projetil::Projetil()
    {
    }

    Projetil::~Projetil()
    {
    }
    
    nlohmann::json Projetil::salvarJogo() // salva apenas o que é exclusivamente da classe
    {
        nlohmann::json j = Entidade::salvarJogo();
        j["vel"] = {vel.x, vel.y};
        return j;
    }

    void Projetil::setVelocidade(sf::Vector2f v)
    {
        vel = v;
    }

    void Projetil::setPosicao(sf::Vector2f p)
    {
        Entidade::setPosicao(p);
    }

    const bool Projetil::saiuDaTela()
    {
        if(fabs(getPosicao().y - pGraf->getCentro().y) > pGraf->getTamanho().y / 2.0f)
        {
            return true;
        }
        return false;
    }

    void Projetil::executar(const float dt)
    {
        sf::Vector2f ds = vel * dt;

        //acao da gravidade
        if(getPosicao().y < 1000.0f)
        {
            vel.y += GRAVIDADE * dt;
            vel.y -= EMPUXO * dt;
            ds.y = vel.y * dt;
        }
        else
        {
            vel.y = 0.0f;
            ds.y = 0.0f;
        }

        corpo.move(ds);
    }

    void Projetil::colide(Entidade* ent, const sf::Vector2f intersec) // colide com jogador, tirando vida, e com plataforma, sumindo
    {
        switch(ent->getTipo())
        {
        case TIPO::PLATAFORMA:
        {
            setPosicao(sf::Vector2f(-1000.0f, -1000.0f));
            setVelocidade(sf::Vector2f(0.0f, 0.0f));
            break;
        }
            
        case TIPO::JOGADOR:
        {
            Personagem::Jogador* pJog = static_cast<Personagem::Jogador*>(ent);
            (*pJog)-=(DANO_ATIRADOR);
            setPosicao(sf::Vector2f(-1000.0f, -1000.0f));
            setVelocidade(sf::Vector2f(0.0f, 0.0f));
            break;
        }
        default:
            break;
        }
    }
}