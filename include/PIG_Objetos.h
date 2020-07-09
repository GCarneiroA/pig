
#ifndef PIG_OBJETOS_H
#define PIG_OBJETOS_H

#include "Tipos_PIG.h"

void DefinirAngulo(int id_objeto, float angulo);
float PegarAngulo(int id_objeto);
void DefinirPivo(int id_objeto,int posicaoX,int posicaoY);
void PegarPivo(int id_objeto,int *posicaoX,int *posicaoY);
void DefinirFlip(int id_objeto,PIG_Flip valor);
PIG_Flip PegarFlip(int id_objeto);
void DefinirDimensoes(int id_objeto, int altura, int largura);
void PegarDimensoes(int id_objeto, int *altura, int *largura);
int PegarLargura(int id_objeto);
int PegarAltura(int id_objeto);
void PegarDimensoesOriginais(int id_objeto, int *altura, int *largura);
void PegarXY(int id_objeto,int *posicaoX,int *posicaoY);
int PegarX(int id_objeto);
int PegarY(int id_objeto);
int PegarCentroX(int id_objeto);
int PegarCentroY(int id_objeto);
void DefinirFrame(int id_objeto,int xBitmap, int yBitmap,int altura,int largura);
void MudarFrameObjeto(int id_objeto, char* nomeArquivo);
void DefinirColoracao(int id_objeto,PIG_Cor cor);
void DefinirOpacidade(int id_objeto,int valor);
void DesenharObjeto(int id_objeto, int offScreen=0);
void DesenharSprite(int id_sprite, int X, int Y, int Largura, int Altura, float Angulo);
int TestarColisaoObjetos(int id_objeto1,int id_objeto2);
void GirarColisao(int IDUnit1, int XUnit1[4], int YUnit1[4]);
int ValidarColisao(int XUnit1[4], int YUnit1[4], int XUnit2[4], int YUnit2[4]);
int VerificarColisao(int IDUnit1, int IDUnit2);
void MoverObjeto(int id_objeto,int posicaoX,int posicaoY);
void MoverCentro(int id_objeto, float PosicaoX, float PosicaoY);
void MoverOffset(int id_objeto, float distancia, float angulo);
int CriarObjeto(char* nomeArquivo, int X, int Y, int Altura, int Largura, int retiraFundo = -1);
int criarObjetoTamanhoOriginal(char* nomeArquivo, int X, int Y, int retiraFundo);
int CriarSprite(char* nomeArquivo);
int PIG_CriarVetor(char* nomeArquivo, int X, int Y, int Tamanho);
void DestruirObjeto(int id_objeto);

#endif
