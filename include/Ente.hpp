#pragma once

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

    virtual void executar(const float dt);
    virtual void desenhar() = 0;
};