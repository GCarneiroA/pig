
#ifndef MANIPULARESPACO_H
#define MANIPULARESPACO_H

#include "Tipos.h"

void ResetarCampo();
void DistorcerCampo(Charger* it);
void NormalizarCampo();
void DefinirCorCampo(int i, int j);
void ParticulaMenosDistante(int i, int j);
void CalcularPontoFinal(float X, float Y, float* XFinal, float* YFinal);
void NormalizarVetor(float X, float Y, float* XFinal, float* YFinal);

#endif
