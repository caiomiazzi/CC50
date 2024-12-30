#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calcular a média de R, G e B
            BYTE average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Atualizar R, G e B com a média
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Trocar os pixels simetricamente
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Copiar a matriz original para temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Iterar sobre cada pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int count = 0;

            // Iterar sobre os vizinhos
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di, nj = j + dj;

                    // Verificar se o vizinho está dentro dos limites
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        totalRed += temp[ni][nj].rgbtRed;
                        totalGreen += temp[ni][nj].rgbtGreen;
                        totalBlue += temp[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calcular a média e atualizar o pixel
            image[i][j].rgbtRed = round(totalRed / (float)count);
            image[i][j].rgbtGreen = round(totalGreen / (float)count);
            image[i][j].rgbtBlue = round(totalBlue / (float)count);
        }
    }
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Copiar a matriz original para temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Kernels de Sobel
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Iterar sobre cada pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redX = 0, greenX = 0, blueX = 0;
            int redY = 0, greenY = 0, blueY = 0;

            // Iterar sobre os vizinhos
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di, nj = j + dj;

                    // Verificar se o vizinho está dentro dos limites
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redX += temp[ni][nj].rgbtRed * Gx[di + 1][dj + 1];
                        greenX += temp[ni][nj].rgbtGreen * Gx[di + 1][dj + 1];
                        blueX += temp[ni][nj].rgbtBlue * Gx[di + 1][dj + 1];

                        redY += temp[ni][nj].rgbtRed * Gy[di + 1][dj + 1];
                        greenY += temp[ni][nj].rgbtGreen * Gy[di + 1][dj + 1];
                        blueY += temp[ni][nj].rgbtBlue * Gy[di + 1][dj + 1];
                    }
                }
            }

            // Calcular a magnitude
            image[i][j].rgbtRed = fmin(round(sqrt(redX * redX + redY * redY)), 255);
            image[i][j].rgbtGreen = fmin(round(sqrt(greenX * greenX + greenY * greenY)), 255);
            image[i][j].rgbtBlue = fmin(round(sqrt(blueX * blueX + blueY * blueY)), 255);
        }
    }
}

