/*
GerenciadorArquivos.hpp
----------------------------------------------------
 * Classe usada para manipular arquivos ao longo do código
 * Inspirado em: https://github.com/Giovanenero/JogoPlataforma2D-Jungle
*/

#pragma once 

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

namespace Gerenciadores 
{
    class GerenciadorArquivos
    {
        private:
            ifstream leitura;
            ofstream gravar;

        public:
        
            GerenciadorArquivos();
            ~GerenciadorArquivos();
            
            vector<string> lerArquivo(const char* caminho);
            void gravarCont(const char* caminho, std::vector<std::string> linhas);
            void gravarCont(const char* caminho, const std::string linha);
            void removerArquivo(const char* caminho);
            void abrirLeitura(const char* caminho);
            void fecharLeitura();
            void abrirGravar(const char* caminho);
            void fechaGravar();
    };
}