#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    change = get_float ("How much change is owed?\n$");
    while (change < 0.009);
    int n = round(change * 100);
    int a = 25;
    int b = 10;
    int c = 5;
    int d = 1;
    int i = 0;
   while ( n > 0 )
    {
        if (n >= a)
        {
            i++;
           n = n - a;
        }
        else if (n >= b)
        {
            i = i + 1;
            n = n - b;
        }
        else if (n >= c)
        {
            i = i + 1;
            n = n - c;
        }
        else if (n >= d)
        {
            i = i + 1;
            n = n - d;
        } 

    }
    printf("%i\n", i);
}
