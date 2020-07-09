
#include "CGerenciadorParticulas.h"

void CGerenciadorParticulas::Inicia(SDL_Renderer *renderer)
{
    render = renderer;
    totalGeradores = 0;
    for (int i = 0; i < MAX_GERADORPARTICULAS; i++) {
        geradores[i] = NULL;
    }
    numGeradores = new CPoolNumeros(MAX_GERADORPARTICULAS);
}

void CGerenciadorParticulas::Encerra()
{
    for (int i = 0; i < MAX_GERADORPARTICULAS; i++) {
        if (geradores[i]) {
            delete geradores[i];
        }
    }
    delete numGeradores;
}

int CGerenciadorParticulas::CriaGeradorParticulas(int maxParticulas, char* nomeArquivoBMP, int usaGerenciadorTimer)
{
    int resp = numGeradores->RetiraLivre();
    geradores[resp] = new CGeradorParticulas(maxParticulas, render, nomeArquivoBMP, usaGerenciadorTimer);
    totalGeradores++;
    return resp;
}

void CGerenciadorParticulas::DestroiGeradorParticulas(int id_gerador)
{
    numGeradores->DevolveUsado(id_gerador);
    delete geradores[id_gerador];
    totalGeradores--;
    geradores[id_gerador] = NULL;
}

void CGerenciadorParticulas::Move(int id_gerador, int px, int py)
{
    geradores[id_gerador]->Move(px,py);
}

void CGerenciadorParticulas::MudaDirecaoParticulas(int id_gerador, int dx, int dy)
{
    geradores[id_gerador]->MudaDirecao(dx,dy);
}

int CGerenciadorParticulas::CriaParticula(int id_gerador,int fadingOut, int minX, int minY, int maxX, int maxY, float maxTempo)
{
    return geradores[id_gerador]->CriaParticula(fadingOut, minX, minY, maxX, maxY, maxTempo);
}

void CGerenciadorParticulas::MoveParticulas(int id_gerador)
{
    geradores[id_gerador]->MoveParticulas();
}

int CGerenciadorParticulas::GetQtdAtivas(int id_gerador)
{
    return geradores[id_gerador]->GetQtdAtivas();
}

void CGerenciadorParticulas::Desenha(int id_gerador)
{
    geradores[id_gerador]->Desenha();
}

int CGerenciadorParticulas::Colisao(int id_gerador, CObjeto *obj)
{
    return geradores[id_gerador]->Colisao(obj);
}
