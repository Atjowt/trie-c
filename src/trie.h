#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct TRIE TRIE;

TRIE* trie_create(void);
void trie_insert(TRIE* trie, const char* string);
TRIE* trie_search(const TRIE* trie, const char* string, bool prefix);
bool trie_remove(TRIE* trie, const char* string);
void trie_destroy(TRIE* trie);