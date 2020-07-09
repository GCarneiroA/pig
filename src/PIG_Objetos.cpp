
#include "PIG_Objetos.h"
#include "Victor.h"
#include "PIG_Variaveis.h"

#include "CGerenciadorObjetos.h"
#include "CJogo.h"


void DefinirAngulo(int id_objeto, float angulo)
{
    if (PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetAngulo(id_objeto, AnguloEquivalente(angulo));
    }
}

float PegarAngulo(int id_objeto)
{
    if (PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        return CGerenciadorObjetos::GetAngulo(id_objeto);
    }
    return 0.0;
}

void DefinirPivo(int id_objeto,int posicaoX,int posicaoY)
{
    if (PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetPivo(id_objeto,posicaoX,posicaoY);
    }
}

void PegarPivo(int id_objeto,int *posicaoX,int *posicaoY)
{
    if (PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetPivo(id_objeto,posicaoX,posicaoY);
    }
}

void DefinirFlip(int id_objeto,PIG_Flip valor)
{
    if (PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetFlip(id_objeto,valor);
    }
}

PIG_Flip PegarFlip(int id_objeto)
{
    PIG_Flip flip;
    if (PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        flip = CGerenciadorObjetos::GetFlip(id_objeto);
    }
    return flip;
}

void DefinirDimensoes(int id_objeto, int altura, int largura)
{
    if (PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetDimensoes(id_objeto,altura,largura);
    }
}

void PegarDimensoes(int id_objeto, int *altura, int *largura)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetDimensoes(id_objeto,altura,largura);
    }
}

int PegarLargura(int id_objeto)
{
    int a,l;

    PegarDimensoes(id_objeto,&a,&l);
    return l;

}
int PegarAltura(int id_objeto)
{
    int a,l;

    PegarDimensoes(id_objeto,&a,&l);
    return a;

}

void PegarDimensoesOriginais(int id_objeto, int *altura, int *largura)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetDimensoesOriginais(id_objeto,altura,largura);
    }
}

void PegarXY(int id_objeto,int *posicaoX,int *posicaoY)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::GetPosicaoXY(id_objeto,posicaoX,posicaoY);
    }
}

int PegarX(int id_objeto)
{
    int x=0,y=0;

    PegarXY(id_objeto,&x,&y);

    return x;

}
int PegarY(int id_objeto)
{
    int x=0,y=0;

    PegarXY(id_objeto,&x,&y);

    return y;
}
int PegarCentroX(int id_objeto)
{
    int x=0,y=0,a,l;

    PegarXY(id_objeto,&x,&y);
    PegarDimensoes(id_objeto,&a,&l);
    x = x + (l/2);

    return x;

}
int PegarCentroY(int id_objeto)
{
    int x=0,y=0,a,l;

    PegarXY(id_objeto,&x,&y);
    PegarDimensoes(id_objeto,&a,&l);
    y = y + (a/2);

    return y;
}

void DefinirFrame(int id_objeto,int xBitmap, int yBitmap,int altura,int largura)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::CriaFrame(id_objeto,xBitmap,yBitmap,altura,largura);
    }
}

void MudarFrameObjeto(int id_objeto, char* nomeArquivo)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::MudarFrameObj(id_objeto,nomeArquivo);
    }
}

void DefinirColoracao(int id_objeto,PIG_Cor cor)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetColoracao(id_objeto,cor);
    }
}

void DefinirOpacidade(int id_objeto,int valor)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::SetOpacidade(id_objeto,valor);
    }
}

void DesenharObjeto(int id_objeto, int offScreen)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        if (offScreen==0)
            CGerenciadorObjetos::Desenha(id_objeto,NULL);
        else CGerenciadorObjetos::Desenha(id_objeto, jogo->offRenderer);
    }
}

void DesenharSprite(int id_sprite, int X, int Y, int Largura, int Altura, float Angulo)
{
    if(PIG_ExistenciaObjeto[id_sprite] == 1)
    {
        CGerenciadorObjetos::DesenhaSprite(id_sprite,X,Y,Largura,Altura,Angulo);
    }
}

int TestarColisaoObjetos(int id_objeto1,int id_objeto2)
{
    if (PIG_ExistenciaObjeto[id_objeto1] == 1 && PIG_ExistenciaObjeto[id_objeto2] == 1)
    {
        return CGerenciadorObjetos::TestaColisao(id_objeto1,id_objeto2);
    }
    return 0;
}

void GirarColisao(int IDUnit1, int XUnit1[4], int YUnit1[4])
{
    int AnguloUnit1 = (int)PegarAngulo(IDUnit1);

    if(AnguloUnit1 <= 45 || AnguloUnit1 > 315)
    {
        XUnit1[0] = PegarCentroX(IDUnit1) - (PegarLargura(IDUnit1)/2);
        YUnit1[0] = PegarCentroY(IDUnit1) + (PegarAltura(IDUnit1)/2);

        XUnit1[1] = PegarCentroX(IDUnit1) + (PegarLargura(IDUnit1)/2);
        YUnit1[1] = PegarCentroY(IDUnit1) + (PegarAltura(IDUnit1)/2);

        XUnit1[2] = PegarCentroX(IDUnit1) - (PegarLargura(IDUnit1)/2);
        YUnit1[2] = PegarCentroY(IDUnit1) - (PegarAltura(IDUnit1)/2);

        XUnit1[3] = PegarCentroX(IDUnit1) + (PegarLargura(IDUnit1)/2);
        YUnit1[3] = PegarCentroY(IDUnit1) - (PegarAltura(IDUnit1)/2);
    }

    if(AnguloUnit1 <= 135 && AnguloUnit1 > 45)
    {
        XUnit1[0] = PegarCentroX(IDUnit1) - (PegarAltura(IDUnit1)/2);
        YUnit1[0] = PegarCentroY(IDUnit1) + (PegarLargura(IDUnit1)/2);

        XUnit1[1] = PegarCentroX(IDUnit1) + (PegarAltura(IDUnit1)/2);
        YUnit1[1] = PegarCentroY(IDUnit1) + (PegarLargura(IDUnit1)/2);

        XUnit1[2] = PegarCentroX(IDUnit1) - (PegarAltura(IDUnit1)/2);
        YUnit1[2] = PegarCentroY(IDUnit1) - (PegarLargura(IDUnit1)/2);

        XUnit1[3] = PegarCentroX(IDUnit1) + (PegarAltura(IDUnit1)/2);
        YUnit1[3] = PegarCentroY(IDUnit1) - (PegarLargura(IDUnit1)/2);
    }

    if(AnguloUnit1 <= 225 && AnguloUnit1 > 135)
    {
        XUnit1[0] = PegarCentroX(IDUnit1) - (PegarLargura(IDUnit1)/2);
        YUnit1[0] = PegarCentroY(IDUnit1) + (PegarAltura(IDUnit1)/2);

        XUnit1[1] = PegarCentroX(IDUnit1) + (PegarLargura(IDUnit1)/2);
        YUnit1[1] = PegarCentroY(IDUnit1) + (PegarAltura(IDUnit1)/2);

        XUnit1[2] = PegarCentroX(IDUnit1) - (PegarLargura(IDUnit1)/2);
        YUnit1[2] = PegarCentroY(IDUnit1) - (PegarAltura(IDUnit1)/2);

        XUnit1[3] = PegarCentroX(IDUnit1) + (PegarLargura(IDUnit1)/2);
        YUnit1[3] = PegarCentroY(IDUnit1) - (PegarAltura(IDUnit1)/2);
    }

    if(AnguloUnit1 <= 315 && AnguloUnit1 > 225)
    {
        XUnit1[0] = PegarCentroX(IDUnit1) - (PegarAltura(IDUnit1)/2);
        YUnit1[0] = PegarCentroY(IDUnit1) + (PegarLargura(IDUnit1)/2);

        XUnit1[1] = PegarCentroX(IDUnit1) + (PegarAltura(IDUnit1)/2);
        YUnit1[1] = PegarCentroY(IDUnit1) + (PegarLargura(IDUnit1)/2);

        XUnit1[2] = PegarCentroX(IDUnit1) - (PegarAltura(IDUnit1)/2);
        YUnit1[2] = PegarCentroY(IDUnit1) - (PegarLargura(IDUnit1)/2);

        XUnit1[3] = PegarCentroX(IDUnit1) + (PegarAltura(IDUnit1)/2);
        YUnit1[3] = PegarCentroY(IDUnit1) - (PegarLargura(IDUnit1)/2);
    }
}

int ValidarColisao(int XUnit1[4], int YUnit1[4], int XUnit2[4], int YUnit2[4])
{
    if(XUnit1[0] >= XUnit2[2] && XUnit1[0] <= XUnit2[3])
    {
        if(YUnit1[0] >= YUnit2[2] && YUnit1[0] <= YUnit2[0])
        {
            return 1;
        }
    }

    if(XUnit1[1] >= XUnit2[2] && XUnit1[1] <= XUnit2[3])
    {
        if(YUnit1[1] >= YUnit2[2] && YUnit1[1] <= YUnit2[0])
        {
            return 1;
        }
    }

    if(XUnit1[2] >= XUnit2[2] && XUnit1[2] <= XUnit2[3])
    {
        if(YUnit1[2] >= YUnit2[2] && YUnit1[2] <= YUnit2[0])
        {
            return 1;
        }
    }

    if(XUnit1[3] >= XUnit2[2] && XUnit1[3] <= XUnit2[3])
    {
        if(YUnit1[3] >= YUnit2[2] && YUnit1[3] <= YUnit2[0])
        {
            return 1;

        }
    }
    return 0;
}

int VerificarColisao(int IDUnit1, int IDUnit2)
{
    int XUnit1[4], YUnit1[4], XUnit2[4], YUnit2[4], E, D;

    if(PIG_ExistenciaObjeto[IDUnit1] == 1 && PIG_ExistenciaObjeto[IDUnit2] == 1)
    {
        GirarColisao(IDUnit1,XUnit1,YUnit1);
        GirarColisao(IDUnit2,XUnit2,YUnit2);

        E = ValidarColisao(XUnit1, YUnit1, XUnit2, YUnit2);
        D = ValidarColisao(XUnit2, YUnit2, XUnit1, YUnit1);

        if(E == 1 || D == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

void MoverObjeto(int id_objeto,int posicaoX,int posicaoY)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        CGerenciadorObjetos::Move(id_objeto,posicaoX,posicaoY);
    }
}

void MoverCentro(int id_objeto, float PosicaoX, float PosicaoY)
{
    int a,l;

    PegarDimensoes(id_objeto,&a,&l);
    PosicaoX = PosicaoX - l/2;
    PosicaoY = PosicaoY - a/2;
    MoverObjeto(id_objeto,PosicaoX,PosicaoY);
}

void MoverOffset(int id_objeto, float distancia, float angulo)
{
    float Adjacente,Oposto;
    float X,Y;

    Adjacente = (cos(angulo*M_PI/180)*distancia);
    Oposto = (sin(angulo*M_PI/180)*distancia);

    X = PegarCentroX(id_objeto) + Adjacente;
    Y = PegarCentroY(id_objeto) + Oposto;

    MoverCentro(id_objeto, X, Y);
}

int CriarObjeto(char* nomeArquivo, int X, int Y, int Altura, int Largura, int retiraFundo)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,retiraFundo,255);
    PIG_ExistenciaObjeto[Objt] = 1;
    DefinirDimensoes(Objt, Altura, Largura);
    DefinirPivo(Objt,Largura/2,Altura/2);
    DefinirAngulo(Objt,0);
    MoverCentro(Objt,X,Y);
    return Objt;
}

int criarObjetoTamanhoOriginal(char* nomeArquivo, int X, int Y, int retiraFundo)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,retiraFundo,255);
    PIG_ExistenciaObjeto[Objt] = 1;

    int Altura = PegarAltura(Objt);
    int Largura = PegarLargura(Objt);
    DefinirPivo(Objt,Largura/2,Altura/2);
    DefinirAngulo(Objt,0);
    MoverCentro(Objt,X,Y);
    return Objt;
}

int CriarSprite(char* nomeArquivo)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,1,255);
    PIG_ExistenciaObjeto[Objt] = 1;

    return Objt;
}

int PIG_CriarVetor(char* nomeArquivo, int X, int Y, int Tamanho)
{
    int Objt;

    Objt = CGerenciadorObjetos::CriaObjeto(0,0,nomeArquivo,1,255);
    PIG_ExistenciaObjeto[Objt] = 1;
    DefinirDimensoes(Objt, Tamanho/4.0, Tamanho);
    DefinirPivo(Objt,0,Tamanho/8.0);
    DefinirAngulo(Objt,0);
    MoverObjeto(Objt,X,Y-Tamanho/8.0);
    return Objt;
}

void DestruirObjeto(int id_objeto)
{
    if(PIG_ExistenciaObjeto[id_objeto] == 1)
    {
        PIG_ExistenciaObjeto[id_objeto] = 0;
        CGerenciadorObjetos::DestroiObjeto(id_objeto);
    }
}
