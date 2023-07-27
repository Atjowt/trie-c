#include <stdlib.h>
#include <stdio.h>

#include "trie.h"

int main(void)
{
    TRIE* trie = trie_create();

    trie_insert(trie, "hello");

    if (trie_search(trie, "hello", false) != NULL)
    {
        puts("Found match!");
    }
    else 
    {
        puts("No match...");
    }

    trie_destroy(trie);

    return EXIT_SUCCESS;
}