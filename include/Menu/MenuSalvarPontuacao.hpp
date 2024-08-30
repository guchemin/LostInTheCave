/*
MenuSalvarPontuacao.hpp - Filha da classe Menu
*/

#pragma once

#include "Menu.hpp"
#include "../Fases/Fase.hpp"
#include "../Gerenciadores/GerenciadorArquivos.hpp"

namespace Estados
{
    namespace Menu
    {
        class MenuSalvarPontuacao : public Menu
        {
        private:
            Gerenciadores::GerenciadorArquivos gArquivo;
            Fases::Fase* fase;
            Texto nomeTexto;
            Texto pontuacaoTexto;
            std::string nomeString;
            sf::RectangleShape painel;

        public:
            MenuSalvarPontuacao(Fases::Fase* f);
            MenuSalvarPontuacao();
            ~MenuSalvarPontuacao();

            void alinharTexto();
            void criarBotoes();
            void adicionarCaracter(std::string c);
            void removerCaracter();
            void salvarColocacao();
            void selecionar(TipoBotao tipo);
            void executar();
        };
    }
}