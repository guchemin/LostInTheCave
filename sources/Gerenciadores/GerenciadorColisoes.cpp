#include "../../include/Gerenciadores/GerenciadorColisoes.hpp"

namespace Gerenciadores
{
    GerenciadorColisoes::GerenciadorColisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li, Listas::ListaEntidades* lpl,
                                            Listas::ListaEntidades* lo, Listas::ListaEntidades* lp):
        listaJogadores(lj),
        listaInimigos(li),
        listaPlataformas(lpl),
        listaObstaculos(lo),
        listaProjeteis(lp)
    {
    }

    GerenciadorColisoes::GerenciadorColisoes()
    {
        listaJogadores = NULL;
        listaInimigos = NULL;
        listaPlataformas = NULL;
        listaObstaculos = NULL;
        listaProjeteis = NULL;
    }

    GerenciadorColisoes::~GerenciadorColisoes()
    {
        listaInimigos->limpar();
        listaObstaculos->limpar();
        listaPlataformas->limpar();
        listaJogadores->limpar();
        listaProjeteis->limpar();
    }

    void GerenciadorColisoes::colidePlataforma()
    {
        sf::Vector2f distcentro;
        sf::Vector2f intersecao;

        Entidades::Obstaculos::Plataforma* pPlat = NULL;
        Entidades::Personagem::Inimigo* pInim = NULL;
        Entidades::Obstaculos::Obstaculo* pObs = NULL;
        Entidades::Projetil* pProj = NULL;

        Listas::ListaEntidades::IteradorEntidades itPlat = listaPlataformas->inicio();
        Listas::ListaEntidades::IteradorEntidades itInim = listaInimigos->inicio();
        Listas::ListaEntidades::IteradorEntidades itObs = listaObstaculos->inicio();
        Listas::ListaEntidades::IteradorEntidades itProj = listaProjeteis->inicio();

        for(itPlat = listaPlataformas->inicio(); itPlat != listaPlataformas->fim(); ++itPlat)
        {
            pPlat = static_cast<Entidades::Obstaculos::Plataforma*>(*itPlat);
            for(itInim = listaInimigos->inicio(); itInim != listaInimigos->fim(); ++itInim)
            {
                pInim = static_cast<Entidades::Personagem::Inimigo*>(*itInim);

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
                pObs = static_cast<Entidades::Obstaculos::Obstaculo*>(*itObs);

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
                pProj = static_cast<Entidades::Projetil*>(*itProj);

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
    }

    void GerenciadorColisoes::colideJogador()
    {
        sf::Vector2f distcentro;
        sf::Vector2f intersecao;

        Entidades::Personagem::Jogador* pJog = NULL;
        Entidades::Obstaculos::Plataforma* pPlat = NULL;
        Entidades::Personagem::Inimigo* pInim = NULL;
        Entidades::Personagem::Inimigo* pInimAux = NULL;

        Listas::ListaEntidades::IteradorEntidades itJog = listaJogadores->inicio();
        Listas::ListaEntidades::IteradorEntidades itPlat = listaPlataformas->inicio();
        Listas::ListaEntidades::IteradorEntidades itInim = listaInimigos->inicio();

        for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
        {
            pJog = static_cast<Entidades::Personagem::Jogador*>(*itJog);

            itPlat = listaPlataformas->inicio();
            while(itPlat != listaPlataformas->fim())  
            {
                pPlat = static_cast<Entidades::Obstaculos::Plataforma*>(*itPlat);

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

            float menorDist = 999999.0f;
            float dist;
            for(itInim = listaInimigos->inicio(); itInim != listaInimigos->fim(); ++itInim)
            {
                pInim = static_cast<Entidades::Personagem::Inimigo*>(*itInim);
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
                        (*pInimAux) -= pJog->getDano();
                        Entidades::Personagem::Jogador::somaPontos(pInimAux->getPontuacao() / 10.0f);
                    }
                }
            }
        } 
    }

    void GerenciadorColisoes::colideObstaculo()
    {
        sf::Vector2f distcentro;
        sf::Vector2f intersecao;

        Entidades::Obstaculos::Obstaculo* pObs = NULL;
        Entidades::Personagem::Jogador* pJog = NULL;
        Entidades::Obstaculos::Obstaculo* pObs2 = NULL;

        Listas::ListaEntidades::IteradorEntidades itObs = listaObstaculos->inicio();
        Listas::ListaEntidades::IteradorEntidades itJog = listaJogadores->inicio();
        Listas::ListaEntidades::IteradorEntidades itObs2 = listaObstaculos->inicio();

        for(itObs = listaObstaculos->inicio(); itObs != listaObstaculos->fim(); ++itObs)
        {
            pObs = static_cast<Entidades::Obstaculos::Obstaculo*>(*itObs);
            for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
            {
                pJog = static_cast<Entidades::Personagem::Jogador*>(*itJog);

                distcentro.x = pObs->getCentro().x - pJog->getCentro().x;
                distcentro.y = pObs->getCentro().y - pJog->getCentro().y;

                intersecao.x = pObs->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
                intersecao.y = pObs->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

                if(intersecao.x > 0.0f && intersecao.y > 0.0f)
                {
                    if(pObs->getDanoso())
                    {
                        Obstaculos::Espinho* espinho = static_cast<Entidades::Obstaculos::Espinho*>(pObs);
                        (*pJog)-=(espinho->getAfiado());
                    }
                    pJog->colide(pObs, intersecao);
                }
            }

            for(itObs2 = itObs.getProx(); itObs2 != listaObstaculos->fim(); ++itObs2)
            {
                pObs2 = static_cast<Entidades::Obstaculos::Obstaculo*>(*itObs2);
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
    }

    void GerenciadorColisoes::colideInimigo()
    {
        sf::Vector2f distcentro;
        sf::Vector2f intersecao;

        Entidades::Personagem::Inimigo* pInim = NULL;
        Entidades::Personagem::Jogador* pJog = NULL;
        Entidades::Personagem::Inimigo* pInimAux = NULL;

        Listas::ListaEntidades::IteradorEntidades itInim = listaInimigos->inicio();
        Listas::ListaEntidades::IteradorEntidades itJog = listaJogadores->inicio();
        Listas::ListaEntidades::IteradorEntidades itInim2 = listaInimigos->inicio();

        for(itInim = listaInimigos->inicio(); itInim != listaInimigos->fim(); ++itInim)
        {
            pInim = static_cast<Entidades::Personagem::Inimigo*>(*itInim);
            float menorDist = 999999.0f;
            float dist;

            for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
            {
                pJog = static_cast<Entidades::Personagem::Jogador*>(*itJog);

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

            for(itInim2 = itInim.getProx(); itInim2 != listaInimigos->fim(); ++itInim2)
            {
                pInimAux = static_cast<Entidades::Personagem::Inimigo*>(*itInim2);
                distcentro.x = pInim->getCentro().x - pInimAux->getCentro().x;
                distcentro.y = pInim->getCentro().y - pInimAux->getCentro().y;

                intersecao.x = pInim->getTamanho().x/2.0f + pInimAux->getTamanho().x/2.0f - fabs(distcentro.x);
                intersecao.y = pInim->getTamanho().y/2.0f + pInimAux->getTamanho().y/2.0f - fabs(distcentro.y);

                if(intersecao.x > 0.0f && intersecao.y > 0.0f)
                {
                    pInim->colide(pInimAux, intersecao);
                    pInimAux->colide(pInim, intersecao);
                }
            }
        }
    }

    void GerenciadorColisoes::colideProjetil()
    {
        sf::Vector2f distcentro;
        sf::Vector2f intersecao;

        Entidades::Projetil* pProj = NULL;
        Entidades::Personagem::Jogador* pJog = NULL;

        Listas::ListaEntidades::IteradorEntidades itProj = listaProjeteis->inicio();
        Listas::ListaEntidades::IteradorEntidades itJog = listaJogadores->inicio();

        for(itProj = listaProjeteis->inicio(); itProj != listaProjeteis->fim(); ++itProj)
        {
            pProj = static_cast<Entidades::Projetil*>(*itProj);

            for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
            {
                pJog = static_cast<Entidades::Personagem::Jogador*>(*itJog);

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

    void GerenciadorColisoes::verificarColisoes()
    {
        if (listaInimigos == NULL || listaObstaculos == NULL || listaJogadores == NULL || listaProjeteis == NULL || listaPlataformas == NULL)
        {
            std::cerr << "Erro: listaInimigos, listaPlataformas ou listaJogadores é nula." << std::endl;
            return;
        }
        colidePlataforma();
        colideJogador();
        colideObstaculo();
        colideInimigo();
        colideProjetil();    
    }
}