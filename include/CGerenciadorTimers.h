
#ifndef GERENCIADOR_TIMERS_H
#define GERENCIADOR_TIMERS_H

#include "CTimer.h"
#include "CPoolNumeros.h"
#include "Tipos_PIG.h"

class CTimer;

class CGerenciadorTimers
{
private:
    static int totalTimers;
    static PoolNumeros numTimers;
    static CTimer *timers[MAX_TIMERS];

public:
    static void Inicia();
    static void Encerra();
    static int CriaTimer();
    static void DestroiTimer(int id_timer);
    static void PausaTodos();
    static void DespausaTodos();
    static float GetTempoDecorrido(int idTimer);
    static void ReiniciaTimer(int idTimer);
    static void PausaTimer(int idTimer);
    static void DespausaTimer(int idTimer);
};

PoolNumeros CGerenciadorTimers::numTimers;
int CGerenciadorTimers::totalTimers;
CTimer *CGerenciadorTimers::timers[MAX_TIMERS];

#endif
