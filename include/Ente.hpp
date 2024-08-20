#pragma once

#include <stdlib.h>
#include <time.h>
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

    virtual void atualizar(float dt) = 0;
    virtual void desenhar() = 0;
};