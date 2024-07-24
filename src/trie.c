#include "trie.h"

#define KEYS 26
#define CHILD(node, key) node->children[key - 'a']

struct Trie {
    Trie* children[KEYS];
    bool is_tail;
};

Trie* trie_create(void) {
    return malloc(sizeof(Trie));
}

void trie_insert(Trie* trie, const char* word) {
    Trie* node = trie;
    while (*word) {
        char key = *word;
        Trie* next = CHILD(node, key);
        if (next == NULL) {
            next = trie_create();
            CHILD(node, key) = next;
        }
        node = next;
        word++;
    }
    node->is_tail = true;
}

Trie* trie_search(Trie* trie, const char* word, bool is_prefix) {
    Trie* node = trie;
    while (*word) {
        char key = *word;
        Trie* child = CHILD(node, key);
        if (child == NULL) {
            return NULL;
        }
        node = child;
        word++;
    }
    return (is_prefix || node->is_tail) ? node : NULL;
}

bool trie_remove(Trie* trie, const char* word) {
    Trie* pointer = trie_search(trie, word, false);
    if (pointer == NULL) {
        return false;
    }
    pointer->is_tail = false;
    return true;
}

void trie_destroy(Trie* trie) {
    if (trie == NULL) return;
    for (size_t i = 0; i < KEYS; i++) {
        trie_destroy(trie->children[i]);
    }
    free(trie);
}