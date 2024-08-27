#include "../../include/Menu/MenuPausa.hpp"

Menu::MenuPausa::MenuPausa(Fases::Fase *f):
Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuPausa, "PAUSA"),
fase(f)
{
    background.setSize(pGraf->getTamanho());
    background.setFillColor(sf::Color(0, 0, 0, 80));
    painel.setSize(sf::Vector2f(pGraf->getTamanho().x / 2.0f, pGraf->getTamanho().y));
    painel.setPosition(pGraf->getCentro().x - painel.getSize().x / 2.0f, 0.0f);
    painel.setFillColor(sf::Color(0, 0, 0, 200));

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
    adicionarBotao("SALVAR", sf::Vector2f(posX, posY + tamBotoes.y * 1.2f), TipoBotao::SALVAR);
    adicionarBotao("VOLTAR AO MENU", sf::Vector2f(posX, posY + tamBotoes.y * 2.4f), TipoBotao::VOLTAR_MENU);
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

        case TipoBotao::SALVAR:
        {
        }

        case TipoBotao::VOLTAR_MENU:
        {
            remover = true;
            fase->setRemover(true);
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
        pGraf->desenhar(background);
        pGraf->desenhar(painel);
        titulo.desenhar();
        desenhar();
    }
}
