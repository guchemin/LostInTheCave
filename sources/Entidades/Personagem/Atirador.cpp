#include "../../../include/Entidades/Personagem/Atirador.hpp"

namespace Entidades
{
    namespace Personagem
    {
        Atirador::Atirador(sf::Vector2f pos):
        Inimigo(pos, sf::Vector2f(50.0f, 70.0f))
        {
            vel = sf::Vector2f(0.0f, 0.0f);
            pProjetil = NULL;
            raioAtaque = RAIO_ATIRADOR;
            tempoAtaque = 0.0f;
            vida = 60.0f;
            dano = DANO_ATIRADOR;

            inicializarAnimacao();
        }

        Atirador::Atirador()
        {
        }

        Atirador::~Atirador()
        {
            pProjetil = NULL;
        }

        void Atirador::inicializarAnimacao()
        {
            sf::Vector2f origem = sf::Vector2f(getTamanho().x / 3.5, getTamanho().y / 3.5);

            animacao.addAnimacao(CAMINHO_ATIRADOR_PARADO, "parado", 12, 0.07f, sf::Vector2f(2.4f, 1.8f), origem);
            animacao.addAnimacao(CAMINHO_ATIRADOR_ATACANDO, "atacando", 9, 0.05f, sf::Vector2f(2.4f, 1.8f), origem);
        }

        void Atirador::atualizarAnimacao()
        {
            if(atacando)
            {
                animacao.atualizar(direcao, "atacando");
            }
            else
            {
                animacao.atualizar(direcao, "parado");
            }
        }

        void Atirador::setProjetil(Projetil *proj) 
        {
            if(proj)
            {
                pProjetil = proj;
            }
        }


        bool Atirador::consegueAtacar()
        {
            // verifica cooldown
            if(tempoAtaque >= COOLDOWN_ATIRADOR)
            {
                if(pProjetil->getPosicao().x <= -800.0f && pProjetil->getPosicao().y <= -800.0f)
                {
                    iniciouAtaque = false;
                    tempoAtaque = 0.0f;
                    return true;
                }
            }
            return false;
        }

        void Atirador::atacar()
        {
            setAtacando(true);
            sf::Vector2f velProj = calcVel();
            sf::Vector2f posProj = sf::Vector2f(getCentro().x, getPosicao().y + getTamanho().y / 2.8f);
            pProjetil->setPosicao(posProj);
            pProjetil->setVelocidade(velProj);
        }

        void Atirador::agir()
        {
            if(pJogador->getPosicao().x > getPosicao().x)
            {
                direcao = true;
            }
            else
            {
                direcao = false;
            }

            if(consegueAtacar())
            {
                atacar();
            }
        }

        void Atirador::executar(const float dt)
        {
            if(atacando)
            {
                tempoAnimacaoAtaque += dt;
                if(tempoAnimacaoAtaque >= TEMPO_TOTAL_ATAQUE_ATIRADOR)
                {
                    atacando = false;
                    tempoAnimacaoAtaque = 0.0f;
                }
            }

            if(tomouDano)
            {
                tempoTomouDano += dt;
                corpo.setFillColor(sf::Color(255, 0, 0, 200));
                if(tempoTomouDano >= TEMPO_TOMOU_DANO)
                {
                    corpo.setFillColor(sf::Color(255, 255, 255, 255));
                    tomouDano = false;
                    tempoTomouDano = 0.0f;
                }
            }
            float dy;
            
            //acao da gravidade
            vel.y += GRAVIDADE * dt;
            dy = vel.y * dt;
            corpo.move(0.0f, dy);

            tempoAtaque += dt;
            
            if(pProjetil->saiuDaTela())
            {
                pProjetil->setPosicao(sf::Vector2f(-1000.0f, -1000.0f));
                pProjetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
            }

            atualizarAnimacao();
        }

        sf::Vector2f Atirador::calcVel()
        {
            if(pJogador == NULL)
            {
                return sf::Vector2f(0.0f, 0.0f);
            }
            
            float Dx;
            float Dy;
            float theta;
            sf::Vector2f velProj;

            if(pJogador->getCentro().x > getCentro().x)
            {    
                Dx = pJogador->getPosicao().x - getCentro().x;
            }
            else
            {    
                Dx = getCentro().x - (pJogador->getPosicao().x + pJogador->getTamanho().x);
            }
            
            Dy = (pJogador->getPosicao().y - pJogador->getTamanho().y / 5.0f) - (getPosicao().y + getTamanho().y / 2.0f);
            

            theta = atan(fabs(Dy / Dx));

            if(pJogador->getCentro().x > getCentro().x)
            {    
                velProj.x = VEL_PROJ * cos(theta);
            }
            else
            {
                velProj.x = -VEL_PROJ * cos(theta);
            }

            if(pJogador->getPosicao().y > getPosicao().y)
            {
                velProj.y = VEL_PROJ * sin(theta);
            }
            else
            {
                velProj.y = -VEL_PROJ * sin(theta);
            }
            return velProj;
        }

        float Atirador::getPontuacao()
        {
            return PONTUACAO_ATIRADOR;
        }
    }
}