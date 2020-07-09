
#ifndef OFFSCREEN_H
#define OFFSCREEN_H

#include <SDL2/SDL.h>
#include "CPilhaCoordenada.h"
#include "Tipos_PIG.h"

class COffscreenRenderer
{
private:
    SDL_Renderer *render;
    SDL_Surface *surface;
    int alt;
    int larg;

public:

    SDL_Renderer *GetRenderer();
    SDL_Surface *GetSurface();
    int GetAltura();
    int GetLargura();
    COffscreenRenderer(int altura,int largura);
    void PintarFundo(SDL_Color cor);
    void PintarArea(int px,int py,PIG_Cor cor);
    void DesenharLinha(int x1,int y1,int x2,int y2,PIG_Cor cor);
    void DesenharRetangulo(int x,int y,int altura,int largura,PIG_Cor cor);
    void DesenharRetanguloVazado(int x,int y,int altura,int largura,PIG_Cor cor);
    void SalvarImagem(char *nomearq);
    ~COffscreenRenderer();
};

#endif
