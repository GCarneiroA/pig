
#ifndef ASSETS_H
#define ASSETS_H

#include <SDL2/SDL.h>
#include "Tipos_PIG.h"
#include "CPoolNumeros.h"

typedef struct hnode
{
    char str[100];
    int cont;
    SDL_Surface *bitmap;
} HashNode;

class CAssetLoader
{
private:
    static int totalBitmaps;
    static PoolNumeros numBitmaps;
    static HashNode *slots[MAX_SLOTS_AL];

    static int BuscaNome(char *str);

public:

    static void Inicia();
    static void Encerra();
    static SDL_Surface *LoadImage(char *nomeArq);
    static void FreeImage(char *nomeArq);

};

int CAssetLoader::totalBitmaps;
PoolNumeros CAssetLoader::numBitmaps;
HashNode* CAssetLoader::slots[MAX_SLOTS_AL];

#endif
