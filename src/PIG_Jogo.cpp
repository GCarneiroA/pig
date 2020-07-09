
#include "PIG_Jogo.h"
#include "PIG_Variaveis.h"
#include "CJogo.h"
#include "CAssetLoader.h"

#include "CMouse.h"
#include "CGerenciadorTimers.h"
#include "CGerenciadorObjetos.h"
#include "CGerenciadorParticulas.h"
#include "CGerenciadorAnimacoes.h"

#include <time.h>

void DefinirFundo(char *nome_ArquivoImagem)
{
    jogo->DefineFundo(nome_ArquivoImagem);
}

PIG_Teclado PegarTeclado()
{
    return jogo->PegaTeclado();
}

void CriarJanela(char *nome_Janela, int cursor_Proprio)
{
    if (jogo == NULL) {
        jogo = new CJogo(nome_Janela, cursor_Proprio);
        CAssetLoader::Inicia();
        if (cursor_Proprio != 0) {
            CMouse::Inicia(jogo->renderer);
        }
        CGerenciadorTimers::Inicia();
        CGerenciadorObjetos::Inicia(jogo->renderer);
        CGerenciadorParticulas::Inicia(jogo->renderer);
        CGerenciadorAnimacoes::Inicia(jogo->renderer);
        PIG_meuTeclado = PegarTeclado();
        PIG_JogoRodando = 1;
        srand(time(NULL));
    }
}

PIG_Evento PegarEvento()
{
    return jogo->PegaEvento();
}

void IniciarDesenho()
{
    jogo->IniciaDesenho();
}

void EncerrarDesenho()
{
    if (jogo->cursorPadrao != 0) {
        CMouse::Desenha();
    }
    jogo->EncerraDesenho();
}

int PegarTecla()
{
    int i;

    if (PIGTeclasControle == 0) {
        if(PIG_evento.teclado.acao == 768) {
            for (i = 0; i < SDL_NUM_SCANCODES; i++) {
                if (PIG_meuTeclado[i] == 1) {
                    PIGTeclasReturn = i;
                    PIGTeclasControle = 1;
                    return i;
                }
            }
            return 0;
        } else {
            return 0;
        }
    } else {
        if (PIG_evento.teclado.acao == 769) {
            for (i = 0; i < SDL_NUM_SCANCODES; i++) {
                if (PIGTeclasReturn == i && PIG_meuTeclado[i] == 0) {
                    PIGTeclasControle = 0;
                    return -i;
                }
            }
            return 0;
        } else {
            return 0;
        }
    }
}

int PegarBotao()
{
    static int Controle = 0;
    if (PIG_evento.mouse.acao == 1025) {
        Controle = 1;
    } else {
        if (PIG_evento.mouse.acao == 1026 && Controle == 1) {
            if(PIG_evento.mouse.botao == 1) {
                Controle = 0;
                return 1;
            } else {
                if(PIG_evento.mouse.botao == 2) {
                    Controle = 0;
                    return 2;
                } else {
                    Controle = 0;
                    return 3;
                }
            }
        }
    }
    return 0;
}

int AtualizarJanela()
{
    PIG_evento = PegarEvento();
    if (PIG_JogoRodando != 0) {
        PIG_JogoRodando = jogo->GetRodando();
    }
    PIG_Tecla = PegarTecla();
    PIG_Botao = PegarBotao();

    return 0;
}

void Esperar(int tempo)
{
    SDL_Delay(tempo);
}

void FinalizarJanela()
{
    CGerenciadorAnimacoes::Encerra();
    CGerenciadorParticulas::Encerra();
    CGerenciadorObjetos::Encerra();
    CGerenciadorTimers::Encerra();
    if (jogo->cursorPadrao == 0) {
        CMouse::Encerra();
    }
    CAssetLoader::Encerra();
    delete jogo;
}

float PegarFPS()
{
    return jogo->GetFPS();
}

void CarregarCursor(int indice,char *nomeArquivoCursor)
{
    CMouse::CarregaCursor(indice,nomeArquivoCursor);
}

void MudarCursor(int indice)
{
    CMouse::MudaCursor(indice);
}
