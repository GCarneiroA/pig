
#ifndef VARIAVEIS_H
#define VARIAVEIS_H

#include "Tipos_PIG.h"
#include "Tipos.h"

extern Charger*            Particulas;
extern Animation           ListaExplosoes[MAX_EXPLOSOES];

extern Vetor               Espaco[LARG_TELA+1][ALT_TELA+1];

extern int                 CampoObjetos[LARG_TELA+1][ALT_TELA+1];

extern int                 TimerGeral;
extern int                 TimerAvisos;
extern int                 TimerAnimation;
extern char                StringAvisos[100];

extern int                 MovimentoEsferas;
extern int                 DesenharVetoresTrajetorias;
extern int                 DesenharGrade;
extern int                 ColisaoAtivada;

extern int                 DistanciaVetoresEspaciais;

extern float               Periodo;

#endif
