/*
Menu.hpp - Filha de Ente e Estado - Classe Abstrata
----------------------------------------------------
 * Inspirado em: https://github.com/MatheusBurda/Desert
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
            bool ativo;
            Observadores::ObsMenu obs;

        protected:
            void centralizar();
            virtual void criarBotoes() = 0;
            void adicionarBotao(string texto, sf::Vector2f pos, TipoBotao tp);
            void inicializarBotoes();

        public:
            Menu(sf::Vector2f tamB, Estados::EstadoID id, string ttl);
            Menu();
            virtual ~Menu();

            const bool getAtivo() const;
            void setAtivo(bool atv);
            void irParaCima();
            void irParaBaixo();
            const TipoBotao getBotaoSelecionado() const;
            virtual void selecionar(TipoBotao tipo) = 0;
            virtual void executar() = 0;
            
            void executar(const float dt);
            void desenhar();
        };
    }
}