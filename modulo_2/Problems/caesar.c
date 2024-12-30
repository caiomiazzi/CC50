#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verificar se o número de argumentos é válido
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verificar se o argumento é composto apenas por dígitos
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Converter a chave para inteiro
    int k = atoi(argv[1]) % 26; // Usar apenas o resto da divisão por 26

    // Solicitar o texto simples
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Criptografar cada caractere do texto simples
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Se for letra maiúscula
        if (isupper(c))
        {
            printf("%c", (c - 'A' + k) % 26 + 'A');
        }
        // Se for letra minúscula
        else if (islower(c))
        {
            printf("%c", (c - 'a' + k) % 26 + 'a');
        }
        // Outros caracteres permanecem inalterados
        else
        {
            printf("%c", c);
        }
    }

    // Imprimir nova linha ao final
    printf("\n");

    return 0;
}
