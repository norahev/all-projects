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
    char copy[l + 1];
    copy[l] = '\0';
    for (int i = 0; i < l; i++)
    {
        copy[i] =  tolower(word[i]);
    }
    int index = hash(copy) % N;
    node *a = table[index];
    if (a != NULL)
    {
        node *p = a;
        while (p != NULL)
        {
            if (strcmp(copy, p->word) == 0)
            {
                return true;
            }
            p = p->next;
        }
    }
 return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //http://www.cse.yorku.ca/~oz/hash.html
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
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    char out[LENGTH];
    //int n = LENGTH + 2;
    while (fscanf(dict,"%s", out) != EOF)
    {
        int index = hash(out) % N;
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            return false;
        }
        strcpy (tmp->word, out);
        tmp->next = table[index];
        table[index] = tmp;
        counter++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
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
