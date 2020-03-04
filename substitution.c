#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) //command line argument
{
    if (argc != 2) //if more than 2 send back error
    {
        printf("Usage: ./substituion key\n");
        return 1;
    }
    string key = argv[1]; //send error if not 26 chars
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    int n = strlen(key);
    for (int i = 0; i < n; i++)
    {
        for (int a = i + 1; a < n; a++)
        {
            if (toupper(key[i]) == toupper(key[a])) //send error if duplicates chars
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
        if (isalpha(key[i]) == false)
        {
            printf("Key must only contain alphabetic characters.\n"); //send error if not letters
            return 1;
        }
    }

    string p = get_string("plaintext: "); //prompt user for input
    printf("ciphertext: "); //first output
    for (int i = 0; i < strlen(p); i++) //counts letters in plaintext
    {
        int z = -1; //counter for the key
        int a = 65; //counter for uppercase
        if (isupper(p[i]))
        {
            do
            {
                z++;
                a++;
                key[z] = toupper(key[z]);
            }
            while (a <= p[i] && a < 91);
        }
        int b = 97; //counter for lowercase
        if (islower(p[i]))
        {
            do
            {
                z++;
                b++;
                key[z] = tolower(key[z]);
            }
            while (b <= p[i] && b < 123);
        }
        if (isalpha(p[i]) == false) //not alphabetical chars should stay the same
        {
            key[z] = p[i];
        }
        p[i] = key[z];
    }
    printf("%s", p); //chipertext
    printf("\n");

    return 0; //end
}
