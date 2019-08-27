#ifndef BST_H
#define BST_H
#define MAX(a, b)	(a > b ? a : b)
#define GET_HEIGHT(T)	(T == NULL ? -1 : T->height)

typedef struct bst_node_t
{
    struct bst_node_t * left;
    struct bst_node_t * right;
    int value;
    void * data;
    int height;
} bst_node_t;

typedef struct bst_t
{
    bst_node_t * root;
} bst_t;

int tree_init(bst_t * tree);
int tree_visit(bst_t * tree, int (*callback)(bst_node_t * node));

int bst_visit(bst_t * tree, int (*callback)(bst_node_t * node));

bst_node_t * bst_search(bst_t * tree, int value);

int is_bst_type(bst_t * tree);

bst_t * create_bst_from_array(int arr[], int size);

int bst_init(bst_t * tree);

int bst_insert(bst_t * tree, int value);
int bst_remove(bst_t * tree, int value);
#endif