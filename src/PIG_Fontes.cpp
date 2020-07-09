
#include "PIG_Fontes.h"
#include "PIG_Variaveis.h"

#include "CJogo.h"

int CriarFonteNormal(char *nome, int tamanho, PIG_Cor corLetra, int contorno, PIG_Cor corContorno, PIG_Estilo estilo)
{
    return jogo->CriaFonteNormal(nome, tamanho, estilo, corLetra, contorno, corContorno);
}

int CriarFonteFundo(char *nome, int tamanho, char *arquivoFundo, int contorno, PIG_Cor corContorno, PIG_Estilo estilo)
{
    return jogo->CriaFonteFundo(nome, tamanho, estilo, arquivoFundo, contorno, corContorno);
}

int CalcularLarguraPixels(char *str, int numFonte)
{
    return jogo->GetLarguraPixels(str);
}

void EscreverDireita(char *str, int posicaoX, int posicaoY, int numFonte)
{
    jogo->EscreverDireita(str, posicaoX, posicaoY, numFonte);
}

void EscreverEsquerda(char *str, int posicaoX, int posicaoY, int numFonte)
{
    jogo->EscreverEsquerda(str, posicaoX, posicaoY, numFonte);
}

void EscreverCentralizada(char *str, int posicaoX, int posicaoY, int numFonte)
{
    jogo->EscreverCentralizada(str, posicaoX, posicaoY, numFonte);
}
