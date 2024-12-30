#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int height;

    //Solicita ao usuário o tamanho da pirámide até que seja entre 1 e 8
    do
    {
        height = get_int("Tamanho:");
    }
    while (height < 1 || height > 8);

    //Loop principal para construir cada linha da pirâmide
    for (int i = 1; i <= height ; i++)
    {
        // Imprime os espaços à esquerda da primeira pirâmide
        for (int j = 0; j < height -i; j++)
        {
            printf(" ");
        }
        // Imprime os hashes da primeira pirâmide
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
         // Imprime a lacuna entre as pirâmides
        printf("  ");

        // Imprime os hashes da segunda pirâmide
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Quebra de linha para passar à próxima linha da pirâmide
        printf("\n");

    }


}
