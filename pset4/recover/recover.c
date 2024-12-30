#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Definir BYTE como uint8_t
typedef uint8_t BYTE;

// Tamanho de cada bloco no arquivo
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Verificar se o programa foi chamado corretamente
    if (argc != 2)
    {
        printf("Uso: ./recover imagem\n");
        return 1;
    }

    // Abrir o arquivo fornecido
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    // Criar buffer para leitura dos blocos
    BYTE buffer[BLOCK_SIZE];

    // Variáveis para gerenciar os arquivos JPEG
    FILE *output_file = NULL;
    char filename[8]; // Para armazenar nomes como "000.jpg"
    int file_count = 0;

    // Ler blocos de 512 bytes até o final do arquivo
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        // Verificar se o bloco é o início de um JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Se já há um arquivo aberto, fechá-lo
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Criar novo arquivo para o JPEG
            sprintf(filename, "%03d.jpg", file_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                printf("Erro: Não foi possível criar o arquivo %s\n", filename);
                fclose(input_file);
                return 1;
            }

            // Incrementar o contador de arquivos
            file_count++;
        }

        // Se um arquivo está aberto, escrever o bloco atual nele
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
        }
    }

    // Fechar quaisquer arquivos abertos
    if (output_file != NULL)
    {
        fclose(output_file);
    }
    fclose(input_file);

    return 0;
}
