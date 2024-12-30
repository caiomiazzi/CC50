#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Função para contar os dígitos de um número
int count_digits(long num)
{
    int count = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

// Função para identificar o tipo do cartão
string identify_card_type(long card_number, int num_digits)
{
    int first_two = card_number / (long) pow(10, num_digits - 2);
    int first_one = card_number / (long) pow(10, num_digits - 1);

    if ((first_two == 34 || first_two == 37) && num_digits == 15)
    {
        return "AMEX";
    }
    else if (first_two >= 51 && first_two <= 55 && num_digits == 16)
    {
        return "MASTERCARD";
    }
    else if (first_one == 4 && (num_digits == 13 || num_digits == 16))
    {
        return "VISA";
    }
    return "INVALID";
}

// Função para validar o número do cartão usando o Algoritmo de Luhn
bool validate_luhn(long card_number)
{
    int sum = 0;
    int is_second = 0;

    while (card_number > 0)
    {
        int digit = card_number % 10;
        if (is_second)
        {
            int product = digit * 2;
            sum += (product / 10) + (product % 10); // Soma dos dígitos do produto
        }
        else
        {
            sum += digit;
        }
        card_number /= 10;
        is_second = !is_second;
    }

    return (sum % 10 == 0);
}

int main(void)
{
    // Solicitar o número do cartão
    long card_number = get_long("Número: ");

    // Contar os dígitos do número
    int num_digits = count_digits(card_number);

    // Verificar se o número de dígitos é válido
    if (num_digits != 13 && num_digits != 15 && num_digits != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Validar o número usando o Algoritmo de Luhn
    if (!validate_luhn(card_number))
    {
        printf("INVALID\n");
        return 0;
    }

    // Identificar o tipo do cartão
    string card_type = identify_card_type(card_number, num_digits);
    printf("%s\n", card_type);
}
