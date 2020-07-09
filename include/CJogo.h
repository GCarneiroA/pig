
#ifndef JOGO_H
#define JOGO_H

#include <SDL2/SDL.h>
#include "Tipos_PIG.h"
#include "CTimer.h"
#include "CMapaCaracteres.h"

class CJogo
{
private:
    SDL_Texture *text_fundo;
    PIG_Cor corFundo;
    PIG_Evento ultimoEvento;
    PIG_Teclado teclado;
    int contFPS;
    CTimer *timerFPS;
    int fontesUsadas;
    MapaCaracteres fontes[MAX_FONTES];
    SDL_Window* window;
    int estado;
    int rodando;

public:
    SDL_Renderer* renderer;
    COffscreenRenderer *offRenderer;
    int cursorPadrao;

    CJogo(char *nome, int cursor=0);
    ~CJogo();
    void DefineFundo(char *nomeArquivo);
    PIG_Evento PegaEvento();
    PIG_Teclado PegaTeclado();
    void IniciaInputTextoTela();
    void EncerraInputTextoTela();
    void IniciaDesenho();
    void EncerraDesenho();
    int GetEstado();
    int GetRodando();
    void SetEstado(int valor);
    void DesenhaRetangulo(int x, int y, int altura, int largura, PIG_Cor cor);
    void DesenhaRetanguloVazado(int x, int y, int altura, int largura, PIG_Cor cor);
    void DesenhaLinhaSimples(int x1,int y1,int x2,int y2,PIG_Cor cor);
    void DesenhaLinhas(SDL_Point* points, int n, PIG_Cor cor);
    void DesenharPonto(int x, int y, PIG_Cor cor);
    void DesenharPontos(const SDL_Point *points, int count, PIG_Cor cor);
    void DesenhaLinhasDisjuntas(int *x,int *y,int qtd,PIG_Cor cor);
    void DesenhaLinhasSequencia(int *x,int *y,int qtd,PIG_Cor cor);
    int CriaFonteFundo(char *nome,int tamanho,int estilo,char *arquivoFundo,int contorno,PIG_Cor corContorno);
    int CriaFonteNormal(char *nome,int tamanho,int estilo,PIG_Cor corLetra,int contorno,PIG_Cor corContorno);
    int GetLarguraPixels(char *str,int numFonte=0);
    void EscreverCentralizada(char *str,int x,int y,int numFonte=0);
    void EscreverDireita(char *str,int x,int y,int numFonte=0);
    void EscreverEsquerda(char *str,int x,int y,int numFonte=0);
    void GetPixel(int x,int y,int *r,int *g,int *b);
    float GetFPS();
    void PreparaOffScreenRenderer(int altura,int largura);
    void SalvaOffScreenBMP(char *nomeArquivo);
    void PintaAreaOffScreen(int px,int py,PIG_Cor cor);
    void PintaFundoOffScreen(PIG_Cor cor);
    void DesenhaRetanguloOffScreen(int x1,int y1,int altura,int largura,PIG_Cor cor);
    void DesenhaRetanguloVazadoOffScreen(int x1,int y1,int altura,int largura,PIG_Cor cor);
    void DesenhaLinhaOffScreen(int x1,int y1,int x2,int y2,PIG_Cor cor);
    void SaveScreenshotBMP(char *nomeArquivo);
};

#endif
