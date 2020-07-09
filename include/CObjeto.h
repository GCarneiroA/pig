
#ifndef OBJETO_H
#define OBJETO_H

#include <SDL2/SDL.h>
#include "Tipos_PIG.h"
#include "Tipos.h"

class SDL_Renderer;
class SDL_Texture;
class SDL_Point;
class PIG_Cor;
class COffscreenRenderer;

class CObjeto
{
protected:
    int alt, larg,altOriginal,largOriginal;
    float angulo;
    SDL_Rect dest, frame;
    SDL_Texture* text;
    SDL_Point pivoRelativo;
    SDL_Renderer* renderer;
    SDL_RendererFlip flip;
    SDL_Surface* bitmap;
    SDL_Point bb[4];
    char nomeImagem[100];
    int estado;

    void DesenhaBB();
    void AtualizaBB();
    void ExtraiPixels();
    void CriaTextura(int retiraFundo,int opacidade);

public:

    int x,y;
    int valoresInt[MAX_ATRIBUTOS_OBJETO];
    float valoresFloat[MAX_ATRIBUTOS_OBJETO];
    PIG_Cor **pixels;

    CObjeto(int posx,int posy, SDL_Renderer* renderizador,char* nomeArquivo,int retiraFundo=1,int opacidade=255);
    ~CObjeto();

    void MudarFrame(char* nomeArquivo);
    void DefineFrame(SDL_Rect *r);
    void GetXY(int &x,int &y);
    void SetColoracao(PIG_Cor cor);
    void Desenha(COffscreenRenderer *offRender = nullptr);
    void DesenhaSprite(int X, int Y, int Largura, int Altura, float Angulo);
    int Colisao(CObjeto* outro);
    void SetAngulo(float a);
    float GetAngulo();
    void SetFlip(PIG_Flip valor);
    PIG_Flip GetFlip();
    void SetPivo(int px,int py);
    void GetPivo(int &px,int &py);
    void Move(int nx,int ny);
    void SetDimensoes(int altura,int largura);
    void GetDimensoes(int &altura, int &largura);
    void GetDimensoesOriginais(int &altura,int &largura);
    void SetOpacidade(int valor);
    PIG_Cor **GetPixels();
    void AtualizaPixels(int retiraFundo=1,int opacidade=255);
};

#endif
