#include "../../include/Gerenciadores/GerenciadorColisoes.hpp"

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li,Listas::ListaEntidades* lo):
listaJogadores(lj),
listaInimigos(li),
listaObstaculos(lo)
{
}

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes()
{
    listaJogadores = NULL;
    listaInimigos = NULL;
    listaObstaculos = NULL;
}

Gerenciadores::GerenciadorColisoes::~GerenciadorColisoes()
{
    listaInimigos->limpar();
    listaObstaculos->limpar();
    listaJogadores->limpar();
}

void Gerenciadores::GerenciadorColisoes::verificarColisoes()
{
    if (listaInimigos == NULL || listaObstaculos == NULL || listaJogadores == NULL)
    {
        std::cerr << "Erro: listaInimigos, listaPlataformas ou listaJogadores é nula." << std::endl;
        return;
    }

    sf::Vector2f distcentro;
    sf::Vector2f intersecao;

    Obstaculos::Obstaculo* pObs = NULL;
    Inimigo* pInim = NULL;
    Jogador* pJog = NULL; 

    int tamObs = listaObstaculos->getTam();
    int tamIni = listaInimigos->getTam();
    int tamJog = listaJogadores->getTam();  

    for(int i = 0; i < tamObs; i++)
    {
        pObs = static_cast<Obstaculos::Obstaculo*>((*listaObstaculos)[i]);

        for(int j = 0; j < tamIni; j++)
        {
            pInim = static_cast<Inimigo*>((*listaInimigos)[j]);

            distcentro.x = pObs->getCentro().x - pInim->getCentro().x;
            distcentro.y = pObs->getCentro().y - pInim->getCentro().y;

            intersecao.x = pObs->getTamanho().x/2.0f + pInim->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pObs->getTamanho().y/2.0f + pInim->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pInim->colide(pObs, intersecao);
            }
        }
        
        for(int j = 0; j < tamJog; j++)
        {
            pJog = static_cast<Jogador*>((*listaJogadores)[j]);

            distcentro.x = pObs->getCentro().x - pJog->getCentro().x;
            distcentro.y = pObs->getCentro().y - pJog->getCentro().y;

            intersecao.x = pObs->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pObs->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pJog->colide(pObs, intersecao);
            }
        }
    }


    for(int i = 0; i < tamIni; i++)
    {
        pInim = static_cast<Inimigo*>((*listaInimigos)[i]);

        for(int j = 0; j < tamJog; j++)
        {
            pJog = static_cast<Jogador*>((*listaJogadores)[j]);

            distcentro.x = pInim->getCentro().x - pJog->getCentro().x;
            distcentro.y = pInim->getCentro().y - pJog->getCentro().y;

            intersecao.x = pInim->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pInim->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pJog->colide(pInim, intersecao);
                pInim->colide(pJog, intersecao);
            }
        }
    }
}