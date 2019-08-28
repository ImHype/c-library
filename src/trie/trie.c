#include "trie.h"
#include "stdlib.h"
#include "string.h"

int trie_init(trie_t * t) {
    int size = sizeof(trie_t *) * 26;
    t->children = malloc(size);
    memset(t->children, 0, size);

    t->endAsWord = 0;
    return 0;
};

int trie_insert(trie_t * t, char* words, int length) {
    if (words != NULL) {
        for (int i = 0; i < length; i++)
        {
            char value = words[i];
            int n = value;
             
            //根据字符获取对应的子节点
            trie_t * node = t->children[n-97];

            if(node != NULL && node->value == n){//判断节点是否存在
                t = node;
            }else{//不存在则创建一个新的叶子节点,并指向当前的叶子节点
                node = malloc(sizeof(trie_t));
                trie_init(node);
                node->value= value;
                t->children[n-97] = node;
                t = node;
            }
        }
        //这个标识很重要
        t->endAsWord = 1;
    }

    return 0;
};

trie_t * trie_find(trie_t * t, char* words, int length) {
    if (words != NULL) {
        for(int i=0;i < length; i++){
            char value = words[i];
            int n = value;
            trie_t * node = t->children[n-97];
            // Trie node=currentNode.children[currentChar-97];

            if (node != NULL && node->value == value){//判断节点是否存在
                t = node;
            } else {
                return NULL;
            }
        }

        return t;
    }

    return NULL;
}

int trie_search(trie_t * t, char* words, int length) {
    trie_t * node = trie_find(t, words, length);
    return node && node->endAsWord;
};

int trie_starts_with(trie_t * t, char* prefix, int length) {
    trie_t * node = trie_find(t, prefix, length);
    
    return node != NULL;
}
