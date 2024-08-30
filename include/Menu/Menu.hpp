/*
Menu.hpp - Filha de Ente e Estado - Classe Abstrata
*/

#pragma once

#include "../Ente.hpp"
#include "../Estados/Estado.hpp"
#include "Botao/Botao.hpp"
#include "../Observadores/ObsMenu.hpp"
#include <string>
#include <vector>

using namespace std;

namespace Estados
{
    namespace Menu
    {
        class Menu : public Ente, public Estados::Estado
        {
        protected:
            sf::RectangleShape background;
            vector<Botao*> listaBotoes;
            vector<Botao*>::iterator it;
            sf::Vector2f tamBotoes;
            Texto titulo;
            Observadores::ObsMenu obs;
            bool ativo;

        public:
            Menu(sf::Vector2f tamB, Estados::EstadoID id, string ttl);
            Menu();
            virtual ~Menu();

            const bool getAtivo() const;
            void centralizar();
            void setAtivo(bool atv);
            virtual void criarBotoes() = 0;
            void adicionarBotao(string texto, sf::Vector2f pos, TipoBotao tp);
            void irParaCima();
            void irParaBaixo();
            void inicializarBotoes();
            const TipoBotao getBotaoSelecionado();
            virtual void selecionar(TipoBotao tipo) = 0;
            virtual void executar() = 0;
            void executar(const float dt);
            void desenhar();
        };
    }
}