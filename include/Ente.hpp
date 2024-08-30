/*
Ente.hpp - Classe Abstrata
----------------------------------------------------
 * Classe base do jogo.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "json/json.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "Gerenciadores/GerenciadorGrafico.hpp"

class Ente
{
protected:
    Gerenciadores::GerenciadorGrafico* pGraf;
    static int contId;
    const int id;

public:
    Ente();
    virtual ~Ente();

    virtual void executar(const float dt) = 0;
    virtual void desenhar() = 0;
};