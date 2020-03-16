#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avr = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avr = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(avr);
            image[i][j].rgbtGreen = round(avr);
            image[i][j].rgbtRed = round(avr);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaR = 0;
    float sepiaG = 0;
    float sepiaB = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaR = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sepiaG = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sepiaB = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            if (sepiaR <=255.0 && sepiaR >= 0.0)
            {
                image[i][j].rgbtRed = round(sepiaR);
            }
            if (sepiaG <= 255.0 && sepiaG >= 0.0)
            {
                image[i][j].rgbtGreen = round(sepiaG);
            }
            if (sepiaB <=255.0 && sepiaB > 0.0)
            {
                image[i][j].rgbtBlue = round(sepiaB);
            }
            if (sepiaR > 255.0)
            {
                image[i][j].rgbtRed = 255;
            }
            if (sepiaG > 255.0)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiaB > 255.0)
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int half = round((float)1/2 * width);
        for (int j = 0; j < width; j++)
        {
            while (j < half)
            {
                RGBTRIPLE t = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j -1] = t;
                break;
            }
        }
    }
}

int helpblur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int RGB)
{
    float counter = 0;
    int sum = 0;
    for (int k = i - 1; k < (i + 2); k++)
    {
        for (int l = j - 1; l < (j + 2); l++)
        {
            if (k < 0 || l < 0 || k >= height || l >= width)
            {

            }
            else
            {
                if (RGB == 0)
                {
                    sum += image[k][l].rgbtRed;
                }
                else if (RGB == 1)
                {
                    sum += image[k][l].rgbtBlue;
                }
                else
                {
                    sum += image[k][l].rgbtGreen;
                }
                counter++;
            }
        }
    }
    return round(sum / counter);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
   {
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = helpblur(i, j, height, width, copy, 0);
            image[i][j].rgbtBlue = helpblur(i, j, height, width, copy, 1);
            image[i][j].rgbtGreen = helpblur(i, j, height, width, copy, 2);
        }
    }
    return;
   }
}
