#include "../../include/Menu/MenuColocacao.hpp"

Menu::MenuColocacao::MenuColocacao():
Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuColocacao, "LEADERBOARD")
{
    texturaFundo = pGraf->carregarTextura("../assets/sprites/Backgrounds/Background1.png");
    background.setTexture(&texturaFundo);
    criarBotoes();
}

Menu::MenuColocacao::~MenuColocacao()
{
}

void Menu::MenuColocacao::criarBotoes()
{
    float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
    float posY = pGraf->getCentro().y - tamBotoes.y;

    adicionarBotao("VOLTAR", sf::Vector2f(posX, posY + tamBotoes.y * 4.0f), TipoBotao::VOLTAR);
    inicializarBotoes();
}

void Menu::MenuColocacao::selecionar(TipoBotao tipo)
{
    if(ativo)
    {
        switch (tipo)
        {
        case TipoBotao::VOLTAR:
        {
            remover = true;
            break;
        }

        default:
            break;
        }
    }
}

void Menu::MenuColocacao::executar()
{
    if(remover)
    {
        pEstados->remover();
    }
    else
    {
        setAtivo(true);
        desenhar();
    }
}