#include "../../include/Animacoes/Imagem.hpp"
#include <iostream>

namespace Animacoes
{
    Imagem::Imagem(const char *caminhoTextura, const unsigned int qtd, const float tempo, const sf::Vector2f esc, const sf::Vector2f org, const bool hor):
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
        terminouAnimacao = false;
    }

    Imagem::~Imagem()
    {
    }

    void Imagem::atualizar(const bool paraDireita, const float dt)
    {
        tempoTotal += dt;
        if(tempoTotal >= tempoTroca)
        {
            tempoTotal -= tempoTroca;
            imgAtual++;
            if (imgAtual >= qtdImagem)
            {
                setTerminouAnimacao(true);
                imgAtual = 0;
            }
        }
        if(!paraDireita)
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

    void Imagem::resetar()
    {
        imgAtual = 0;
        tempoTotal = 0.0f;
    }

    const bool Imagem::getTerminouAnimacao()
    {
        if(terminouAnimacao)
        {
            terminouAnimacao = false;
            return true;
        }
        return false;
    }

    void Imagem::setTerminouAnimacao(const bool terminou)
    {
        terminouAnimacao = terminou;
    }

    const int Imagem::getQuadroAtual() const
    {
        return imgAtual;
    }

    void Imagem::setQuadroAtual(const unsigned int img)
    {
        imgAtual = img;
    }

    const float Imagem::getTempoTotal() const
    {
        return tempoTotal;
    }

    void Imagem::setTempoTotal(const float tempo)
    {
        tempoTotal = tempo;
    }

    const sf::IntRect Imagem::getTamanho() const
    {
        return tamanho;
    }

    const sf::Texture *Imagem::getTextura() const
    {
        return &textura;
    }

    const sf::Vector2f Imagem::getEscala() const
    {
        return escala;
    }

    const sf::Vector2f Imagem::getOrigin() const
    {
        return origem;
    }
}
