#pragma once

#include "Entidades/Personagem/Jogador.hpp"
#include "Entidades/Personagem/Voador.hpp"
#include "Entidades/Personagem/Chefao.hpp"
#include "Entidades/Personagem/Atirador.hpp"
#include "Entidades/Obstaculos/Teia.hpp"
#include "Entidades/Obstaculos/Espinho.hpp"
#include "Fases/FaseUm.hpp"

class Principal
{
private:
    Gerenciadores::GerenciadorGrafico* pGraf;

    Fases::FaseUm fase;
    
public:
    Principal();
    ~Principal();
    
    void executar();
};