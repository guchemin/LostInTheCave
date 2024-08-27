#pragma once

#include "Texto.hpp"
#include "../../Ente.hpp"

#define TAMANHO_BOTAO_X 300
#define TAMANHO_BOTAO_Y 100

enum TipoBotao
{
    FASE_1,
    FASE_2,
    CARREGAR,
    LEADERBOARD,
    UM_JOGADOR,
    DOIS_JOGADORES,
    JOGAR_FASE2,
    SAIR,
    CONTINUAR,
    VOLTAR,
    VOLTAR_MENU,
    SALVAR,
    SALVAR_PONTUACAO,
    CONFIRMAR,
};

class Botao : public Ente
{
private:
    TipoBotao tipo;
    Texto texto;
    sf::Texture texturaPadrao;
    sf::Texture texturaSelecionado;
    sf::RectangleShape corpo;

public:
    Botao(string txt, sf::Vector2f pos, TipoBotao tp);
    Botao();
    ~Botao();

    TipoBotao getTipo();
    void setSelecionado(const bool selecionado);
    void desenhar();
};

