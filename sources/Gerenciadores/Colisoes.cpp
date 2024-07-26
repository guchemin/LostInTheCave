#include "../../include/Gerenciadores/Colisoes.hpp"

Gerenciadores::Colisoes::Colisoes(Listas::ListaEntidades *lJogadores, Listas::ListaEntidades* lInimigos,Listas::ListaEntidades *lPlataformas):
listaJogadores(lJogadores),
listaInimigos(lInimigos),
listaPlataformas(lPlataformas)
{
}

Gerenciadores::Colisoes::Colisoes()
{
    listaJogadores = NULL;
    listaInimigos = NULL;
    listaPlataformas = NULL;
}

Gerenciadores::Colisoes::~Colisoes()
{
    listaInimigos->limpar();
    listaPlataformas->limpar();
    listaJogadores->limpar();
}

void Gerenciadores::Colisoes::verificarColisoes()
{
    if (listaInimigos == NULL || listaPlataformas == NULL || listaJogadores == NULL)
    {
        std::cerr << "Erro: listaInimigos, listaPlataformas ou listaJogadores é nula." << std::endl;
        return;
    }

    std::vector<Entidades::Entidades*>::iterator it1;
    std::vector<Entidades::Entidades*>::iterator it2;

    sf::Vector2f distcentro;
    sf::Vector2f intersecao;

    for (it1 = listaPlataformas->getInicio(); it1 != listaPlataformas->getFim(); ++it1)
    {
        for (it2 = listaInimigos->getInicio(); it2!= listaInimigos->getFim(); ++it2)
        {
            distcentro.x = (*it1)->getCentro().x - (*it2)->getCentro().x;
            distcentro.y = (*it1)->getCentro().y - (*it2)->getCentro().y;

            intersecao.x = (*it1)->getTamanho().x/2.0f + (*it2)->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = (*it1)->getTamanho().y/2.0f + (*it2)->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
                (*it2)->colide((*it1), intersecao);
        }

        for(it2 = listaJogadores->getInicio(); it2 != listaJogadores->getFim(); ++it2)
        {
            distcentro.x = (*it1)->getCentro().x - (*it2)->getCentro().x;
            distcentro.y = (*it1)->getCentro().y - (*it2)->getCentro().y;

            intersecao.x = (*it1)->getTamanho().x/2.0f + (*it2)->getTamanho().x/2.0f - fabs(distcentro.x);
            intersecao.y = (*it1)->getTamanho().y/2.0f + (*it2)->getTamanho().y/2.0f - fabs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
                (*it2)->colide((*it1), intersecao);
        }
    }
}