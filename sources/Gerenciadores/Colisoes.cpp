#include "../../include/Gerenciadores/Colisoes.hpp"

Gerenciadores::Colisoes::Colisoes(Listas::ListaEntidades *lPersonagem, Listas::ListaEntidades *lPlataforma):
listaPersonagem(lPersonagem),
listaPlataforma(lPlataforma)
{
}

Gerenciadores::Colisoes::Colisoes()
{

}

Gerenciadores::Colisoes::~Colisoes()
{
    listaPersonagem = NULL;
    listaPlataforma = NULL;
}

void Gerenciadores::Colisoes::verificarColisoes()
{
    if (listaPersonagem == NULL || listaPlataforma == NULL)
    {
        std::cerr << "Erro: listaPersonagem ou listaPlataforma é nula." << std::endl;
        return;
    }


    std::vector<Entidades::Entidades*>::iterator it1;
    std::vector<Entidades::Entidades*>::iterator it2;

    sf::Vector2f distcentro;
    sf::Vector2f intersecao;

    for (it1 = listaPersonagem->getInicio(); it1 != listaPersonagem->getFim(); ++it1)
    {

        for (it2 = listaPlataforma->getInicio(); it2!= listaPlataforma->getFim(); ++it2)
        {
            distcentro.x = (*it1)->getCentroX() - (*it2)->getCentroX();
            distcentro.y = (*it1)->getCentroY() - (*it2)->getCentroY();

            intersecao.x = (*it1)->getTamanhoX()/2 + (*it2)->getTamanhoX()/2 - abs(distcentro.x);
            intersecao.y = (*it1)->getTamanhoY()/2 + (*it2)->getTamanhoY()/2 - abs(distcentro.y);

            if(intersecao.x > 0.0f && intersecao.y > 0.0f)
                (*it1)->colide((*it2), intersecao);
        }
    }
}
