#include "../../include/Menu/MenuJogar.hpp"
#include "../../include/Gerenciadores/GerenciadorEstados.hpp"

Menu::MenuJogar::MenuJogar(Estados::EstadoID faseID):
Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), faseID, "LOST IN THE CAVE")
{
    criarBotoes();
    if(faseID == Estados::EstadoID::MenuJogarUm)
    {
        cenario = pGraf->carregarTextura(BACKGROUND_FASE1);
    }
    else if(faseID == Estados::EstadoID::MenuJogarDois)
    {
        cenario = pGraf->carregarTextura(BACKGROUND_FASE1);
        background.setFillColor(sf::Color(230, 140, 255));
    }
    background.setTexture(&cenario);
    // texturaFundoUmJog = pGraf->carregarTextura(BACKGROUND_UM_JOGADOR);
    // texturaFundoDoisJog = pGraf->carregarTextura(BACKGROUND_DOIS_JOGADORES);
}

Menu::MenuJogar::~MenuJogar()
{
}

void Menu::MenuJogar::mudarBackground(TipoBotao tipo)
{
    switch (tipo)
    {
    case TipoBotao::UM_JOGADOR:
    {
        // background.setTexture(&texturaFundoUmJog);
        background.setFillColor(sf::Color::Red);
        break;
    }

    case TipoBotao::DOIS_JOGADORES:
    {
        // background.setTexture(&texturaFundoDoisJog);
        background.setFillColor(sf::Color::Blue);
        break;
    }
    
    default:
        break;
    }
}

void Menu::MenuJogar::criarBotoes() 
{
    float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
    float posY = pGraf->getCentro().y - tamBotoes.y;

    adicionarBotao("1 JOGADOR", sf::Vector2f(posX, posY), TipoBotao::UM_JOGADOR);
    adicionarBotao("2 JOGADORES", sf::Vector2f(posX, posY + tamBotoes.y * 1.2f), TipoBotao::DOIS_JOGADORES);
    adicionarBotao("VOLTAR", sf::Vector2f(posX, posY + tamBotoes.y * 2.4f), TipoBotao::VOLTAR);
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
            if(getEstadoID() == Estados::EstadoID::MenuJogarUm)
            {
                pEstados->adicionar(Estados::EstadoID::FaseUm);
            }
            else if(getEstadoID() == Estados::EstadoID::MenuJogarDois)
            {
                pEstados->adicionar(Estados::EstadoID::FaseDois);
            }
            setAtivo(false);
            Estado* est = pEstados->getEstadoAtual();
            est->setDoisJogadores(false);
            est = NULL;
            remover = true;
            break;
        }

        case TipoBotao::DOIS_JOGADORES:
        {
            if(getEstadoID() == Estados::EstadoID::MenuJogarUm)
            {
                pEstados->adicionar(Estados::EstadoID::FaseUm);
            }
            else if (getEstadoID() == Estados::EstadoID::MenuJogarDois)
            {
                pEstados->adicionar(Estados::EstadoID::FaseDois);
            }
            setAtivo(false);
            Estado* est = pEstados->getEstadoAtual();
            est->setDoisJogadores(true);
            est = NULL;
            remover = true;
            break;
        }

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

void Menu::MenuJogar::executar()
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
