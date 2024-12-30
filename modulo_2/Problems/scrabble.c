#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Pontuação de cada letra do alfabeto
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Protótipo da função
int compute_score(string word);

int main(void)
{
    // Solicitar palavras dos jogadores
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calcular os pontos de cada palavra
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determinar e imprimir o vencedor
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Função para calcular a pontuação de uma palavra
int compute_score(string word)
{
    int score = 0;

    // Iterar sobre cada caractere da palavra
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i])) // Verificar se o caractere é uma letra
        {
            char uppercase = toupper(word[i]); // Converter para maiúscula
            int index = uppercase - 'A';       // Obter o índice no array POINTS
            score += POINTS[index];            // Somar o valor correspondente ao índice
        }
    }

    return score;
}
