// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1985;

// Hash table
node *table[N];

//declaring wordcount for size function
int counter = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int l = strlen(word);
    char copy[l + 1]; //make a copy of every word in the text
    copy[l] = '\0';
    for (int i = 0; i < l; i++)
    {
        copy[i] =  tolower(word[i]); //change the copies to lowercase, this way they will be like in the dictionary
    }
    int index = hash(copy) % N;
    node *a = table[index]; //head of the node
    if (a != NULL)
    {
        node *p = a; //p is the cursor
        while (p != NULL)
        {
            if (strcmp(copy, p->word) == 0) //compares the text word by word to the dictionary
            {
                return true; //returns true if they match
            }
            p = p->next;
        }
    }
 return false; //else the word is misspelled
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //http://www.cse.yorku.ca/~oz/hash.html
    //hash function that I found on the internet
    unsigned int hash = 5381;
    int c;
    while ((c = *word++))
    {
       hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
       return hash;
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r"); //open file dictionary and read
    if (dict == NULL)
    {
        return false; //if nothing found return false
    }
    char out[LENGTH]; //word in dictionary
    while (fscanf(dict,"%s", out) != EOF)
    {
        int index = hash(out) % N;
        node *tmp = malloc(sizeof(node)); //allocates memory fot temporary node
        if (tmp == NULL)
        {
            return false; //if couldn't fint memory
        }
        strcpy (tmp->word, out); //copy dictionary words to hashtable
        tmp->next = table[index];
        table[index] = tmp; hash index
        counter++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter; //returns counter of words
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *p = table[i];
        while (p != NULL)
        {
            node *tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    return true;
}
