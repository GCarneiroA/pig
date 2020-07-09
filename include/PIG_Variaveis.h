
#ifndef PIG_VARIAVEIS_H
#define PIG_VARIAVEIS_H

#include "Tipos_PIG.h"

#define DEGTORAD (0.01745329251994329576)
#define RADTODEG (57.29577951307854999853275233034)

#define M_Radi DEGTORAD

class CJogo;
CJogo *jogo = nullptr;

PIG_Evento PIG_evento;
PIG_Teclado PIG_meuTeclado;
int PIGTeclasControle = 0;
int PIGTeclasReturn = 0;

int PIG_ExistenciaObjeto[MAX_OBJETOS] = {0};
int PIG_ExistenciaTimer[MAX_TIMERS] = {0};

int PIG_Tecla, PIG_Botao;
int PIG_JogoRodando = 0;

double CameraPosX = 0;
double CameraPosY = 0;
double CameraZoom = 0;
double CameraRotationXY = 0;
double CameraRotationZ = 0;

#endif
