#include <cs50.h>
#include <stdio.h>

int main(void) //start
{
    long n;
    do
    {
        n = get_long("Insert credit card number: "); //prompt user for number
    }
    while (n / 10000000000000000 > 9); //reprompt until number fits
    //tears given number to digits
    int a = n / 10 % 10;
    int a1 = (a * 2) % 10;
    int a2 = (a * 2) / 10 % 10; 
    int b = n / 1000 % 10;
    int b1 = (b * 2) % 10;
    int b2 = (b * 2) / 10 % 10;
    int c = n / 100000 % 10;
    int c1 = (c * 2) % 10;
    int c2 = (c * 2) / 10 % 10;
    int d = n / 10000000 % 10;
    int d1 = (d * 2) % 10;
    int d2 = (d * 2) / 10 % 10;
    int e = n / 1000000000 % 10;
    int e1 = (e * 2) % 10;
    int e2 = (e * 2) / 10 % 10;
    int f = n / 100000000000 % 10;
    int f1 = (f * 2) % 10;
    int f2 = (f * 2) / 10 % 10;
    int g = n / 10000000000000 % 10;
    int g1 = (g * 2) % 10;
    int g2 = (g * 2) / 10 % 10;
    int h = n / 1000000000000000 % 10;
    int h1 = (h * 2) % 10;
    int h2 = (h * 2) / 10 % 10;
    //gives the sum of the multipliedd numbers
    int i = a1 + a2 + b1 + b2 + c1 + c2 + d1 + d2 + e1 + e2 + f1 + f2 + g1 + g2 + h1 + h2;
    int j = n % 10;
    int k = n / 100 % 10;
    int l = n / 10000 % 10;
    int m = n / 1000000 % 10;
    int o = n / 100000000 % 10;
    int p = n / 10000000000 % 10;
    int r = n / 1000000000000 % 10;
    int s = n / 100000000000000 % 10; 
    int q = n / 10000000000000000 % 10;
    //gives the sum of the non-multiplied numbers
    int z = j + k + l + m + o + p + r + s + q;
    int sum = i + z; //adds together all the sums
    //declares card type
    {
        if (sum % 10 == 0 && n / 1000000000000 == 4)
        {
            printf("Visa\n"); 
        }
        else if (sum % 10 == 0 && n / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else if (sum % 10 == 0 && n / 100000000000000 == 51)
        {
            printf("MASTERCARD\n");
        }
        else if (sum % 10 == 0 && n / 100000000000000 == 52)
        {
            printf("MASTERCARD\n");
        }
        else if (sum % 10 == 0 && n / 100000000000000 == 53)
        {
            printf("MASTERCARD\n");
        }
        else if (sum % 10 == 0 && n / 100000000000000 == 54)
        {
            printf("MASTERCARD\n");
        }
        else if (sum % 10 == 0 && n / 100000000000000 == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (sum % 10 == 0 && n / 10000000000000 == 34)
        {
            printf("AMEX\n");
        }
        else if (sum % 10 == 0 && n / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else //prints invalid for wrong numbers
        {
            printf("INVALID\n");
        }
    }
}//end
