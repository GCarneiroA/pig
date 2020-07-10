
#include "PIG_Variaveis.h"
#include "CJogo.h"

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
