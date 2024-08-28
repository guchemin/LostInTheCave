#pragma once

#include "Menu.hpp"
#include "../Fases/Fase.hpp"
#include "../Gerenciadores/GerenciadorArquivos.hpp"

namespace Menu
{
    class MenuSalvarPontuacao : public Menu
    {
    private:
        Gerenciadores::GerenciadorArquivos gArquivo;
        Fases::Fase* fase;
        Texto nomeTexto;
        std::string nomeString;
        sf::Font fonte;

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