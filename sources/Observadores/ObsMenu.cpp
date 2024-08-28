#include "../../include/Observadores/ObsMenu.hpp"
#include "../../include/Menu/Menu.hpp"
#include "../../include/Menu/MenuSalvarPontuacao.hpp"

namespace Observadores
{
    ObsMenu::ObsMenu(Estados::Menu::Menu *pM):
    Observador(),
    pMenu(pM)
    {
        cima = sf::Keyboard::Key::Up;
        baixo = sf::Keyboard::Key::Down;
        enter = sf::Keyboard::Key::Enter;

        if(pMenu->getEstadoID() == Estados::EstadoID::MenuJogarUm || 
        pMenu->getEstadoID() == Estados::EstadoID::MenuJogarDois ||
        pMenu->getEstadoID() == Estados::EstadoID::MenuColocacao ||
        pMenu->getEstadoID() == Estados::EstadoID::MenuSalvarPontuacao)
        {
            podeSelecionar = false;
        }
        else
        {
            podeSelecionar = true;
        }
    }

    ObsMenu::ObsMenu():
    Observador()
    {
    }

    ObsMenu::~ObsMenu()
    {
        pMenu = NULL;
    }

    void ObsMenu::notificarPressionada(const sf::Keyboard::Key tecla)
    {
        if(!pMenu->getAtivo())
            return;

        if(tecla == cima)
        {
            pMenu->irParaCima();
        }
        else if(tecla == baixo)
        {
            pMenu->irParaBaixo();
        }
        else if(tecla == enter && podeSelecionar)
        {
            pMenu->selecionar(pMenu->getBotaoSelecionado());
        }
    }

    void ObsMenu::notificarSolta(const sf::Keyboard::Key tecla)
    {
        if(tecla == enter)
        {
            podeSelecionar = true;
        }

        if(pMenu->getEstadoID() == Estados::EstadoID::MenuSalvarPontuacao && 
        pEstados->getEstadoAtual()->getEstadoID() == Estados::EstadoID::MenuSalvarPontuacao)
        {
            if(tecladoEspecial[tecla] == "Backspace")
            {
                Estados::Menu::MenuSalvarPontuacao* m = dynamic_cast<Estados::Menu::MenuSalvarPontuacao*>(pMenu);
                m->removerCaracter();
            }
            else 
            {
                std::map <sf::Keyboard::Key,std::string> :: iterator it = teclado.find(tecla);
                if (it == teclado.end())
                    return;
                Estados::Menu::MenuSalvarPontuacao* m = dynamic_cast<Estados::Menu::MenuSalvarPontuacao*>(pMenu);
                m->adicionarCaracter(it->second);
                // for(int i = 97; i < 123; i++)
                // {
                //     if(keys == i)
                //     {
                //         Menu::MenuSalvarPontuacao* m = dynamic_cast<Menu::MenuSalvarPontuacao*>(pMenu);
                //         m->adicionarCaracter(teclado[tecla]);
                //         break;
                //     }
                // }
                // for(int i = 48; i < 58; i++)
                // {
                //     if(teclado[tecla] == i)
                //     {
                //         cout << i << endl;
                //         Menu::MenuSalvarPontuacao* m = dynamic_cast<Menu::MenuSalvarPontuacao*>(pMenu);
                //         m->adicionarCaracter(teclado[tecla]);
                //         break;
                //     }
                // }
            }
        }
    }
}