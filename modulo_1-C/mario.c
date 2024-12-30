#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;

    // Solicita ao usuário o tamanho da pirâmide entre 1 e 8
    do
    {
        height = get_int("Tamanho da Pirâmide: ");
    }
    while (height < 1 || height > 8);

    // Construção da piramide
    for (int i = 1; i <= height; i++)
    {

        // Dando os espaços a esquerda para a construção da pirâmide
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Imprime os # para a construção da pirâmide
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Quebra de linha para a proxima linha da pirâmide
        printf("\n");
    }
}
