// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int NumberOfWords = 0;
int hashcode = 0;
// Number of buckets in hash table
// some number of power of 2 so it will be easy to the compiler to make module
const unsigned int N = 65536;

// Hash table
node* table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    // gets the hash code from the hash function
    int code = hash(word);

    // indicates which bucket in the array to look through
    node* list = table[code];

    // iterates through the indicated linked list
    while (list != NULL)
    {
        // compares two strings case-insensitively
        if (strcasecmp(list->word, word) == 0)
        {
            return true;
        }
        else
        {
            list = list->next;
        }

    }
    return false;
}

// Hashes word to a number
// by Dan Bernstein.
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hash  = 5381;
    //unsigned int i = 0;

    for (unsigned int i = 0; word[i] != '\0'; i++)
    {
         hash  = ((hash  << 5) + hash ) + tolower(word[i]);
    }
    return hash % N;

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    // opening the given dictionary
    FILE* dict = fopen (dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // an array to store the currunt word
    char word[LENGTH + 1];

    // reads through the dictionay a word at a time
    while (fscanf(dict, "%s\n", word) != EOF)
    {
        node* new_word = malloc(sizeof(node));
        if (new_word == NULL)
        {
            free(new_word);
            return false;
        }

        // gets the hash code
        int index = hash(word);

        // creats the new node word and next pointer
        strcpy(new_word->word, word);
        new_word->next = NULL;

         if (table[index] == NULL)
        {
            // makes the head pointer to the first node in the linked list
            table[index] = new_word;
        }
        else
        {
            // inserts the new node at the beginning of the chosen linked list
            new_word->next = table[index];
            table[index] = new_word;

        }
        // increments the words counter
        NumberOfWords++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{

    return NumberOfWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // iterates through the hash table
    for (int i = 0; i < N; i++)
    {
       // creates a new node pointer points to the first node in some linked list
       node* cursor = table[i];
       while(cursor != NULL)
       {
          // another pointer points to the first node in some linked list
          node* tmp = cursor;

          // moves cursor pointer to the next node
          cursor = cursor->next;

          // frees the current node
          free(tmp);
       }
    }
    return true;
}

