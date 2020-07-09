
#ifndef ANIMACAO_H
#define ANIMACAO_H

#include "CObjeto.h"

class CTimer;

class CAnimacao : public CObjeto
{
    typedef struct
    {
        int loop;
        int qtdFrames;
        int frames[MAX_FRAMES_MODO];
        float delays[MAX_FRAMES_MODO];
    } Modo;

private:
    int souCopia;
    int qtdTotalFrames;
    Modo *modos[MAX_MODOS];
    int frameDoModo;
    SDL_Rect *frames[MAX_FRAMES];
    CTimer *tempoFrame;
    int idTimer;
    int offx,offy;
    int modoAtual;
    int frameAtual;

public:

    CAnimacao(int px,int py, SDL_Renderer* renderizador,char *nomeArq,int usaGerenciadorTimer=0,int retiraFundo=1,int opacidade=255);
    CAnimacao(int px,int py, CAnimacao* base,int usaGerenciadorTimer=0);
    ~CAnimacao();

    void CriaFrame(int codFrame,int x,int y,int altura,int largura);
    void CriaModo(int idModo, int loop);
    void InsereFrame(int idModo, int idFrame, float delayFrame);
    void MudaModo(int idModo,int inicia);
    int Desenha();
};

typedef CAnimacao* Animacao;

#endif
