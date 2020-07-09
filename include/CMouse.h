
#ifndef MOUSE_H
#define MOUSE_H

#include <SDL2/SDL.h>
#include "Tipos_PIG.h"


typedef struct iC
{
    SDL_Surface *bitmap;
    SDL_Texture *text;
    char nomeArquivo[60];
} InfoCursor;

class CMouse
{
private:
    static int cursorAtual;
    static InfoCursor *cursores[MAX_CURSORES];
    static SDL_Rect rect;
    static SDL_Renderer *renderer;

public:
    static void Inicia(SDL_Renderer *render);
    static void Encerra();
    static void PegaXY(int &x, int &y);
    static void MudaCursor(int indice);
    static void Desenha();
    static void Move(int x, int y);
    static void CarregaCursor(int indice, char *nomeArquivo);
};

int CMouse::cursorAtual;
InfoCursor* CMouse::cursores[MAX_CURSORES];
SDL_Rect CMouse::rect;
SDL_Renderer* CMouse::renderer;

#endif
