#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float word;
float letter;
float sentence;
int main(void)
{
    string text = get_string("Text: "); //prompt user for input
    printf("Text:%s\n", text);
    int lenght = strlen(text); //lenght of text
    if isalnum(text[0]) //if first character of text is number/letter set wordcount to 1
    word = 1;
    for(int i = 0; text[i] != '\0'; i++) //repeat until end of text, check characters if they are letters
    {
        isalpha(text[i]);
        {
            if(isalpha(text[i])) //count leetters
            letter++;
        }
        {
            if(text[i] == ' ' && isalnum(text[i + 1])) //count words
            word++;
        }
        {
            if(text[i] =='.' || text[i] == '!' || text[i] == '?') //count sentences
            sentence++;
        }
    }
    //coleman-liau index
    float L = (letter / word) * 100;
    float S = (sentence / word) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //output of grades
    if(index < 1)
    {
        printf("Before grade 1");
    }
    else if(index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %.0f", index);
    }
    printf("\n");
} //end

