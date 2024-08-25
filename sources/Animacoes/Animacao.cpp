#include "../../include/Animacoes/Animacao.hpp"

Animacoes::Animacao::Animacao(sf::RectangleShape *crp):
corpo(crp),
imagens(),
imagemAtual(""),
relogio()
{
}

Animacoes::Animacao::Animacao()
{
}

Animacoes::Animacao::~Animacao()
{
    map<string, Imagem*>::iterator it = imagens.begin();
    while (it != imagens.end())
    {
        if(it->second)
            delete it->second;
        it++;
    }
    imagens.clear();
}

const string Animacoes::Animacao::getImagemAtual() const
{
    return imagemAtual;
}

const int Animacoes::Animacao::getQuadroAtual()
{  
    return imagens[imagemAtual]->getQuadroAtual();
}

void Animacoes::Animacao::setQuadroAtual(const unsigned int imgAtual)
{
    
    imagens[imagemAtual]->setQuadroAtual(imgAtual);
}

const bool Animacoes::Animacao::getTerminouAnimacao()
{
    return imagens[imagemAtual]->getTerminouAnimacao();
}

const float Animacoes::Animacao::getTempoTotal()
{
    return imagens[imagemAtual]->getTempoTotal();
}

void Animacoes::Animacao::setTempoTotal(const float tempoTotal)
{
    imagens[imagemAtual]->setTempoTotal(tempoTotal);
}

void Animacoes::Animacao::setImgAtual(const string imgAtual)
{
    imagemAtual = imgAtual;
}

void Animacoes::Animacao::atualizar(const bool paraDireita, string imgAtual)
{
    if(imagemAtual != imgAtual)
    {
        if(imagemAtual != "")
        {
            imagens[imagemAtual]->resetar();
        }
        imagemAtual = imgAtual;
    }

    float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();

    Imagem* img = imagens[imagemAtual];
    sf::Vector2f tamCorpo = corpo->getSize();
    sf::Vector2f escala = img->getEscala();
    
    img->atualizar(paraDireita, dt);
    corpo->setTextureRect(img->getTamanho());
    corpo->setTexture(img->getTextura());
    corpo->setOrigin(img->getOrigin());
    corpo->setScale(escala.x, escala.y);

}

void Animacoes::Animacao::addAnimacao(const char *caminhoTextura, string nomeAnimacao, const int qtdImagem, const float tempoTroca, const sf::Vector2f escala, const sf::Vector2f origin, const bool horizontal)
{
    Imagem* img = new Imagem(caminhoTextura, qtdImagem, tempoTroca, escala, origin, horizontal);
    imagens.insert(pair<string, Imagem*>(nomeAnimacao, img));
}
