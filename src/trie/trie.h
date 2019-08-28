#ifndef TRIE_H
#define TRIE_H

typedef struct trie_s trie_t;

struct trie_s {
    char value;
    trie_t ** children;
    int endAsWord;
};

int trie_init(trie_t * t);

int trie_insert(trie_t * t, char* words, int length);

int trie_search(trie_t * t, char* words, int length);

int trie_starts_with(trie_t * t, char* prefix, int length);

#endif