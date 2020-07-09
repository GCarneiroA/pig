
#ifndef FORCACLASS_H
#define FORCACLASS_H

typedef struct force
{
    int Forca[2];

    int Objeto;
    struct force* Proximo;

} Forca;

class ForcaClass
{
public:
    ForcaClass();
    void ExecutarForcas();
    void AplicarForca(int Objeto, int ForcaAplicada, int Direcao);
    void ZerarForca(int Objeto, int Direcao);
    void InverterForca(int Objeto, int Direcao);
    int GetForca(int Objeto, int Direcao);
private:
    Forca *Lista;
    int ForcaTimer;
};

#endif // FORCACLASS_H
