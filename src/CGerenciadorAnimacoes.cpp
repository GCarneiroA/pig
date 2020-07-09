
#include "CGerenciadorAnimacoes.h"

Animacao CGerenciadorAnimacoes::GetAnimacao(int id_animacao)
{
    return animacoes[id_animacao];
}

void CGerenciadorAnimacoes::Inicia(SDL_Renderer *renderer)
{
    render = renderer;
    totalAnimacoes = 0;
    for (int i = 0; i < MAX_ANIMACOES; i++) {
        animacoes[i] = NULL;
    }
    numAnimacoes = new CPoolNumeros(MAX_ANIMACOES);
}

void CGerenciadorAnimacoes::Encerra()
{
    for (int i = 0; i < MAX_ANIMACOES; i++) {
        if (animacoes[i]) {
            delete animacoes[i];
        }
    }
    delete numAnimacoes;
}

int CGerenciadorAnimacoes::CriaAnimacao(char* nomeArquivoBMP, int retiraFundo, int opacidade)
{
    int resp = numAnimacoes->RetiraLivre();
    animacoes[resp] = new CAnimacao(0, 0, render, nomeArquivoBMP, opacidade, retiraFundo);
    totalAnimacoes++;
    return resp;
}

int CGerenciadorAnimacoes::CriaAnimacao(int id_animacaoBase)
{
    int resp = numAnimacoes->RetiraLivre();
    animacoes[resp] = new CAnimacao(0, 0, animacoes[id_animacaoBase]);
    totalAnimacoes++;
    return resp;
}

void CGerenciadorAnimacoes::DestroiAnimacao(int id_animacao)
{
    numAnimacoes->DevolveUsado(id_animacao);
    delete animacoes[id_animacao];
    totalAnimacoes--;
    animacoes[id_animacao] = NULL;
}

void CGerenciadorAnimacoes::Move(int id_animacao, int px, int py)
{
    animacoes[id_animacao]->Move(px, py);
}

void CGerenciadorAnimacoes::GetPosicaoXY(int id_animacao, int *x,int *y)
{
    animacoes[id_animacao]->GetXY(*x, *y);
}

int CGerenciadorAnimacoes::Desenha(int id_animacao)
{
    return animacoes[id_animacao]->Desenha();
}

void CGerenciadorAnimacoes::CriaFrame(int id_animacao,int codFrame,int x,int y,int altura,int largura)
{
    animacoes[id_animacao]->CriaFrame(codFrame, x, y, altura, largura);
}

void CGerenciadorAnimacoes::CriaModo(int id_animacao,int idModo, int loop)
{
    animacoes[id_animacao]->CriaModo(idModo, loop);
}

void CGerenciadorAnimacoes::InsereFrame(int id_animacao, int idModo,int idFrame, float delayFrame)
{
    animacoes[id_animacao]->InsereFrame(idModo, idFrame, delayFrame);
}

void CGerenciadorAnimacoes::MudaModo(int id_animacao,int idModo,int inicia)
{
    animacoes[id_animacao]->MudaModo(idModo, inicia);
}

void CGerenciadorAnimacoes::SetOpacidade(int id_animacao,int valor)
{
    animacoes[id_animacao]->SetOpacidade(valor);
}

void CGerenciadorAnimacoes::SetColoracao(int id_animacao,PIG_Cor cor)
{
    animacoes[id_animacao]->SetColoracao(cor);
}

void CGerenciadorAnimacoes::SetPivo(int id_animacao,int x,int y)
{
    animacoes[id_animacao]->SetPivo(x, y);
}

void CGerenciadorAnimacoes::GetPivo(int id_animacao,int *x,int *y)
{
    animacoes[id_animacao]->GetPivo(*x, *y);
}

void CGerenciadorAnimacoes::SetAngulo(int id_animacao,float valor)
{
    animacoes[id_animacao]->SetAngulo(valor);
}

float CGerenciadorAnimacoes::GetAngulo(int id_animacao)
{
    return animacoes[id_animacao]->GetAngulo();
}

int CGerenciadorAnimacoes::ColisaoAnimacoes(int id_animacao1, int id_animacao2)
{
    return animacoes[id_animacao1]->Colisao(animacoes[id_animacao2]);
}

int CGerenciadorAnimacoes::ColisaoObjeto(int id_animacao, CObjeto *obj)
{
    return animacoes[id_animacao]->Colisao(obj);
}

void CGerenciadorAnimacoes::SetDimensoes(int id_animacao,int altura,int largura)
{
    animacoes[id_animacao]->SetDimensoes(altura, largura);
}

void CGerenciadorAnimacoes::GetDimensoes(int id_animacao,int *altura,int *largura)
{
    animacoes[id_animacao]->GetDimensoes(*altura, *largura);
}

void CGerenciadorAnimacoes::SetValorInt(int id_animacao,int indice,int valor)
{
    animacoes[id_animacao]->valoresInt[indice] = valor;
}

int CGerenciadorAnimacoes::GetValorInt(int id_animacao,int indice)
{
    return animacoes[id_animacao]->valoresInt[indice];
}

void CGerenciadorAnimacoes::SetValorFloat(int id_animacao,int indice,float valor)
{
    animacoes[id_animacao]->valoresFloat[indice] = valor;
}

float CGerenciadorAnimacoes::GetValorFloat(int id_animacao,int indice)
{
    return animacoes[id_animacao]->valoresFloat[indice];
}
