#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // Verificar se há exatamente um argumento
    if (argc != 2)
    {
        printf("Uso: ./substitution chave de substituição\n");
        return 1;
    }

    string key = argv[1];

    // Validar a chave
    if (!is_valid_key(key))
    {
        printf("Chave inválida. Certifique-se de que ela tenha 26 caracteres únicos e apenas "
               "letras.\n");
        return 1;
    }

    // Solicitar o texto simples ao usuário
    string plaintext = get_string("plaintext: ");

    // Inicializar o texto cifrado
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            int index = c - 'A';
            printf("%c", toupper(key[index]));
        }
        else if (islower(c))
        {
            int index = c - 'a';
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", c);
        }
    }

    // Imprimir nova linha ao final
    printf("\n");
    return 0;
}

// Função para validar a chave
bool is_valid_key(string key)
{
    // Verificar comprimento
    if (strlen(key) != 26)
    {
        return false;
    }

    // Verificar caracteres e duplicatas
    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }

    return true;
}
