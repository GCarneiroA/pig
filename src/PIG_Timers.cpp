
#include "PIG_Timers.h"
#include "PIG_Variaveis.h"
#include "CGerenciadorTimers.h"

int CriarTimer()
{
    int timer;

    timer = CGerenciadorTimers::CriaTimer();
    PIG_ExistenciaTimer[timer] = 1;
    return timer;
}

float TempoDecorrido(int id_timer)
{
    if(PIG_ExistenciaTimer[id_timer] == 1)
    {
        return CGerenciadorTimers::GetTempoDecorrido(id_timer);
    }
    return 0.0;
}

int TimerCriado(int id_timer)
{
    if(PIG_ExistenciaTimer[id_timer] == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PausarTimer(int id_timer)
{
    if(PIG_ExistenciaTimer[id_timer] == 1)
    {
        CGerenciadorTimers::PausaTimer(id_timer);
    }
}

void PausarTudo()
{
    CGerenciadorTimers::PausaTodos();
}

void DespausarTimer(int id_timer)
{
    if(PIG_ExistenciaTimer[id_timer] == 1)
    {
        CGerenciadorTimers::DespausaTimer(id_timer);
    }
}

void DespausarTudo()
{
    CGerenciadorTimers::DespausaTodos();
}

void ReiniciarTimer(int id_timer)
{
    if(PIG_ExistenciaTimer[id_timer] == 1)
    {
        CGerenciadorTimers::ReiniciaTimer(id_timer);
    }
}

void DestruirTimer(int id_timer)
{
    if(PIG_ExistenciaTimer[id_timer] == 1)
    {
        PIG_ExistenciaTimer[id_timer] = 0;
        CGerenciadorTimers::DestroiTimer(id_timer);
    }
}
