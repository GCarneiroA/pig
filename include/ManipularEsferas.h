
#ifndef MANIPULARESFERAS_H
#define MANIPULARESFERAS_H

#include "Tipos.h"

Charger* InserirParticula(Charger* Lista, int TipoCarga, float Carga, float Px, float Py, float Vx, float Vy);
Charger* RemoverParticula(Charger* Lista, int Px, int Py);
Charger* DestruirParticula(Charger* Lista);

#endif
