
#ifndef PIG_JOGO_H
#define PIG_JOGO_H

#include "Tipos_PIG.h"

void DefinirFundo(char *nome_ArquivoImagem);
PIG_Teclado PegarTeclado();
void CriarJanela(char *nome_Janela, int cursor_Proprio=0);
PIG_Evento PegarEvento();
void IniciarDesenho();
void EncerrarDesenho();
int PegarTecla();
int PegarBotao();
int AtualizarJanela();
void Esperar(int tempo);
void FinalizarJanela();
float PegarFPS();
void CarregarCursor(int indice,char *nomeArquivoCursor);
void MudarCursor(int indice);

#endif
