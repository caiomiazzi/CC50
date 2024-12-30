// Legibilidade: implementação do algoritmo Coleman-Liau

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Solicitar ao usuário um texto
    string text = get_string("Texto: ");

    // Variáveis para armazenar contadores
    int letters = 0;
    int words = 1; // Começa com 1 para contar a última palavra
    int sentences = 0;

    // Iterar sobre cada caractere do texto
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Contar letras (A-Z ou a-z)
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Contar palavras (espaços indicam separação)
        else if (isspace(text[i]))
        {
            words++;
        }
        // Contar frases (. ! ? indicam fim de frase)
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Cálculo das médias por 100 palavras
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    // Fórmula de Coleman-Liau
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Determinar e imprimir o nível de leitura
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}
