
#include "CParticula.h"
#include "CGerenciadorTimers.h"

CParticula::CParticula(int x, int y, int desloc_x, int desloc_y, int vida, int fadeOut, SDL_Renderer* renderizador, char *nomeArq, int usaGerenciadorTimer)
    : CObjeto(x, y, renderizador, nomeArq)
{
    xini = x;
    yini = y;
    dx = desloc_x;
    dy = desloc_y;
    hp = vida;
    fading = fadeOut;

    if (usaGerenciadorTimer) {
        timer = NULL;
        idTimer = CGerenciadorTimers::CriaTimer();
    } else {
        timer = new CTimer();
        idTimer = -1;
    }
    viva = 1;
}

CParticula::~CParticula()
{
    if (timer) {
        delete timer;
    } else {
        CGerenciadorTimers::DestroiTimer(idTimer);
    }
}

void CParticula::DefineLimites(int xMenor, int xMaior, int yMenor, int yMaior, float tempoMax)
{
    menor_x = xMenor;
    maior_x = xMaior;
    menor_y = yMenor;
    maior_y = yMaior;
    lim_tempo = tempoMax;
}

void CParticula::Move()
{
    if (!viva){
        return;
    }
    float decorrido;
    if (timer) {
        decorrido = timer->GetTempoDecorrido();
    } else {
        decorrido = CGerenciadorTimers::GetTempoDecorrido(idTimer);
    }
    if (fading) {
        CObjeto::SetOpacidade(255 * (1 - (decorrido / lim_tempo)));
    }
    x = xini + dx * decorrido;
    y = yini + dy * decorrido;
    CObjeto::Move(x, y);
    viva = (x > menor_x) && (x < maior_x) && (y > menor_y) && (y < maior_y) && (decorrido < lim_tempo);
}

void CParticula::MudaDirecao(int novaDx, int novaDy)
{
    dx = novaDx;
    dy = novaDy;
}

int CParticula::Colisao(CObjeto *outro)
{
    int resp = CObjeto::Colisao(outro);
    if (resp) {
        hp--;
        viva = hp > 0;
    }
    return resp;
}
