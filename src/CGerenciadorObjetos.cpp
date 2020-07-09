
#include "CGerenciadorObjetos.h"

/*
CObjeto *CGerenciadorObjetos::objetos[MAX_OBJETOS];
PoolNumeros CGerenciadorObjetos::numObjetos;
int CGerenciadorObjetos::totalObjetos;
SDL_Renderer* CGerenciadorObjetos::renderer;
*/

CObjeto *CGerenciadorObjetos::GetObjeto(int id_objeto)
{
    return objetos[id_objeto];
}

void CGerenciadorObjetos::Inicia(SDL_Renderer *render)
{
renderer = render;
        totalObjetos = 0;
        for (int i=0;i<MAX_OBJETOS;i++)
            objetos[i] = NULL;
        numObjetos = new CPoolNumeros(MAX_OBJETOS);
}

void CGerenciadorObjetos::Encerra()
{
for (int i=0;i<MAX_OBJETOS;i++){
            if (objetos[i]) delete objetos[i];
        }
        delete numObjetos;
}

int CGerenciadorObjetos::CriaObjeto(int posx,int posy,char* nomeArquivoBMP,int retiraFundo,int opacidade)
{
 int resp = numObjetos->RetiraLivre();
        objetos[resp] = new CObjeto(posx,posy,renderer,nomeArquivoBMP,retiraFundo,opacidade);
        totalObjetos++;
        return resp;
}

void CGerenciadorObjetos::DestroiObjeto(int idObjeto)
{
numObjetos->DevolveUsado(idObjeto);
        delete objetos[idObjeto];
        totalObjetos--;
        objetos[idObjeto] = NULL;
}

inline void CGerenciadorObjetos::SetValorIntObjeto(int idObjeto,int indice,int valor)
{
objetos[idObjeto]->valoresInt[indice] = valor;
}

inline void CGerenciadorObjetos::SetValorFloatObjeto(int idObjeto,int indice,float valor)
{
objetos[idObjeto]->valoresFloat[indice] = valor;
}

inline int CGerenciadorObjetos::GetValorIntObjeto(int idObjeto,int indice)
{
return objetos[idObjeto]->valoresInt[indice];
}

inline float CGerenciadorObjetos::GetValorFloatObjeto(int idObjeto,int indice)
{
return objetos[idObjeto]->valoresFloat[indice];
}

inline void CGerenciadorObjetos::GetPosicaoXY(int idObjeto, int *x,int *y)
{
objetos[idObjeto]->GetXY(*x,*y);
}

inline void CGerenciadorObjetos::Move(int idObjeto, int x,int y)
{
objetos[idObjeto]->Move(x,y);
}

inline void CGerenciadorObjetos::SetAngulo(int idObjeto, float angulo)
{
objetos[idObjeto]->SetAngulo(angulo);
}

inline float CGerenciadorObjetos::GetAngulo(int idObjeto)
{
return objetos[idObjeto]->GetAngulo();
}

inline void CGerenciadorObjetos::SetPivo(int idObjeto, int x,int y)
{
objetos[idObjeto]->SetPivo(x,y);
}

inline void CGerenciadorObjetos::GetPivo(int idObjeto, int *x,int *y)
{
 objetos[idObjeto]->GetPivo(*x,*y);
}

inline void CGerenciadorObjetos::SetFlip(int idObjeto, PIG_Flip valor)
{
objetos[idObjeto]->SetFlip(valor);
}

inline PIG_Flip CGerenciadorObjetos::GetFlip(int idObjeto)
{
 return objetos[idObjeto]->GetFlip();
}

inline void CGerenciadorObjetos::SetDimensoes(int idObjeto, int altura, int largura)
{
objetos[idObjeto]->SetDimensoes(altura,largura);
}

inline void CGerenciadorObjetos::GetDimensoes(int idObjeto, int *altura, int *largura)
{
objetos[idObjeto]->GetDimensoes(*altura,*largura);
}

inline void CGerenciadorObjetos::GetDimensoesOriginais(int idObjeto, int *altura, int *largura)
{
objetos[idObjeto]->GetDimensoesOriginais(*altura,*largura);
}

inline void CGerenciadorObjetos::CriaFrame(int idObjeto, int xBitmap, int yBitmap,int altura,int largura)
{
SDL_Rect r;
        r.x = xBitmap;
        r.y = yBitmap;
        r.h = altura;
        r.w = largura;
        objetos[idObjeto]->DefineFrame(&r);
}

inline void CGerenciadorObjetos::SetColoracao(int idObjeto, PIG_Cor cor)
{
objetos[idObjeto]->SetColoracao(cor);
}

inline void CGerenciadorObjetos::MudarFrameObj(int idObjeto, char* nomeArquivo)
{
objetos[idObjeto]->MudarFrame(nomeArquivo);
}

inline void CGerenciadorObjetos::SetOpacidade(int idObjeto, int valor)
{
objetos[idObjeto]->SetOpacidade(valor);
}

inline void CGerenciadorObjetos::Desenha(int id_objeto, COffscreenRenderer *offRender)
{
objetos[id_objeto]->Desenha(offRender);
}

inline void CGerenciadorObjetos::CGerenciadorObjetos::DesenhaSprite(int id_objeto, int X, int Y, int Largura, int Altura, float Angulo)
{
 objetos[id_objeto]->DesenhaSprite(X,Y,Largura,Altura,Angulo);
}

inline int CGerenciadorObjetos::TestaColisao(int id_objeto1,int id_objeto2)
{
    return objetos[id_objeto1]->Colisao(objetos[id_objeto2]);
}

inline PIG_Cor **CGerenciadorObjetos::GetPixels(int id_objeto)
{
return objetos[id_objeto]->GetPixels();
}

inline void CGerenciadorObjetos::AtualizaPixels(int id_objeto,int retiraFundo,int opacidade)
{
objetos[id_objeto]->AtualizaPixels(retiraFundo,opacidade);
}
