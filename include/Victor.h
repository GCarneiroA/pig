
#ifndef VICTOR_H
#define VICTOR_H

double AnguloEquivalente(double angulo);
double AnguloEntrePontos(double X1, double Y1, double X2, double Y2);
double DistanciaEntrePontos(double X1, double Y1, double X2, double Y2);
int NumeroAleatorio(int Minimo, int Maximo);
void RodarXY(double *X, double* Y);
double XVirtualParaReal(double X, double Y);
double YVirtualParaReal(double X, double Y);
double XRealParaVirtual(double X, double Y);
double YRealParaVirtual(double X, double Y, double Z = 0);
void XYRealParaVirtual(int* NovoX, int* NovoY, double X, double Y, double Z = 0);
void XeYRealParaVirtual(double* X, double* Y);

#endif
