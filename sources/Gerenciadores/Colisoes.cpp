#include "../../include/Gerenciadores/Colisoes.hpp"

Gerenciadores::Colisoes::Colisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li,Listas::ListaEntidades* lo):
listaJogadores(lj),
listaInimigos(li),
listaObstaculos(lo)
{
}

Gerenciadores::Colisoes::Colisoes()
{
    listaJogadores = NULL;
    listaInimigos = NULL;
    listaObstaculos = NULL;
}

Gerenciadores::Colisoes::~Colisoes()
{
    listaInimigos->limpar();
    listaObstaculos->limpar();
    listaJogadores->limpar();
}

void Gerenciadores::Colisoes::verificarColisoes()
{
    if (listaInimigos == NULL || listaObstaculos == NULL || listaJogadores == NULL)
    {
        std::cerr << "Erro: listaInimigos, listaPlataformas ou listaJogadores é nula." << std::endl;
        return;
    }

    std::vector<Entidades::Entidades*>::iterator it1;
    std::vector<Entidades::Entidades*>::iterator it2;

    sf::Vector2f distcentro;
    sf::Vector2f intersecao;

    for (it1 = listaObstaculos->getInicio(); it1 != listaObstaculos->getFim(); ++it1)
    {
        for (it2 = listaInimigos->getInicio(); it2!= listaInimigos->getFim(); ++it2)
        {
            distcentro.x = (*it1)->getCentro().x - (*it2)->getCentro().x;
            distcentro.y = (*it1)->getCentro().y - (*it2)->getCentro().y;

            intersecao.x = (*it1)->getTamanho().x/2.0f + (*it2)->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = (*it1)->getTamanho().y/2.0f + (*it2)->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                Inimigo::Inimigo* inimigo = dynamic_cast<Inimigo::Inimigo*>(*it2);
                inimigo->colide((*it1), intersecao);
            }
        }

        for(it2 = listaJogadores->getInicio(); it2 != listaJogadores->getFim(); ++it2)
        {
            distcentro.x = (*it1)->getCentro().x - (*it2)->getCentro().x;
            distcentro.y = (*it1)->getCentro().y - (*it2)->getCentro().y;

            intersecao.x = (*it1)->getTamanho().x/2.0f + (*it2)->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = (*it1)->getTamanho().y/2.0f + (*it2)->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                Jogador::Jogador* jogador = dynamic_cast<Jogador::Jogador*>(*it2);
                jogador->colide((*it1), intersecao);
            }
        }
    }

        for (it1 = listaInimigos->getInicio(); it1 != listaInimigos->getFim(); ++it1)
    {
        for (it2 = listaJogadores->getInicio(); it2!= listaJogadores->getFim(); ++it2)
        {
            distcentro.x = (*it1)->getCentro().x - (*it2)->getCentro().x;
            distcentro.y = (*it1)->getCentro().y - (*it2)->getCentro().y;

            intersecao.x = (*it1)->getTamanho().x/2.0f + (*it2)->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = (*it1)->getTamanho().y/2.0f + (*it2)->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
            {
                Jogador::Jogador* jogador = dynamic_cast<Jogador::Jogador*>(*it2);
                jogador->colide((*it1), intersecao);
            }
        }
    }

}