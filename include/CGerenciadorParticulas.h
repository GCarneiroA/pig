
#ifndef GERENCIADOR_PARTICULAS_H
#define GERENCIADOR_PARTICULAS_H

#include "CGeradorParticulas.h"
#include "CPoolNumeros.h"

class CGerenciadorParticulas
{
private:
    static SDL_Renderer *render;
    static int totalGeradores;
    static PoolNumeros numGeradores;
    static GeradorParticulas geradores[MAX_GERADORPARTICULAS];

public:
    static void Inicia(SDL_Renderer *renderer);
    static void Encerra();
    static int CriaGeradorParticulas(int maxParticulas,char* nomeArquivoBMP,int usaGerenciadorTimer=1);
    static void DestroiGeradorParticulas(int id_gerador);
    inline static void Move(int id_gerador,int px,int py);
    inline static void MudaDirecaoParticulas(int id_gerador,int dx,int dy);
    inline static int CriaParticula(int id_gerador,int fadingOut=0,int minX=-50,int minY=-50,int maxX=LARG_TELA+50,int maxY=ALT_TELA+50,float maxTempo=9999999.9);
    inline static void MoveParticulas(int id_gerador);
    inline static int GetQtdAtivas(int id_gerador);
    inline static void Desenha(int id_gerador);
    inline static int Colisao(int id_gerador, CObjeto *obj);
};

#endif
