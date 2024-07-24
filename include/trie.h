#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct Trie Trie;

Trie* trie_create(void);
void trie_insert(Trie* trie, const char* word);
Trie* trie_search(Trie* trie, const char* word, bool is_prefix);
bool trie_remove(Trie* trie, const char* word);
void trie_destroy(Trie* trie);