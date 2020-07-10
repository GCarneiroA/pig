
#ifndef GERADOR_ANIMACOES_H
#define GERADOR_ANIMACOES_H

#include "CAnimacao.h"
#include "CPoolNumeros.h"

class CGerenciadorAnimacoes
{
private:
    static SDL_Renderer *render;
    static int totalAnimacoes;
    static PoolNumeros numAnimacoes;
    static Animacao animacoes[MAX_ANIMACOES];

public:
    static Animacao GetAnimacao(int id_animacao);
    static void Inicia(SDL_Renderer *renderer);
    static void Encerra();
    static int CriaAnimacao(char* nomeArquivoBMP,int retiraFundo=1,int opacidade=255);
    static int CriaAnimacao(int id_animacaoBase);
    static void DestroiAnimacao(int id_animacao);
    inline static void Move(int id_animacao,int px,int py);
    inline static void GetPosicaoXY(int id_animacao, int *x,int *y);
    inline static int Desenha(int id_animacao);
    inline static void CriaFrame(int id_animacao,int codFrame,int x,int y,int altura,int largura);
    inline static void CriaModo(int id_animacao,int idModo, int loop);
    inline static void InsereFrame(int id_animacao, int idModo,int idFrame, float delayFrame);
    inline static void MudaModo(int id_animacao,int idModo,int inicia);
    inline static void SetOpacidade(int id_animacao,int valor);
    inline static void SetColoracao(int id_animacao,PIG_Cor cor);
    inline static void SetPivo(int id_animacao,int x,int y);
    inline static void GetPivo(int id_animacao,int *x,int *y);
    inline static void SetAngulo(int id_animacao,float valor);
    inline static float GetAngulo(int id_animacao);
    inline static int ColisaoAnimacoes(int id_animacao1,int id_animacao2);
    inline static int ColisaoObjeto(int id_animacao, CObjeto *obj);
    inline static void SetDimensoes(int id_animacao,int altura,int largura);
    inline static void GetDimensoes(int id_animacao,int *altura,int *largura);
    inline static void SetValorInt(int id_animacao,int indice,int valor);
    inline static int GetValorInt(int id_animacao,int indice);
    inline static void SetValorFloat(int id_animacao,int indice,float valor);
    inline static float GetValorFloat(int id_animacao,int indice);
};

#endif
