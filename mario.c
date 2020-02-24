#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: "); //prompt user for number
    }
    while (n < 1 || n > 8); //repeat until number fits the parameters
    for (int i = 0; i < n; i++) //determines and repeats line #
    {
        for (int k = i; k < n - 1; k++)
        { 
            printf(" ");
        }

        {
            for (int j = 0; j <= i; j++)
            {
                printf("#");
            }
            printf("\n");

        }//end
    }


}
