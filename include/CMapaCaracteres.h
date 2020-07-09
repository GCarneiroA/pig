
#ifndef MAPACARACTERES_H
#define MAPACARACTERES_H

#include <SDL2/SDL.h>
#include "COffscreenRenderer.h"
#include "Tipos_PIG.h"

class CMapaCaracteres
{
private:
    int *alturaLetra;
    int *larguraLetra;

    SDL_Renderer *render;
    SDL_Texture **glyphsT;

public:
    char nome[100];
    int tamFonte;

    CMapaCaracteres(char *nomeFonte,SDL_Renderer* renderer,int tamanhoFonte,int estilo, PIG_Cor corFonte,int outline,PIG_Cor corOutline);
    CMapaCaracteres(char *nomeFonte,SDL_Renderer* renderer,int tamanhoFonte,int estilo, char *fundoFonte,int outline,PIG_Cor corOutline);
    ~CMapaCaracteres();
    int GetLarguraPixelsString(char *str);
    void EscreveStringCentralizado(char *str,int x,int y);
    void EscreveStringEsquerda(char *str,int x,int y);
    void EscreveStringDireita(char *str,int x,int y);
};

typedef CMapaCaracteres* MapaCaracteres;

#endif
