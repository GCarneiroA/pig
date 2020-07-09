
#ifndef PILHACOORDENADA_H
#define PILHACOORDENADA_H

class CPilhaCoordenada
{
private:

    typedef struct Ponto{
        int x,y;
        struct Ponto *prox;
    } Ponto;

    Ponto *ini;

public:

    CPilhaCoordenada();
    void Empilha(int x,int y);
    int Desempilha(int &x,int &y);
    ~CPilhaCoordenada();
};

#endif
