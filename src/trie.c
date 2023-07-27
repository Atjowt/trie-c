#include <string.h>

#include "trie.h"

#define CHILD(trie, key) trie->children[key - 'a']

struct TRIE
{
    TRIE* children[26];
    bool terminal;
};

TRIE* trie_create(void)
{
    return malloc(sizeof(TRIE));
}

void trie_insert(TRIE* trie, const char* string)
{
    TRIE* pointer = trie;
    for (size_t i = 0; i < strlen(string); i++)
    {
        char key = string[i];
        TRIE* child = CHILD(pointer, key);
        if (child == NULL)
        {
            child = trie_create();
            CHILD(pointer, key) = child;
        }
        pointer = child;
    }
    pointer->terminal = true;
}

TRIE* trie_search(const TRIE* trie, const char* string, bool prefix)
{
    TRIE* pointer = (TRIE*)trie;
    for (size_t i = 0; i < strlen(string); i++)
    {
        char key = string[i];
        TRIE* child = CHILD(pointer, key);
        if (child == NULL)
        {
            return NULL;
        }
        pointer = child;
    }
    return prefix || pointer->terminal ? pointer : NULL;
}

bool trie_remove(TRIE* trie, const char* string)
{
    TRIE* pointer = trie_search(trie, string, false);
    if (pointer == NULL)
    {
        return false;
    }
    pointer->terminal = false;
    return true;
}

void trie_destroy(TRIE* trie)
{
    for (char key = 'a'; key <= 'z'; key++)
    {
        TRIE* child = trie->children[key - 'a'];
        if (child != NULL)
        {
            trie_destroy(child);
        }
    }
    free(trie);
}