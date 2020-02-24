#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: "); //prompt user for number
    }
    while (h < 1 || h > 8); //repeat until number fits parameters
    for (int l = 0; l < h; l++)
    {
        for (int d = l; d < h - 1; d++) //spaces on left 
        {
            printf(" ");
        }
        {
            for (int f = 0; f <= l; f++) //left side of pyramid
            {
                printf("#");
            }
        }
        for (int g = 0; g < 1; g++) //spaces inbetween pyramids
        {
            printf("  ");
        }
        for (int n = 0; n <= l; n++) //right pyramid
        {
            printf("#");
        }
        printf("\n");
    }

} //end
