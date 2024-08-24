#include "../../include/Menu/MenuPausa.hpp"

Menu::MenuPausa::MenuPausa(Fases::Fase *f):
Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuPausa, "PAUSA"),
fase(f)
{
    filtro.setSize(pGraf->getTamanho());
    filtro.setFillColor(sf::Color(0, 0, 0, 100));
    fundo.setSize(sf::Vector2f(pGraf->getTamanho().x / 2.0f, pGraf->getTamanho().y));
    fundo.setPosition(pGraf->getCentro().x - fundo.getSize().x / 2.0f, 0.0f);
    fundo.setFillColor(sf::Color(0, 0, 0, 200));

    criarBotoes();
    ativo = true;
}

Menu::MenuPausa::MenuPausa()
{
}

Menu::MenuPausa::~MenuPausa()
{
}

void Menu::MenuPausa::criarBotoes()
{
    float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
    float posY = pGraf->getCentro().y - tamBotoes.y;

    adicionarBotao("CONTINUAR", sf::Vector2f(posX, posY), TipoBotao::CONTINUAR);
    adicionarBotao("SAIR", sf::Vector2f(posX, posY + tamBotoes.y * 1.5f), TipoBotao::SAIR);
    inicializarBotoes();
}

void Menu::MenuPausa::setFase(Fases::Fase *f)
{
    if(f)
    {
        fase = f;
    }
}

void Menu::MenuPausa::selecionar(TipoBotao tipo)
{
    if(ativo)
    {
        switch (tipo)
        {
        case TipoBotao::CONTINUAR:
        {   
            remover = true;
            break;
        }

        case TipoBotao::SAIR:
        {
            pGraf->fecharJanela();
            break;
        }
        
        default:
            break;
        }
    }
}

void Menu::MenuPausa::executar()
{
    if(remover)
    {
        pEstados->remover();
    }
    else
    {
        fase->desenhar();
        pGraf->desenhar(filtro);
        pGraf->desenhar(fundo);
        titulo.desenhar();
        desenhar();
    }
}
