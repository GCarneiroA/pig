
#ifndef DESENHAR_H
#define DESENHAR_H

#include "Tipos.h"

Charger* DesenharParticula(Charger* Lista);
Charger* DesenharTrajetorias(Charger* Lista);
void DesenharCampoVetorial();
void DesenharLinhaDoCampo(Charger* Particula, float Angulo);
void DesenharLinhasDoCampo(Charger* Particula);
void ProcurarIndice(float A, int* i, int* j);
void Desenhar();

#endif
