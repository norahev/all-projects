#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("How much change is owed?\n$"); //prompts user for number
    }
    while (change < 0.009); //repeats until number fits parameters
    int n = round(change * 100);
    int a = 25;
    int b = 10;
    int c = 5;
    int d = 1;
    int i = 0;
    while (n > 0) //repeats until change is 0
    {
        if (n >= a) //25 coins
        {
            i++;
            n = n - a;
        }
        else if (n >= b) //10 coins
        {
            i = i + 1;
            n = n - b;
        }
        else if (n >= c) //5 coins
        {
            i = i + 1;
            n = n - c;
        }
        else if (n >= d) //1 coins
        {
            i = i + 1;
            n = n - d;
        } 

    }
    printf("%i\n", i); //shows answer
} //end
