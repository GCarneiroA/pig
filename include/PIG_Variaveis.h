
#ifndef PIG_VARIAVEIS_H
#define PIG_VARIAVEIS_H

#include "Tipos_PIG.h"

#define DEGTORAD (0.01745329251994329576)
#define RADTODEG (57.29577951307854999853275233034)

#define M_Radi DEGTORAD

class CJogo;
extern CJogo *jogo;

extern PIG_Evento PIG_evento;
extern PIG_Teclado PIG_meuTeclado;
extern int PIGTeclasControle;
extern int PIGTeclasReturn;

extern int PIG_ExistenciaObjeto[MAX_OBJETOS];
extern int PIG_ExistenciaTimer[MAX_TIMERS];

extern int PIG_Tecla, PIG_Botao;
extern int PIG_JogoRodando;

extern double CameraPosX;
extern double CameraPosY;
extern double CameraZoom;
extern double CameraRotationXY;
extern double CameraRotationZ;

#endif
