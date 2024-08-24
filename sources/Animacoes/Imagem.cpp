#include "../../include/Animacoes/Imagem.hpp"

Animacoes::Imagem::Imagem(const char *caminhoTextura, const unsigned int qtd, const float tempo, const sf::Vector2f esc, const sf::Vector2f org, const bool hor):
pGraf(Gerenciadores::GerenciadorGrafico::getInstancia()),
qtdImagem(qtd),
tempoTroca(tempo),
escala(esc),
origem(org),
horizontal(hor)
{
    tempoTotal = 0.0f;
    tamanho = sf::IntRect(0, 0, 0, 0);
    imgAtual = 0;
    textura = pGraf->carregarTextura(caminhoTextura);
    if(horizontal)
    {
        tamanho.width = textura.getSize().x / (float)qtdImagem;
        tamanho.height = textura.getSize().y;
    } 
    else 
    {
        tamanho.width = textura.getSize().x;
        tamanho.height = textura.getSize().y / (float)qtdImagem;
    }
}

Animacoes::Imagem::~Imagem()
{
}

void Animacoes::Imagem::atualizar(const bool paraEsquerda, const float dt)
{
    tempoTotal += dt;
    if(tempoTotal >= tempoTroca)
    {
        tempoTotal -= tempoTroca;
        imgAtual++;
        if (imgAtual >= qtdImagem)
        {
            imgAtual = 0;
        }
    }
    if(paraEsquerda)
    {
        tamanho.width = -abs(tamanho.width);
        if(horizontal)
        {
            tamanho.left = (imgAtual + 1) * abs(tamanho.width);
        } 
        else 
        {
            tamanho.top = imgAtual * tamanho.height;
            tamanho.left = abs(tamanho.width);
        }
    } 
    else 
    {
        tamanho.width = abs(tamanho.width);
        if(horizontal)
        {
            tamanho.left = imgAtual * tamanho.width;
        } 
        else 
        {
            tamanho.top = imgAtual * tamanho.height;
            tamanho.left = 0.0f;
        }
    }
}

void Animacoes::Imagem::resetar()
{
    imgAtual = 0;
    tempoTotal = 0.0f;
}

const int Animacoes::Imagem::getQuadroAtual() const
{
    return imgAtual;
}

void Animacoes::Imagem::setQuadroAtual(const unsigned int img)
{
    imgAtual = img;
}

const float Animacoes::Imagem::getTempoTotal() const
{
    return tempoTotal;
}

void Animacoes::Imagem::setTempoTotal(const float tempo)
{
    tempoTotal = tempo;
}

const sf::IntRect Animacoes::Imagem::getTamanho() const
{
    return tamanho;
}

const sf::Texture *Animacoes::Imagem::getTextura() const
{
    return &textura;
}

const sf::Vector2f Animacoes::Imagem::getEscala() const
{
    return escala;
}

const sf::Vector2f Animacoes::Imagem::getOrigin() const
{
    return origem;
}
