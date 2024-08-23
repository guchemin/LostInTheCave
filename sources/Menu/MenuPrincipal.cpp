#include "../../include/Menu/MenuPrincipal.hpp"
#include "../../include/Gerenciadores/GerenciadorEstados.hpp"

Menu::MenuPrincipal::MenuPrincipal():
Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuPrincipal, "LOST IN THE CAVE")
{
    criarBotoes();
}

Menu::MenuPrincipal::~MenuPrincipal()
{
}

void Menu::MenuPrincipal::criarBotoes()
{
    float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
    float posY = pGraf->getCentro().y - tamBotoes.y;

    adicionarBotao("FASE 1", sf::Vector2f(posX, posY), TipoBotao::FASE_1);
    adicionarBotao("TESTE", sf::Vector2f(posX, posY + tamBotoes.y * 1.5f), TipoBotao::SAIR);
    adicionarBotao("SAIR", sf::Vector2f(posX, posY + tamBotoes.y * 3.0f), TipoBotao::SAIR);
    inicializarBotoes();
}

void Menu::MenuPrincipal::selecionar(TipoBotao tipo)
{
    switch (tipo)
    {
    case TipoBotao::FASE_1:
    {
        pEstados->adicionar(Estados::EstadoID::MenuJogar);
        setAtivo(false);
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