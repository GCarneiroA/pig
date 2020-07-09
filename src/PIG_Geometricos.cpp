
#include "PIG_Geometricos.h"
#include "PIG_Variaveis.h"
#include "CJogo.h"

void DesenharLinhaSimples(int pontoX1, int pontoY1, int pontoX2, int pontoY2, PIG_Cor cor)
{
    jogo->DesenhaLinhaSimples(pontoX1, pontoY1, pontoX2, pontoY2, cor);
}

void DesenharLinhas(SDL_Point* points, int n, PIG_Cor cor)
{
    jogo->DesenhaLinhas(points, n, cor);
}

void DesenharLinhasDisjuntas(int *x, int *y, int qtd, PIG_Cor cor)
{
    jogo->DesenhaLinhasDisjuntas(x, y, qtd, cor);
}

void DesenharPonto(float x, float y, PIG_Cor cor)
{
    jogo->DesenharPonto(x, y, cor);
}

void DesenharPontos(SDL_Point *points, int count, PIG_Cor cor)
{
    jogo->DesenharPontos(points, count, cor);
}

void DesenharRetangulo(int posicaoX, int posicaoY, int altura, int largura, PIG_Cor cor)
{
    jogo->DesenhaRetangulo(posicaoX, posicaoY, altura, largura, cor);
}
