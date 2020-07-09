
#ifndef PIG_FONTES_H
#define PIG_FONTES_H

#include "Tipos_PIG.h"

int CriarFonteNormal(char *nome,int tamanho, PIG_Cor corLetra,int contorno, PIG_Cor corContorno, PIG_Estilo estilo/* = ESTILO_NORMAL*/);
int CriarFonteFundo(char *nome,int tamanho, char *arquivoFundo,int contorno, PIG_Cor corContorno, PIG_Estilo estilo /*= ESTILO_NORMAL*/);
int CalcularLarguraPixels(char *str,int numFonte=0);
void EscreverDireita(char *str,int posicaoX,int posicaoY,int numFonte=0);
void EscreverEsquerda(char *str,int posicaoX,int posicaoY,int numFonte=0);
void EscreverCentralizada(char *str,int posicaoX,int posicaoY,int numFonte=0);

#endif
