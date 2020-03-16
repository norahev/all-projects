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


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
