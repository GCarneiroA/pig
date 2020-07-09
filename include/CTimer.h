
#ifndef TIMER_H
#define TIMER_H

class CTimer
{
private:
        long int inicio;
        long int pausa;
        bool pausado;
public:
    CTimer();
    ~CTimer();
    float GetTempoDecorrido();
    void Pausa();
    void Despausa();
    void Reinicia();
    CTimer* Copia();
};

#endif
