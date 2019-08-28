#include "trie.h"
#include "assert.h"
#include "string.h"

int main() {
    trie_t trie;
    trie_t * t = &trie;

    char str[] = "hello";
    char str_part[] = "hell";

    trie_init(t);
    trie_insert(t, str, 5);

    assert(trie_search(t, str, strlen(str)) == 1);
    assert(trie_search(t, str_part, strlen(str_part)) == 0);

    assert(trie_starts_with(t, str_part, strlen(str_part)) == 1);

    return 0;
}