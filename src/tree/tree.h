#ifndef TREE_H

#define TREE_H

typedef struct tree_node_t
{
    struct tree_node_t * left;
    struct tree_node_t * right;
    int value;
    void * data;
} tree_node_t;


tree_node_t * node_init(int value);
tree_node_t * node_search(tree_node_t ** tree, int value);
int node_visit(tree_node_t ** tree, int (*callback)(tree_node_t * node));
int node_add_node(tree_node_t ** tree, tree_node_t * node);


typedef struct tree_t
{
    tree_node_t * root;
} tree_t;

int tree_init(tree_t * tree);
tree_node_t * tree_search(tree_t * tree, int value);
int tree_visit(tree_t * tree, int (*callback)(tree_node_t * node));

int tree_add_node(tree_t * tree, int value);

#endif