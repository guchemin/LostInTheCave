#include "../../include/Gerenciadores/GerenciadorEstados.hpp"
#include "../../include/Fases/FaseUm.hpp"
#include "../../include/Menu/MenuPrincipal.hpp"
#include "../../include/Menu/MenuJogar.hpp"
#include "../../include/Menu/MenuPausa.hpp"
#include "../../include/Menu/MenuColocacao.hpp"
#include "../../include/Menu/MenuFim.hpp"
#include "../../include/Menu/MenuSalvarPontuacao.hpp"

namespace Gerenciadores
{
    // padrao Singleton
    GerenciadorEstados* GerenciadorEstados::instancia = NULL;

    GerenciadorEstados *GerenciadorEstados::getInstancia()
    {
        if(instancia == NULL)
        {
            instancia = new GerenciadorEstados();
        }
        return instancia;
    }

    GerenciadorEstados::GerenciadorEstados():
    estados()
    {
    }

    GerenciadorEstados::~GerenciadorEstados()
    {
        while(!estados.empty())
        {
            if(estados.top())
                delete(estados.top());
            estados.top() = NULL;
            estados.pop();
        }
    }

    void GerenciadorEstados::executar()
    {
        if(estados.empty())
        {
            return;
        }
        estados.top()->executar();
    }

    void GerenciadorEstados::adicionar(Estados::EstadoID estadoID)
    {
        switch(estadoID)
        {
        case Estados::EstadoID::FaseUm:
        {
            Estados::Fases::FaseUm* fase = new Estados::Fases::FaseUm();
            Estados::Estado* est = static_cast<Estados::Estado*>(fase);
            estados.push(est);
            break;
        }

        // ------------------- MUDAR PARA FASE DOIS
        case Estados::EstadoID::FaseDois:
        {
            Estados::Fases::FaseUm* fase = new Estados::Fases::FaseUm();
            Estados::Estado* est = static_cast<Estados::Estado*>(fase);
            estados.push(est);
            break;
        }

        case Estados::EstadoID::MenuPrincipal:
        {
            Estados::Menu::MenuPrincipal* menu = new Estados::Menu::MenuPrincipal();
            Estados::Estado* est = static_cast<Estados::Estado*>(menu);
            estados.push(est);
            break;
        }

        case Estados::EstadoID::MenuJogarUm:
        {
            Estados::Menu::MenuJogar* menuJogar = new Estados::Menu::MenuJogar(Estados::EstadoID::MenuJogarUm);
            Estados::Estado* est = static_cast<Estados::Estado*>(menuJogar);
            estados.push(est);
            break;
        }

        case Estados::EstadoID::MenuJogarDois:
        {
            Estados::Menu::MenuJogar* menuJogar = new Estados::Menu::MenuJogar(Estados::EstadoID::MenuJogarDois);
            Estados::Estado* est = static_cast<Estados::Estado*>(menuJogar);
            estados.push(est);
            break;
        }

        case Estados::EstadoID::MenuPausa:
        {
            Estados::Fases::Fase* pFase = static_cast<Estados::Fases::Fase*>(estados.top());
            Estados::Menu::MenuPausa* menuPausa = new Estados::Menu::MenuPausa(pFase);
            Estados::Estado* est = static_cast<Estados::Estado*>(menuPausa);
            estados.push(est);
            break;
        }

        case Estados::EstadoID::MenuFim:
        {
            Estados::Fases::Fase* pFase = static_cast<Estados::Fases::Fase*>(estados.top());
            Estados::Menu::MenuFim* menuFim = new Estados::Menu::MenuFim(pFase);
            Estados::Estado* est = static_cast<Estados::Estado*>(menuFim);
            estados.push(est);
            break;
        }

        case Estados::EstadoID::MenuColocacao:
        {
            Estados::Menu::MenuColocacao* menuColocacao = new Estados::Menu::MenuColocacao();
            Estados::Estado* est = static_cast<Estados::Estado*>(menuColocacao);
            estados.push(est);
            break;
        }

        case Estados::EstadoID::MenuSalvarPontuacao:
        {
            if(estados.top()->getEstadoID() == Estados::EstadoID::MenuFim)
            {
                Estados::Menu::MenuFim* pMenuFim = static_cast<Estados::Menu::MenuFim*>(estados.top());
                Estados::Fases::Fase* pFase = pMenuFim->getFase();
                Estados::Menu::MenuSalvarPontuacao* menuSalvarPontuacao = new Estados::Menu::MenuSalvarPontuacao(pFase);
                Estados::Estado* est = static_cast<Estados::Estado*>(menuSalvarPontuacao);
                estados.push(est);
            }
            else if(estados.top()->getEstadoID() == Estados::EstadoID::FaseUm || estados.top()->getEstadoID() == Estados::EstadoID::FaseDois)
            {
                Estados::Fases::Fase* pFase = static_cast<Estados::Fases::Fase*>(estados.top());
                Estados::Menu::MenuSalvarPontuacao* menuSalvarPontuacao = new Estados::Menu::MenuSalvarPontuacao(pFase);
                Estados::Estado* est = static_cast<Estados::Estado*>(menuSalvarPontuacao);
                estados.push(est);
            }
            break;
        }
        
        default:
            break;
        }
    }

    void GerenciadorEstados::remover()
    {
        if(estados.top())
        {
            delete(estados.top());
            estados.top() = NULL;
            estados.pop();
        }
        if(estados.empty())
        {
            GerenciadorGrafico* pGraf = GerenciadorGrafico::getInstancia();
            pGraf->fecharJanela();
        }
    }

    Estados::Estado *GerenciadorEstados::getEstadoAtual()
    {
        return estados.top();
    }
}