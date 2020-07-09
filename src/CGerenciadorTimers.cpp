
#include "CGerenciadorTimers.h"

void CGerenciadorTimers::Inicia()
{
    totalTimers = 0;
    for (int i = 0; i < MAX_TIMERS; i++) {
        timers[i] = NULL;
    }
    numTimers = new CPoolNumeros(MAX_TIMERS);
}

void CGerenciadorTimers::Encerra()
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timers[i]) {
            delete timers[i];
        }
    }
    delete numTimers;
}

int CGerenciadorTimers::CriaTimer()
{
    int resp = numTimers->RetiraLivre();
    timers[resp] = new CTimer();
    totalTimers++;
    return resp;
}

void CGerenciadorTimers::DestroiTimer(int id_timer)
{
    numTimers->DevolveUsado(id_timer);
    totalTimers--;
    delete timers[id_timer];
    timers[id_timer] = NULL;
}

void CGerenciadorTimers::PausaTodos()
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timers[i]) {
            timers[i]->Pausa();
        }
    }
}

void CGerenciadorTimers::DespausaTodos()
{
    for (int i = 0; i < MAX_TIMERS; i++) {
        if (timers[i]) {
            timers[i]->Despausa();
        }
    }
}

inline float CGerenciadorTimers::GetTempoDecorrido(int idTimer)
{
    return timers[idTimer]->GetTempoDecorrido();
}

inline void CGerenciadorTimers::ReiniciaTimer(int idTimer)
{
    timers[idTimer]->Reinicia();
}

inline void CGerenciadorTimers::PausaTimer(int idTimer)
{
    timers[idTimer]->Pausa();
}

inline void CGerenciadorTimers::DespausaTimer(int idTimer)
{
    timers[idTimer]->Despausa();
}
