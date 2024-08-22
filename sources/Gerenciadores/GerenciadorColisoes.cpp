#include "../../include/Gerenciadores/GerenciadorColisoes.hpp"

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li,
                                                        Listas::ListaEntidades* lo, Listas::ListaEntidades* lp):
listaJogadores(lj),
listaInimigos(li),
listaObstaculos(lo),
listaProjeteis(lp)
{
}

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes()
{
    listaJogadores = NULL;
    listaInimigos = NULL;
    listaObstaculos = NULL;
    listaProjeteis = NULL;
}

Gerenciadores::GerenciadorColisoes::~GerenciadorColisoes()
{
    listaInimigos->limpar();
    listaObstaculos->limpar();
    listaJogadores->limpar();
    listaProjeteis->limpar();
}

void Gerenciadores::GerenciadorColisoes::verificarColisoes()
{
    if (listaInimigos == NULL || listaObstaculos == NULL || listaJogadores == NULL || listaProjeteis == NULL)
    {
        std::cerr << "Erro: listaInimigos, listaPlataformas ou listaJogadores é nula." << std::endl;
        return;
    }

    sf::Vector2f distcentro;
    sf::Vector2f intersecao;

    Obstaculos::Obstaculo* pObs = NULL;
    Inimigo* pInim = NULL;
    Inimigo* pInim2 = NULL;
    Jogador* pJog = NULL;
    Jogador* pJog2 = NULL; 
    Projetil* pProj = NULL;

    int tamObs = listaObstaculos->getTam();
    int tamIni = listaInimigos->getTam();
    int tamJog = listaJogadores->getTam();  
    int tamProj = listaProjeteis->getTam();

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

    for(int i = 0; i < tamProj; i++)
    {
        pProj = static_cast<Projetil*>((*listaProjeteis)[i]);

        for(int j = 0; j < tamJog; j++)
        {
            pJog = static_cast<Jogador*>((*listaJogadores)[j]);

            distcentro.x = pProj->getCentro().x - pJog->getCentro().x;
            distcentro.y = pProj->getCentro().y - pJog->getCentro().y;

            intersecao.x = pProj->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pProj->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pProj->colide(pJog, intersecao);
            }
        }

        for(int j = 0; j < tamObs; j++)
        {
            pObs = static_cast<Obstaculos::Obstaculo*>((*listaObstaculos)[j]);

            distcentro.x = pProj->getCentro().x - pObs->getCentro().x;
            distcentro.y = pProj->getCentro().y - pObs->getCentro().y;

            intersecao.x = pProj->getTamanho().x/2.0f + pObs->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pProj->getTamanho().y/2.0f + pObs->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pProj->colide(pObs, intersecao);
            }
        }
    }

    for(int i = 0; i < tamIni; i++)
    {
        pInim = static_cast<Inimigo*>((*listaInimigos)[i]);
        float menorDist = 999999.0f;
        float dist;

        for(int j = 0; j < tamJog; j++)
        {
            pJog = static_cast<Jogador*>((*listaJogadores)[j]);

            distcentro.x = pInim->getCentro().x - pJog->getCentro().x;
            distcentro.y = pInim->getCentro().y - pJog->getCentro().y;

            intersecao.x = pInim->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pInim->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

            dist = sqrt(pow(pJog->getPosicao().x - pInim->getPosicao().x, 2) + pow(pJog->getPosicao().y - pInim->getPosicao().y, 2));

            if(dist < menorDist)
            {
                menorDist = dist;
                pInim->setJogador(pJog);
            }

            if(intersecao.x > -pJog->getRaioAtaque() && intersecao.y > 0.0f)
            {
                if(pJog->podeAtacar())
                {
                    pInim->tiraVida(pJog->getDano());
                }

                if(intersecao.x > 0.0f)
                {
                    pJog->colide(pInim, intersecao);
                    pInim->colide(pJog, intersecao);
                }
            }
        }
        if(menorDist <= pInim->getRaioAtaque())
        {
            pInim->agir();
        }

        // for(int j = i + 1; j < tamIni; j++)
        // {
        //     pInim2 = static_cast<Inimigo*>((*listaInimigos)[j]);

        //     distcentro.x = pInim->getCentro().x - pInim2->getCentro().x;
        //     distcentro.y = pInim->getCentro().y - pInim2->getCentro().y;

        //     intersecao.x = pInim->getTamanho().x/2.0f + pInim2->getTamanho().x/2.0f - fabs(distcentro.x);
        //     intersecao.y = pInim->getTamanho().y/2.0f + pInim2->getTamanho().y/2.0f - fabs(distcentro.y);

        //     if(intersecao.x > 0.0f && intersecao.y > 0.0f)
        //     {
        //         // pInim->colide(pInim2, intersecao);
        //     }
        // }
    }

    // for(int i = 0; i < tamJog; i++)
    // {
    //     pJog = static_cast<Jogador*>((*listaJogadores)[i]);

    //     for(int j = i + 1; j < tamJog; j++)
    //     {
    //         pJog2 = static_cast<Jogador*>((*listaJogadores)[j]);

    //         distcentro.x = pJog->getCentro().x - pJog2->getCentro().x;
    //         distcentro.y = pJog->getCentro().y - pJog2->getCentro().y;

    //         intersecao.x = pJog->getTamanho().x/2.0f + pJog2->getTamanho().x/2.0f - fabs(distcentro.x);
    //         intersecao.y = pJog->getTamanho().y/2.0f + pJog2->getTamanho().y/2.0f - fabs(distcentro.y);
            
    //         if(intersecao.x > 0.0f && intersecao.y > 0.0f)
    //         {
    //             pJog->colide(pJog2, intersecao);
    //             pJog2->colide(pJog, intersecao);
    //         }
    //     }
    // }
}