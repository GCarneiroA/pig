
#ifndef PARTICULA_H
#define PARTICULA_H

#include "CObjeto.h"

class CTimer;

class CParticula : public CObjeto
{
private:
    CTimer *timer;
    int idTimer;
    int xini;
    int yini;
    int dx;
    int dy;
    int menor_x;
    int maior_x;
    int menor_y;
    int maior_y;
    int hp;
    int fading;
    float lim_tempo;

public:
    int viva;

    CParticula(int x, int y, int desloc_x, int desloc_y, int vida, int fadeOut, SDL_Renderer* renderizador, char *nomeArq, int usaGerenciadorTimer = 1);
    void DefineLimites(int xMenor, int xMaior, int yMenor, int yMaior, float tempoMax);
    ~CParticula();
    void Move();
    void MudaDirecao(int novaDx, int novaDy);
    int Colisao(CObjeto *outro);
};

#endif
