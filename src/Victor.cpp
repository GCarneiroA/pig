
#include "Victor.h"
#include "Tipos_PIG.h"
#include "PIG_Variaveis.h"
#include <math.h>

double AnguloEquivalente(double angulo)
{
    int a = angulo/360;

    angulo = angulo - (360*a);
    if(angulo < 0)
    {
        angulo = angulo + 360.0;
    }
    return angulo;
}

double AnguloEntrePontos(double X1, double Y1, double X2, double Y2)
{
    double Angulo;

    if(X1 == X2 && Y1 == Y2)
    {
        return 0.0;
    }
    Angulo = (((180.0*atan(((double)(Y2 - Y1)/(double)(X2 - X1))))/M_PI));

    if(X2 < X1)
    {
        Angulo = Angulo + 180.0;
    }
    return AnguloEquivalente(Angulo);
}

double DistanciaEntrePontos(double X1, double Y1, double X2, double Y2)
{
    return sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
}

int NumeroAleatorio(int Minimo, int Maximo)
{
    Maximo = Maximo + 1;
    return (rand() % (Maximo-Minimo)) + Minimo;
}

void RodarXY(double *X, double* Y)
{
    double CamX = LARG_TELA / 2.0;
    double CamY = ALT_TELA/2.0;

    double D = DistanciaEntrePontos(*X,*Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,*X,*Y);

    *X = CamX + D*cos(M_Radi*(A+CameraRotationXY));
    *Y = CamY + D*sin(M_Radi*(A+CameraRotationXY));
}

double XVirtualParaReal(double X, double Y)
{
    double CamX = LARG_TELA/2.0;
    double CamY = ALT_TELA/2.0;

    double C = (CamY)*sin(M_Radi*CameraRotationZ);
    double B = sin(M_Radi*CameraRotationZ)-1;

    if(B == 0)
    {
        B = 0.0001;
    }

    Y = (-Y + C)/B;

    double D = DistanciaEntrePontos(X,Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,X,Y);

    X = CamX + D*cos(M_Radi*(A-CameraRotationXY));

    return (X-CameraPosX+(CameraZoom*((LARG_TELA/2.0)-CameraPosX)))/(CameraZoom+1);
}

double YVirtualParaReal(double X, double Y)
{
    double CamX = LARG_TELA/2.0;
    double CamY = ALT_TELA/2.0;

    double C = (CamY)*sin(M_Radi*CameraRotationZ);
    double B = sin(M_Radi*CameraRotationZ)-1;

    if(B == 0)
    {
        B = 0.0001;
    }

    Y = (-Y + C)/B;

    double D = DistanciaEntrePontos(X,Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,X,Y);

    Y = CamY + D*sin(M_Radi*(A-CameraRotationXY));

    return (Y-CameraPosY+(CameraZoom*((ALT_TELA/2.0)-CameraPosY)))/(CameraZoom+1);
}

double XRealParaVirtual(double X, double Y)
{
    X = ((X+CameraPosX)+((X+CameraPosX)-(LARG_TELA/2.0))*CameraZoom);
    Y = ((Y+CameraPosY)+((Y+CameraPosY)-(ALT_TELA/2.0))*CameraZoom);

    if(CameraRotationXY == 0.0)
    {
        return X;
    }

    double CamX = LARG_TELA/2.0;
    double CamY = ALT_TELA/2.0;

    double D = DistanciaEntrePontos(X,Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,X,Y);

    X = CamX + D*cos(M_Radi*(A+CameraRotationXY));

    return X;

    //return ((X+CameraPosX)+((X+CameraPosX)-(LARG_TELA/2.0))*CameraZoom);
}

double YRealParaVirtual(double X, double Y, double Z)
{
    X = ((X+CameraPosX)+((X+CameraPosX)-(LARG_TELA/2.0))*CameraZoom);
    Y = ((Y+CameraPosY)+((Y+CameraPosY)-(ALT_TELA/2.0))*CameraZoom);

    if(CameraRotationXY == 0.0 && CameraRotationZ == 0.0)
    {
        return Y;
    }

    double CamX = LARG_TELA/2.0;
    double CamY = ALT_TELA/2.0;

    double D = DistanciaEntrePontos(X,Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,X,Y);

    Y = CamY + D*sin(M_Radi*(A+CameraRotationXY));

    Y = Y - (Y-CamY-Z)*sin(M_Radi*CameraRotationZ);

    return Y;

    //return ((Y+CameraPosY)+((Y+CameraPosY)-(ALT_TELA/2.0))*CameraZoom);
}

void XYRealParaVirtual(int* NovoX, int* NovoY, double X, double Y, double Z)
{
    X = ((X+CameraPosX)+((X+CameraPosX)-(LARG_TELA/2.0))*CameraZoom);
    Y = ((Y+CameraPosY)+((Y+CameraPosY)-(ALT_TELA/2.0))*CameraZoom);

    if(CameraRotationXY == 0.0 && CameraRotationZ == 0.0)
    {
        *NovoX = X;
        *NovoY = Y;
        return;
    }

    double CamX = LARG_TELA/2.0;
    double CamY = ALT_TELA/2.0;

    double D = DistanciaEntrePontos(X,Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,X,Y);

    X = CamX + D*cos(M_Radi*(A+CameraRotationXY));
    Y = CamY + D*sin(M_Radi*(A+CameraRotationXY));
    Y = Y - (Y-CamY-Z)*sin(M_Radi*CameraRotationZ);

    *NovoX = X;
    *NovoY = Y;
}

void XeYRealParaVirtual(double* X, double* Y)
{
    *X = XRealParaVirtual(*X,*Y);
    *Y = YRealParaVirtual(*X,*Y);

    double CamX = LARG_TELA/2.0;
    double CamY = ALT_TELA/2.0;

    double D = DistanciaEntrePontos(*X,*Y,CamX,CamY);
    double A = AnguloEntrePontos(CamX,CamY,*X,*Y);

    *X = CamX + D*cos(M_Radi*(A+CameraRotationXY));
    *Y = CamY + D*sin(M_Radi*(A+CameraRotationXY));
}
