
#ifndef POOLNUMEROS_H
#define POOLNUMEROS_H

class CPoolNumeros
{
    typedef struct xxx{
        int valor;
        struct xxx *prox;
    } Elem;

private:
    Elem *livres;
    int *usados;

public:
    int qtdTotal;

    CPoolNumeros(int qtd);
    ~CPoolNumeros();
    int RetiraLivre();
    void DevolveUsado(int valor);
    void ImprimeLivres();
    void ImprimeUsados();
};

typedef CPoolNumeros* PoolNumeros;

#endif
