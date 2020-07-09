
#ifndef COLISAO_H
#define COLISAO_H

#include "Tipos.h"

int VerificarColisaoEsferas(float X1, float Y1, float Raio1, float X2, float Y2, float Raio2);
int AplicarColisao(Charger* E1, Charger* E2);
void ResetColision();
void ExplosionEnergy(Charger* E1, Charger* E2);

#endif
