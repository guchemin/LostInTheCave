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
    Jogador* pJog = NULL;
    Projetil* pProj = NULL;

    int tamObs = listaObstaculos->getTam();
    int tamIni = listaInimigos->getTam();
    int tamJog = listaJogadores->getTam();  
    int tamProj = listaProjeteis->getTam();
    int tamPlat = listaPlataformas->getTam();

    for(int i = 0; i < tamPlat; i++)
    {
        pPlat = static_cast<Plataforma*>((*listaPlataformas)[i]);

        for(int j = 0; j < tamIni; j++)
        {
            pInim = static_cast<Inimigo*>((*listaInimigos)[j]);

            distcentro.x = pPlat->getCentro().x - pInim->getCentro().x;
            distcentro.y = pPlat->getCentro().y - pInim->getCentro().y;

            intersecao.x = pPlat->getTamanho().x/2.0f + pInim->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pPlat->getTamanho().y/2.0f + pInim->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pInim->colide(pPlat, intersecao);
            }
        }
        
        for(int j = 0; j < tamJog; j++)
        {
            pJog = static_cast<Jogador*>((*listaJogadores)[j]);

            distcentro.x = pPlat->getCentro().x - pJog->getCentro().x;
            distcentro.y = pPlat->getCentro().y - pJog->getCentro().y;

            intersecao.x = pPlat->getTamanho().x/2.0f + pJog->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pPlat->getTamanho().y/2.0f + pJog->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                if(pPlat->getFalsa())
                {
                    listaPlataformas->remover(pPlat);
                    if(tamPlat > 0)
                    {
                        tamPlat--;
                        i--;
                    }
                }
                pJog->colide(pPlat, intersecao);
            }
        }

        for(int j = 0; j < tamObs; j++)
        {
            pObs = static_cast<Obstaculos::Obstaculo*>((*listaObstaculos)[j]);

            distcentro.x = pPlat->getCentro().x - pObs->getCentro().x;
            distcentro.y = pPlat->getCentro().y - pObs->getCentro().y;

            intersecao.x = pPlat->getTamanho().x/2.0f + pObs->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = pPlat->getTamanho().y/2.0f + pObs->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                pObs->colide(pPlat, intersecao);
            }
        }

        for(int j = 0; j < tamProj; j++)
        {
            pProj = static_cast<Projetil*>((*listaProjeteis)[j]);

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

    for(int i = 0; i < tamObs; i++)
    {
        pObs = static_cast<Obstaculos::Obstaculo*>((*listaObstaculos)[i]);
        for(int j = 0; j < tamJog; j++)
        {
            pJog = static_cast<Jogador*>((*listaJogadores)[j]);

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

        for(int j = i + 1; j < tamObs; j++)
        {
            pObs2 = static_cast<Obstaculos::Obstaculo*>((*listaObstaculos)[j]);
            if(pObs->getTipo() == TIPO::PEDRA && pObs2->getTipo() == TIPO::PEDRA)
            {
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
    }
}