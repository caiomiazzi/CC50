#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float reais;

    // Solicita um valor positivo para o troco
    do
    {
        reais = get_float("Troca devida: ");
    }
    while (reais < 0);

    // Converte o valor em reais para centavos
    int centavos = round(reais * 100);

    // Contador de moedas
    int moedas = 0;

    // Calcula o número de moedas de 25 centavos
    moedas += centavos / 25;
    centavos %= 25;

    // Calcula o número de moedas de 10 centavos
    moedas += centavos / 10;
    centavos %= 10;

    // Calcula o número de moedas de 5 centavos
    moedas += centavos / 5;
    centavos %= 5;

    // Calcula o número de moedas de 1 centavo
    moedas += centavos;

    // Imprime o número total de moedas
    printf("%d\n", moedas);
}
