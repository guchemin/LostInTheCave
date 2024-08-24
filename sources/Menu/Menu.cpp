#include "../../include/Menu/Menu.hpp"

Menu::Menu::Menu(sf::Vector2f tamB, Estados::EstadoID id, string ttl):
Ente(),
Estado(id),
listaBotoes(),
it(),
titulo(),
tamBotoes(tamB),
obs(this)
{
    titulo.setInfo(ttl);
    titulo.setTamanhoFonte(128);
    titulo.setCor(sf::Color::White);
    titulo.setPos(sf::Vector2f(pGraf->getCentro().x - titulo.getTamanho().x / 2.0f, 50.0f));
    ativo = false;
    remover = false;
}

Menu::Menu::Menu()
{
}

Menu::Menu::~Menu()
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

const bool Menu::Menu::getAtivo() const
{
    return ativo;
}

void Menu::Menu::setAtivo(bool atv)
{
    ativo = atv;
}

void Menu::Menu::adicionarBotao(string texto, sf::Vector2f pos, TipoBotao tp)
{
    Botao* pBotao = new Botao(texto, pos, tp);
    if(pBotao)
    {
        listaBotoes.push_back(pBotao);
    }
}

void Menu::Menu::irParaCima()
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

void Menu::Menu::irParaBaixo()
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

void Menu::Menu::inicializarBotoes()
{
    it = listaBotoes.begin();
    if(it != listaBotoes.end())
    {
        (*it)->setSelecionado(true);
    }
}

const TipoBotao Menu::Menu::getBotaoSelecionado()
{
    return (*it)->getTipo();
}

void Menu::Menu::desenhar()
{
    vector<Botao*>::iterator iterador = listaBotoes.begin();
    while(iterador != listaBotoes.end())
    {
        (*iterador)->desenhar();
        iterador++;
    }
    titulo.desenhar();
}

void Menu::Menu::executar()
{
    setAtivo(true);
    pGraf->limpar();
    desenhar();
}