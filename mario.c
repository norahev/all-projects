#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: "); //prompt user for number
    }
    while(h < 1 || h > 8); //repeat until number fits parameters
    for(int l = 0; l < h; l++)
    {
        for(int d = l; d < h; d++)
        {
            printf(" ");
        }
        {
            for(int f = 0; f <= l; f++)
            {
                printf("#");
            }
        }
        for(int g = 0; g < 2; g++)
        {
            printf("  ");
        }
        for(int n = 0; n <= l; n++)
            {
                printf("#");
            }
        printf("\n");
    }

}
