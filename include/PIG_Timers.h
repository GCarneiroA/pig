
#ifndef PIG_TIMERS_H
#define PIG_TIMERS_H

int CriarTimer();
float TempoDecorrido(int id_timer);
int TimerCriado(int id_timer);
void PausarTimer(int id_timer);
void PausarTudo();
void DespausarTimer(int id_timer);
void DespausarTudo();
void ReiniciarTimer(int id_timer);
void DestruirTimer(int id_timer);

#endif
