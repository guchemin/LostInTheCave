#pragma once

#include "Gerenciadores/Graficos.hpp"

class Ente
{
protected:
    Gerenciadores::Graficos* pGraf;

public:
    Ente();
    virtual ~Ente();

    virtual void atualizar(float dt) = 0;
};