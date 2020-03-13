#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avr = 0;
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            do
            {
                avr = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
                image[i][j].rgbtBlue = avr;
                image[i][j].rgbtGreen = avr;
                image[i][j].rgbtRed = avr;
            }
            while (avr <= 255);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
