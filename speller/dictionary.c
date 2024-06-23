// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
unsigned int hash_value;
unsigned int wordcount;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);
    node *cursor = table[hash_value];
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int counter = 0;
    unsigned int firstch = toupper(word[0]) - 'A';
    if (strlen(word) >= 2)
    {
        unsigned int secondch = toupper(word[1]) - 'A';

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (firstch == i && secondch == j)
                {
                    return counter;
                }
                counter++;
            }
        }
    }

    return counter;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("unable to open %s\n", dictionary);
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            return false;
        }
        // add the word into newnode
        strcpy(newnode->word, word);
        // find the hash_value for the word
        hash_value = hash(word);
        // new node poit the first node
        newnode->next = table[hash_value];
        // new node will replace the first node
        table[hash_value] = newnode;
        wordcount++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (wordcount > 0)
    {
        return wordcount;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if (cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
