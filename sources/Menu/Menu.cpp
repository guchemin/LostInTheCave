#include "../../include/Menu/Menu.hpp"

namespace Estados
{
    namespace Menu
    {
        Menu::Menu(sf::Vector2f tamB, Estados::EstadoID id, string ttl):
        Ente(),
        Estado(id),
        listaBotoes(),
        it(),
        titulo(),
        tamBotoes(tamB),
        obs(this)
        {
            background.setSize(pGraf->getTamanho());
            background.setPosition(0.0f, 0.0f);
            titulo.setInfo(ttl);
            titulo.setTamanhoFonte(128);
            titulo.setCor(sf::Color::White);
            titulo.setPos(sf::Vector2f(pGraf->getCentro().x - titulo.getTamanho().x / 2.0f, 50.0f));
            ativo = false;
            remover = false;
        }

        Menu::Menu()
        {
        }

        Menu::~Menu()
        {
            it = listaBotoes.begin();
            while (it != listaBotoes.end())
            {
                if(*it)
                {
                    delete (*it);
                    (*it) = NULL;
                }
                it++;
            }
            listaBotoes.clear();
        }

        const bool Menu::getAtivo() const
        {
            return ativo;
        }

        void Menu::centralizar()
        {
            background.setPosition(pGraf->getCentro() - pGraf->getTamanho() / 2.0f);
            titulo.setPos(sf::Vector2f(pGraf->getCentro().x - titulo.getTamanho().x / 2.0f, 50.0f));
            float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
            vector<Botao*>::iterator iterador = listaBotoes.begin();
            while(iterador != listaBotoes.end())
            {
                (*iterador)->setPosicao(sf::Vector2f(posX, (*iterador)->getPosicao().y));
                iterador++;
            }
        }

        void Menu::setAtivo(bool atv)
        {
            ativo = atv;
        }

        void Menu::adicionarBotao(string texto, sf::Vector2f pos, TipoBotao tp)
        {
            Botao* pBotao = new Botao(pos, tp, texto);
            if(pBotao)
            {
                listaBotoes.push_back(pBotao);
            }
        }

        void Menu::irParaCima()
        {
            Botao* pBotao = *it;
            if(pBotao)
            {
                pBotao->setSelecionado(false);
                if(it == listaBotoes.begin())
                {
                    it = listaBotoes.end();
                }
                it--;
                pBotao = *it;
                pBotao->setSelecionado(true);
            }
        }

        void Menu::irParaBaixo()
        {
            Botao* pBotao = *it;
            if(pBotao)
            {
                pBotao->setSelecionado(false);
                it++;
                if(it == listaBotoes.end())
                {
                    it = listaBotoes.begin();
                }
                pBotao = *it;
                pBotao->setSelecionado(true);
            }
        }

        void Menu::inicializarBotoes()
        {
            it = listaBotoes.begin();
            if(it != listaBotoes.end())
            {
                (*it)->setSelecionado(true);
            }
        }

        const TipoBotao Menu::getBotaoSelecionado()
        {
            return (*it)->getTipo();
        }

        void Menu::desenhar()
        {
            pGraf->desenhar(background);
            vector<Botao*>::iterator iterador = listaBotoes.begin();
            while(iterador != listaBotoes.end())
            {
                (*iterador)->desenhar();
                iterador++;
            }
            titulo.desenhar();
        }
    }
}
