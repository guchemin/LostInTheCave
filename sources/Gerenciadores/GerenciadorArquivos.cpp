#include "../../include/Gerenciadores/GerenciadorArquivos.hpp"

Gerenciadores::GerenciadorArquivos::GerenciadorArquivos():
leitura(),
gravar()
{
}

Gerenciadores::GerenciadorArquivos::~GerenciadorArquivos()
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

vector<string> Gerenciadores::GerenciadorArquivos::lerArquivo(const char *caminho)
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

void Gerenciadores::GerenciadorArquivos::gravarCont(const char *caminho, std::vector<std::string> linhas)
{
    abrirGravar(caminho);
    for(int i = 0; i < linhas.size(); i++)
    {
        gravar << linhas[i] << " " << endl;
    }
    
    fechaGravar();
}

void Gerenciadores::GerenciadorArquivos::gravarCont(const char *caminho, const std::string linha)
{
    abrirGravar(caminho);
    const char quebrarLinha = 10;
    gravar << linha << " " << quebrarLinha;
    fechaGravar(); 
}

void Gerenciadores::GerenciadorArquivos::removerArquivo(const char *caminho)
{
    remove(caminho);
}

void Gerenciadores::GerenciadorArquivos::abrirLeitura(const char *caminho)
{
    leitura.open(caminho);
    if(!leitura.is_open())
    {
        cout << "Erro ao abrir o arquivo " << caminho << endl;
    }
}

void Gerenciadores::GerenciadorArquivos::fecharLeitura()
{
    leitura.close();
}

void Gerenciadores::GerenciadorArquivos::abrirGravar(const char *caminho)
{
    gravar.open(caminho);
    if(!gravar.is_open())
    {
        cout << "Erro ao abrir o arquivo " << caminho << endl;
    }
}

void Gerenciadores::GerenciadorArquivos::fechaGravar()
{
    gravar.close();
}
