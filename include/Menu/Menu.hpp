#pragma once

#include "../Ente.hpp"
#include "../Estados/Estado.hpp"
#include "Botao/Botao.hpp"
#include "../Observadores/ObsMenu.hpp"
#include <string>
#include <vector>

using namespace std;

namespace Menu
{
    class Menu : public Ente, public Estados::Estado
    {
    protected:
        vector<Botao*> listaBotoes;
        vector<Botao*>::iterator it;
        sf::Vector2f tamBotoes;
        Texto titulo;
        Observadores::ObsMenu obs;
        bool ativo;
        bool remover;

    public:
        Menu(sf::Vector2f tamB, Estados::EstadoID id, string ttl);
        Menu();
        virtual ~Menu();

        const bool getAtivo() const;
        void setAtivo(bool atv);
        void adicionarBotao(string texto, sf::Vector2f pos, TipoBotao tp);
        void irParaCima();
        void irParaBaixo();
        void inicializarBotoes();
        const TipoBotao getBotaoSelecionado();
        void desenhar();
        virtual void selecionar(TipoBotao tipo) = 0;
        virtual void executar();
    };
}