
#ifndef GERENCIADOR_OBJETOS_H
#define GERENCIADOR_OBJETOS_H

#include "CObjeto.h"
#include "CPoolNumeros.h"

class COffscreenRenderer;

class CGerenciadorObjetos
{
private:
    static SDL_Renderer *renderer;
    static int totalObjetos;
    static PoolNumeros numObjetos;

public:
    static CObjeto *objetos[MAX_OBJETOS];
    static CObjeto *GetObjeto(int id_objeto);
    static void Inicia(SDL_Renderer *render);
    static void Encerra();
    static int CriaObjeto(int posx,int posy,char* nomeArquivoBMP,int retiraFundo=1,int opacidade=255);
    static void DestroiObjeto(int idObjeto);

    static void SetValorIntObjeto(int idObjeto,int indice,int valor);
    static void SetValorFloatObjeto(int idObjeto,int indice,float valor);
    static int GetValorIntObjeto(int idObjeto,int indice);
    static float GetValorFloatObjeto(int idObjeto,int indice);
    static void GetPosicaoXY(int idObjeto, int *x,int *y);
    static void Move(int idObjeto, int x,int y);
    static void SetAngulo(int idObjeto, float angulo);
    static float GetAngulo(int idObjeto);
    static void SetPivo(int idObjeto, int x,int y);
    static void GetPivo(int idObjeto, int *x,int *y);
    static void SetFlip(int idObjeto, PIG_Flip valor);
    static PIG_Flip GetFlip(int idObjeto);
    static void SetDimensoes(int idObjeto, int altura, int largura);
    static void GetDimensoes(int idObjeto, int *altura, int *largura);
    static void GetDimensoesOriginais(int idObjeto, int *altura, int *largura);
    static void CriaFrame(int idObjeto, int xBitmap, int yBitmap,int altura,int largura);
    static void SetColoracao(int idObjeto, PIG_Cor cor);
    static void MudarFrameObj(int idObjeto, char* nomeArquivo);
    static void SetOpacidade(int idObjeto, int valor);
    static void Desenha(int id_objeto, COffscreenRenderer *offRender = nullptr);
    static void DesenhaSprite(int id_objeto, int X, int Y, int Largura, int Altura, float Angulo);
    static int TestaColisao(int id_objeto1,int id_objeto2);
    static PIG_Cor **GetPixels(int id_objeto);
    static void AtualizaPixels(int id_objeto,int retiraFundo=1,int opacidade=255);
};

#endif
