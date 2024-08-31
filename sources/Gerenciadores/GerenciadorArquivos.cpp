#include "../../include/Gerenciadores/GerenciadorArquivos.hpp"

// feito com base no código do monitor Giovane: https://github.com/Giovanenero/JogoPlataforma2D-Jungle

namespace Gerenciadores
{
    GerenciadorArquivos::GerenciadorArquivos():
        leitura(),
        gravar()
    {
    }

    GerenciadorArquivos::~GerenciadorArquivos()
    {
        if(leitura.is_open())
        {
            leitura.close();
        }
        if(gravar.is_open())
        {
            gravar.close();
        }
    }

    vector<string> GerenciadorArquivos::lerArquivo(const char *caminho)
    {
        abrirLeitura(caminho);
        vector<string> linhas;
        string linha = "";
        while(getline(leitura, linha)){
            linhas.push_back(linha);
        }
        fecharLeitura();

        return linhas;
    }

    void GerenciadorArquivos::gravarCont(const char *caminho, std::vector<std::string> linhas)
    {
        abrirGravar(caminho);
        for(int i = 0; i < linhas.size(); i++)
        {
            gravar << linhas[i] << " " << endl;
        }
        
        fechaGravar();
    }

    void GerenciadorArquivos::gravarCont(const char *caminho, const std::string linha)
    {
        abrirGravar(caminho);
        const char quebrarLinha = 10;
        gravar << linha << " " << quebrarLinha;
        fechaGravar(); 
    }

    void GerenciadorArquivos::removerArquivo(const char *caminho)
    {
        remove(caminho);
    }

    void GerenciadorArquivos::abrirLeitura(const char *caminho)
    {
        leitura.open(caminho);
        if(!leitura.is_open())
        {
            cout << "Erro ao abrir o arquivo " << caminho << endl;
        }
    }

    void GerenciadorArquivos::fecharLeitura()
    {
        leitura.close();
    }

    void GerenciadorArquivos::abrirGravar(const char *caminho)
    {
        gravar.open(caminho, std::ios::app);  // Abrir em modo de append
        if(!gravar.is_open())
        {
            cout << "Erro ao abrir o arquivo " << caminho << endl;
        }
    }

    void GerenciadorArquivos::fechaGravar()
    {
        gravar.close();
    }
}