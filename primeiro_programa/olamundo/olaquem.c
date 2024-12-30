#include <cs50.h>
#include <stdio.h>

int main(void)

{
    // Getting user name
    string answer = get_string("Qual seu nome?");
    // Greeting user
    printf("Olá, %s.\n", answer);
}
