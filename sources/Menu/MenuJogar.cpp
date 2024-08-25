#include "../../include/Menu/MenuJogar.hpp"
#include "../../include/Gerenciadores/GerenciadorEstados.hpp"

Menu::MenuJogar::MenuJogar():
Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuJogar, "LOST IN THE CAVE")
{
    criarBotoes();
}

Menu::MenuJogar::~MenuJogar()
{
}

void Menu::MenuJogar::criarBotoes()
{
    float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
    float posY = pGraf->getCentro().y - tamBotoes.y;

    adicionarBotao("1 JOGADOR", sf::Vector2f(posX, posY), TipoBotao::UM_JOGADOR);
    adicionarBotao("2 JOGADORES", sf::Vector2f(posX, posY + tamBotoes.y * 1.5f), TipoBotao::DOIS_JOGADORES);
    inicializarBotoes();
}

void Menu::MenuJogar::selecionar(TipoBotao tipo)
{
    if(ativo)
    {
        switch (tipo)
        {
        case TipoBotao::UM_JOGADOR:
        {
            pEstados->adicionar(Estados::EstadoID::FaseUm);
            setAtivo(false);
            Estado* est = pEstados->getEstadoAtual();
            est->setDoisJogadores(false);
            est = NULL;
            break;
        }

        case TipoBotao::DOIS_JOGADORES:
        {
            pEstados->adicionar(Estados::EstadoID::FaseUm);
            setAtivo(false);
            Estado* est = pEstados->getEstadoAtual();
            est->setDoisJogadores(true);
            est = NULL;
            break;
        }
        
        default:
            break;
        }
    }
}
