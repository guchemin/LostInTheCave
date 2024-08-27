#include "../../include/Gerenciadores/GerenciadorColisoes.hpp"

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li, Listas::ListaEntidades* lpl,
                                                        Listas::ListaEntidades* lo, Listas::ListaEntidades* lp):
listaJogadores(lj),
listaInimigos(li),
listaPlataformas(lpl),
listaObstaculos(lo),
listaProjeteis(lp)
{
}

Gerenciadores::GerenciadorColisoes::GerenciadorColisoes()
{
    listaJogadores = NULL;
    listaInimigos = NULL;
    listaPlataformas = NULL;
    listaObstaculos = NULL;
    listaProjeteis = NULL;
}

Gerenciadores::GerenciadorColisoes::~GerenciadorColisoes()
{
    listaInimigos->limpar();
    listaObstaculos->limpar();
    listaPlataformas->limpar();
    listaJogadores->limpar();
    listaProjeteis->limpar();
}

void Gerenciadores::GerenciadorColisoes::verificarColisoes()
{
    if (listaInimigos == NULL || listaObstaculos == NULL || listaJogadores == NULL || listaProjeteis == NULL || listaPlataformas == NULL)
    {
        std::cerr << "Erro: listaInimigos, listaPlataformas ou listaJogadores é nula." << std::endl;
        return;
    }

    sf::Vector2f distcentro;
    sf::Vector2f intersecao;

    Obstaculos::Obstaculo* pObs = NULL;
    Obstaculos::Obstaculo* pObs2 = NULL;
    Plataforma* pPlat = NULL;
    Inimigo* pInim = NULL;
    Inimigo* pInimAux = NULL;
    Jogador* pJog = NULL;
    Projetil* pProj = NULL;

    Listas::Lista<Entidades::Entidade>::Iterador itProj = listaProjeteis->inicio();
    Listas::Lista<Entidades::Entidade>::Iterador itInim = listaInimigos->inicio();
    Listas::Lista<Entidades::Entidade>::Iterador itJog = listaJogadores->inicio();
    Listas::Lista<Entidades::Entidade>::Iterador itPlat = listaPlataformas->inicio();
    Listas::Lista<Entidades::Entidade>::Iterador itObs = listaObstaculos->inicio();
    Listas::Lista<Entidades::Entidade>::Iterador itObs2 = listaObstaculos->inicio();

    for(itPlat = listaPlataformas->inicio(); itPlat != listaPlataformas->fim(); ++itPlat)
    {
        pPlat = static_cast<Plataforma*>(*itPlat);
        for(itInim = listaInimigos->inicio(); itInim != listaInimigos->fim(); ++itInim)
        {
            pInim = static_cast<Inimigo*>(*itInim);

            distcentro.x = pPlat->getCentro().x - pInim->getCentro().x;
            distcentro.y = pPlat->getCentro().y - pInim->getCentro().y;

            intersecao.x = pPlat->getTamanho().x/2.0f + pInim->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pPlat->getTamanho().y/2.0f + pInim->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pInim->colide(pPlat, intersecao);
            }
        }

        for(itObs = listaObstaculos->inicio(); itObs != listaObstaculos->fim(); ++itObs)
        {
            pObs = static_cast<Obstaculos::Obstaculo*>(*itObs);

            distcentro.x = pPlat->getCentro().x - pObs->getCentro().x;
            distcentro.y = pPlat->getCentro().y - pObs->getCentro().y;

            intersecao.x = pPlat->getTamanho().x/2.0f + pObs->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pPlat->getTamanho().y/2.0f + pObs->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pObs->colide(pPlat, intersecao);
            }
        }

        for(itProj = listaProjeteis->inicio(); itProj != listaProjeteis->fim(); ++itProj)
        {
            pProj = static_cast<Projetil*>(*itProj);

            distcentro.x = pPlat->getCentro().x - pProj->getCentro().x;
            distcentro.y = pPlat->getCentro().y - pProj->getCentro().y;

            intersecao.x = pPlat->getTamanho().x/2.0f + pProj->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pPlat->getTamanho().y/2.0f + pProj->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pProj->colide(pPlat, intersecao);
            }
        }
    } 
    
    

    for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
    {
        pJog = static_cast<Jogador*>(*itJog);

        itPlat = listaPlataformas->inicio();
        while(itPlat != listaPlataformas->fim())  
        {
            pPlat = static_cast<Plataforma*>(*itPlat);

            distcentro.x = pPlat->getCentro().x - pJog->getCentro().x;
            distcentro.y = pPlat->getCentro().y - pJog->getCentro().y;

            intersecao.x = pPlat->getTamanho().x / 2.0f + pJog->getTamanho().x / 2.0f - fabs(distcentro.x);
            intersecao.y = pPlat->getTamanho().y / 2.0f + pJog->getTamanho().y / 2.0f - fabs(distcentro.y);
            
            if (intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                if (pPlat->getFalsa())
                {
                    itPlat = listaPlataformas->remover(itPlat);
                }
                else
                {
                    pJog->colide(pPlat, intersecao);
                    ++itPlat;
                }
            }
            else
            {
                ++itPlat;
            }
        }
    } 

    for(itObs = listaObstaculos->inicio(); itObs != listaObstaculos->fim(); ++itObs)
    {
        pObs = static_cast<Obstaculos::Obstaculo*>(*itObs);
        for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
        {
            pJog = static_cast<Jogador*>(*itJog);

            distcentro.x = pObs->getCentro().x - pJog->getCentro().x;
            distcentro.y = pObs->getCentro().y - pJog->getCentro().y;

            intersecao.x = pObs->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pObs->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                if(pObs->getDanoso())
                {
                    Obstaculos::Espinho* espinho = static_cast<Obstaculos::Espinho*>(pObs);
                    pJog->tiraVida(espinho->getAfiado());
                }
                pJog->colide(pObs, intersecao);
            }
        }

        for(itObs2 = itObs.getProx(); itObs2 != listaObstaculos->fim(); ++itObs2)
        {
            pObs2 = static_cast<Obstaculos::Obstaculo*>(*itObs2);
            distcentro.x = pObs->getCentro().x - pObs2->getCentro().x;
            distcentro.y = pObs->getCentro().y - pObs2->getCentro().y;

            intersecao.x = pObs->getTamanho().x/2.0f + pObs2->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pObs->getTamanho().y/2.0f + pObs2->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pObs->colide(pObs2, intersecao);
                pObs2->colide(pObs, intersecao);
            }
        }
    }

    for(itInim = listaInimigos->inicio(); itInim != listaInimigos->fim(); ++itInim)
    {
        pInim = static_cast<Inimigo*>(*itInim);
        float menorDist = 999999.0f;
        float dist;

        for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
        {
            pJog = static_cast<Jogador*>(*itJog);

            distcentro.x = pInim->getCentro().x - pJog->getCentro().x;
            distcentro.y = pInim->getCentro().y - pJog->getCentro().y;

            intersecao.x = pInim->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pInim->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

            dist = sqrt(pow(pJog->getCentro().x - pInim->getCentro().x, 2) + pow(pJog->getCentro().y - pInim->getCentro().y, 2));

            if(dist < menorDist)
            {
                menorDist = dist;
                pInim->setJogador(pJog);
            }

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pJog->colide(pInim, intersecao);
                pInim->colide(pJog, intersecao);
            }
        }
        if(menorDist <= pInim->getRaioAtaque())
        {
            pInim->agir();
        }
    }
    
    for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
    {
        pJog = static_cast<Jogador*>(*itJog);
        float menorDist = 999999.0f;
        float dist;
        for(itInim = listaInimigos->inicio(); itInim != listaInimigos->fim(); ++itInim)
        {
            pInim = static_cast<Inimigo*>(*itInim);
            dist = sqrt(pow(pJog->getPosicao().x - pInim->getPosicao().x, 2) + pow(pJog->getPosicao().y - pInim->getPosicao().y, 2));
            if(dist < menorDist)
            {
                menorDist = dist;
                pInimAux = pInim;
            }
        }

        if(pInimAux)
        {
            if(pJog->podeAtacar(pInimAux->getCentro().x > pJog->getCentro().x))
            {
                distcentro.x = pJog->getCentro().x - pInimAux->getCentro().x;
                distcentro.y = pJog->getCentro().y - pInimAux->getCentro().y;
                intersecao.y = pJog->getTamanho().y/2.0f + pInimAux->getTamanho().y/2.0f - fabs(distcentro.y);

                if(fabs(distcentro.x) < pJog->getRaioAtaque() && intersecao.y > 0.0f)
                {
                    pInimAux->tiraVida(pJog->getDano());
                }
            }
        }
    }

    for(itProj = listaProjeteis->inicio(); itProj != listaProjeteis->fim(); ++itProj)
    {
        pProj = static_cast<Projetil*>(*itProj);

        for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
        {
            pJog = static_cast<Jogador*>(*itJog);

            distcentro.x = pProj->getCentro().x - pJog->getCentro().x;
            distcentro.y = pProj->getCentro().y - pJog->getCentro().y;

            intersecao.x = pProj->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pProj->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pProj->colide(pJog, intersecao);
            }
        }
    }
}