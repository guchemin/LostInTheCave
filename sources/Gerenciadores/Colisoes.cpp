#include "../../include/Gerenciadores/Colisoes.hpp"

Gerenciadores::Colisoes::Colisoes(Listas::ListaEntidades *lPersonagem, Listas::ListaEntidades *lPlataforma):
listaPersonagem(lPersonagem),
listaPlataforma(lPlataforma)
{
}

Gerenciadores::Colisoes::~Colisoes()
{
    listaPersonagem = NULL;
    listaPlataforma = NULL;
}

void Gerenciadores::Colisoes::verificarColisoes()
{
}