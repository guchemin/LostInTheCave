#pragma once

#include "Entidades/Jogador/Jogador.hpp"
#include "Entidades/Plataforma/Plataforma.hpp"
#include "Gerenciadores/Graficos.hpp"
#include "Listas/ListaEntidades.hpp"

class Principal
{
private:
    Gerenciadores::Graficos* pGraf;
    Listas::ListaEntidades* listaJogadores;
    Listas::ListaEntidades* listaPlataformas;
    Jogador::Jogador* jogador1;
    Jogador::Jogador* jogador2;
    Plataforma::Plataforma* plataforma1;
    
public:
    Principal();
    ~Principal();

    void inicializar();
    void atualizar();
    void executar();
};