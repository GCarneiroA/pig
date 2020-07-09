
#ifndef PIG_GEOMETRICOS_H
#define PIG_GEOMETRICOS_H

#include "Tipos_PIG.h"
#include <SDL2/SDL.h>

void DesenharLinhaSimples(int pontoX1,int pontoY1,int pontoX2,int pontoY2, PIG_Cor cor);
void DesenharLinhas(SDL_Point* points, int n, PIG_Cor cor);
void DesenharLinhasDisjuntas(int *x, int *y, int qtd, PIG_Cor cor);
void DesenharPonto(float x, float y, PIG_Cor cor);
void DesenharPontos(SDL_Point *points, int count, PIG_Cor cor);
void DesenharRetangulo(int posicaoX, int posicaoY, int altura, int largura, PIG_Cor cor);

#endif
