/*
MenuColocacao.hpp - Filha da classe Menu
*/

#pragma once

#include "Menu.hpp"
#include "../Gerenciadores/GerenciadorArquivos.hpp"
#include <vector>
#include <string>
#include <sstream>

#define CAMINHO_ARQUIVO_COLOCACAO "../resources/leaderboard.txt"
#define BACKGROUNG_MENU_COLOCACAO "../assets/sprites/Backgrounds/Background1.png"

namespace Estados
{
    namespace Menu
    {
        class MenuColocacao : public Menu
        {
        private:
            sf::Texture texturaFundo;
            std::vector<Texto*> colocacoes;
            Gerenciadores::GerenciadorArquivos gArquivo;
            std::vector<std::pair<std::string, int>> leaderboard;

        private:
            void centralizarTexto();
            void criarBotoes();
            void criarTexto(const std::string& nome, int pontos);
            void criarColocacao();
            void desenharColocacao();
            
        public:
            MenuColocacao();
            ~MenuColocacao();

            void selecionar(TipoBotao tipo);
            void executar();
        };
    }
}