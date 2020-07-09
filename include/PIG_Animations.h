
#ifndef PIG_ANIMATIONS_H
#define PIG_ANIMATIONS_H

typedef struct animation
{
    int SpriteAtual;
    int* VetorSprites;
    int QuantidadeSprites;
    int Largura, Altura;
    double X, Y;
    double Angulo;

    struct animation* Proximo;

}   Animation;

Animation* AnimationsList;

void DesenharAnimations(Animation* List);
void PlayAnimation(int Codigo, double X, double Y, int Largura, int Altura, double Angulo);
Animation* DestruirAnimations(Animation* List);
Animation* AtualizarAnimations(Animation* List);
void CriarAnimations();

#endif
