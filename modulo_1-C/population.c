#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size, end_size;

    // Solicitar o tamanho inicial
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Solicitar o tamanho final
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calcular os anos necessários
    int years = 0;
    int population = start_size;

    while (population < end_size)
    {
        int born = population / 3; // Nascimentos
        int die = population / 4;  // Mortes
        population += born - die;  // Atualizar população
        years++;                   // Incrementar contador de anos
    }

    // Imprimir o resultado
    printf("Years: %i\n", years);
}
