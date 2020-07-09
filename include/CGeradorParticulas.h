
#ifndef GERADOR_PARTICULAS_H
#define GERADOR_PARTICULAS_H

#include "CParticula.h"

class CGeradorParticulas
{
private:
    CParticula *parts[MAX_PARTICULAS];
    int px;
    int py;
    int dx;
    int dy;    //posicao e direcao atual das particulas
    SDL_Renderer* renderer;
    int hp;
    int maxParticulas;
    char nome[50];
    int ativas;
    int usaGerTimer;

public:
    CGeradorParticulas(int maximoParticulas,SDL_Renderer* renderizador, char *nomeArq, int usaGerenciadorTimer);
    ~CGeradorParticulas();
    void MoveParticulas();
    void Move(int nx,int ny);
    void MudaDirecao(int novaDx,int novaDy);
    void MudaHP(int novoValor);
    void Desenha();
    int CriaParticula(int fadingOut=0,int minX=-50,int minY=-50,int maxX=LARG_TELA+50,int maxY=ALT_TELA+50,float maxTempo=9999999.9);
    int Colisao(CObjeto *outro);
    int GetQtdAtivas();
};

typedef CGeradorParticulas* GeradorParticulas;

#endif
