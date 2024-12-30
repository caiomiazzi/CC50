#include <cs50.h>
#include <stdio.h>

const int TOTAL = 3;

// Função para calcular a média de um conjunto de números
double media(int quantidade, int array[]) {
    double soma = 0.0; // Inicializa a soma como um número de ponto flutuante

    for (int i = 0; i < quantidade; i++) {
        soma += array[i];
    }

    return soma / quantidade; // A divisão por um inteiro já promove a conversão para double
}

int main(void) {
    int scores[TOTAL];

    // Lê as pontuações do usuário
    for (int i = 0; i < TOTAL; i++) {
        scores[i] = get_int("Pontuação: ");
    }

    // Calcula e imprime a média
    double media_calculada = media(TOTAL, scores);
    printf("Média: %.2lf\n", media_calculada); // Imprime a média com duas casas decimais

    return 0;
}
