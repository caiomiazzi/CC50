#include <cs50.h>
#include <stdio.h>

const int TOTAL = 3;


float media(int quantidade, int array[])
{
     int soma = 0;
     for (int i = 0; i < quantidade; i++)
     {
            soma += array[i];
     }
     return soma / (float) quantidade;
}





int main(void)
{
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i ++)
    {
         scores[i] = get_int("Pontuação:");
    }
    // Imprimir média
    printf ("Média: %f \n", media(TOTAL, scores));
}


