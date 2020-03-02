#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) //command line arguments
{
    if (argc != 2) //if there are more/less then 2 arguments, send back error message
    {
        printf("Usage : ./caesar key");
        return 1;
    }
    string keys = argv[1]; //1st argument is the key
    int n = strlen(keys);
    for (int i = 0; i < n; i++) //checking string char by char
    {
        if (isdigit(keys[i]) == false) //if input is not a digit send back error message
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    int key = atoi(keys); //if string passed previous checks, convert it to int
    string p = get_string("plaintext: "); //prompt user for text
    for (int i = 0; i < strlen(p); i++) //encrypt text
    {
        if (isupper(p[i])) //uppercase
        {
            p[i] = ((p[i] - 65) + key) % 26 + 65;
        }
        else if (islower(p[i])) //lowercase
        {
            p[i] = ((p[i] - 97) + key) % 26 + 97;
        }
        else //anything else that is not a letter, stays the same
        {
            p[i] = p[i];
        }
    }
    printf("ciphertext: %s", p); //output ciphertext
    printf("\n");
    return 0;
}