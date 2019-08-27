#ifndef TREE_H

#define TREE_H

typedef struct tree_node_t
{
    struct tree_node_t * left;
    struct tree_node_t * right;
    int value;
    void * data;
    int height;
} tree_node_t;


tree_node_t * node_init(int value);

int node_visit(tree_node_t ** tree, int (*callback)(tree_node_t * node));

typedef struct tree_t
{
    tree_node_t * root;
} tree_t;

int tree_init(tree_t * tree);
int tree_visit(tree_t * tree, int (*callback)(tree_node_t * node));

#endif