#include "bst.h"
#include "stdlib.h"
#include "stdio.h"

bst_node_t * create_node(int value) {
    bst_node_t * node = malloc(sizeof(bst_node_t));

    node->left = NULL;
    node->right = NULL;
    node->value = value;
    node->height = 0;

    return node;
};

int node_visit(bst_node_t ** tree, int (*callback)(bst_node_t * node)) {
    bst_node_t * p = *tree;

    if (p == NULL) {
        return 0;
    }

    node_visit(&p->left, callback);

    callback(p);

    node_visit(&p->right, callback);

    return 0;
};

int tree_init(bst_t * tree) {
    tree->root = NULL;
    return 0;
}

int tree_visit(bst_t * tree, int (*callback)(bst_node_t * node)) {
    return node_visit(&tree->root, callback);
};

bst_node_t * node_search(bst_node_t ** tree, int value) {
    bst_node_t * p = *tree;

    if (p == NULL) {
        return NULL;
    }

    if (p->value == value) {
        return p;
    }

    if (value < p->value) {
        return node_search(&p->left, value);
    }

    return node_search(&p->right, value);
};


int ll_rotate(bst_node_t ** tree) {
    bst_node_t * node =  *tree;
    bst_node_t * node_l =  (*tree)->left;

    node->left = node_l->right;

    node_l->right = node;

    *tree = node_l;

    // node is (*tree)->right
    node->height = MAX(GET_HEIGHT(node->left), GET_HEIGHT(node->right)) + 1;
    // (*tree)->right 不需要调整高度
	// (*tree)->right->height = MAX(GET_HEIGHT((*tree)->right->left), GET_HEIGHT((*tree)->right->right)) + 1;

    // node_l is *tree
    node_l->height = MAX(GET_HEIGHT(node_l->left), GET_HEIGHT(node_l->right)) + 1;

    return 0;
}


int rr_rotate(bst_node_t ** tree) {
    bst_node_t * node =  *tree;
    bst_node_t * node_r =  (*tree)->right;

    node->right = node_r->left;

    node_r->left = node;

    *tree = node_r;

    // node is (*tree)->left
    node->height = MAX(GET_HEIGHT(node->left), GET_HEIGHT(node->right)) + 1;
    // (*tree)->right 不需要调整高度
	// (*tree)->right->height = MAX(GET_HEIGHT((*tree)->right->left), GET_HEIGHT((*tree)->right->right)) + 1;

    // node_r is *tree
    node_r->height = MAX(GET_HEIGHT(node_r->left), GET_HEIGHT(node_r->right)) + 1;

    return 0;
}

int lr_rotate(bst_node_t ** tree) {
    bst_node_t * node = *tree;

    rr_rotate(&node->left);
    ll_rotate(tree);

    return 9;
}

int rl_rotate(bst_node_t ** tree) {
    ll_rotate(&(*tree)->right);
    rr_rotate(tree);
    return 0;
}

int insert(bst_node_t ** tree, bst_node_t * node) {
    bst_node_t * p = *tree;

    if (p == NULL) {
        *tree = node;
        return 0;
    }

    if (node->value < p->value) {
        insert(&(p->left), node);

        if(GET_HEIGHT(p->left) - GET_HEIGHT(p->right) == 2) {
			if(node->value < p->left->value) {
                // ll
                ll_rotate(tree);
            } else {
                // lr
				lr_rotate(tree);
            }
        }
    } else {
        insert(&p->right, node);
        
        if(GET_HEIGHT(p->right) - GET_HEIGHT(p->left) == 2) {
			if (node->value > p->right->value) {
                // rr
                rr_rotate(tree);
            } else {
                // rl
                rl_rotate(tree);
            }
        }
    }

    p->height = MAX(GET_HEIGHT(p->left), GET_HEIGHT(p->right)) + 1;

    return 0;
};

bst_node_t * find_min(bst_node_t * node) {
    if(node == NULL) 
        return NULL;
    else if(node->left == NULL)
        return node;
    else 
        return find_min(node->left);
}

int _remove(bst_node_t ** tree, int value) {
    bst_node_t * p = *tree;

    if (p == NULL) {
        return -1;
    }

    if (p->value == value) {
        if (p->left && p->right) {
            if (GET_HEIGHT(p->right) > GET_HEIGHT(p->left)) {
                bst_node_t * tmp = find_min(p->right);

                p->value = tmp->value;
                p->data = tmp->data;

                _remove(&p->right, tmp->value);
            } else {
                bst_node_t * tmp = find_min(p->left);

                p->value = tmp->value;
                p->data = tmp->data;

                _remove(&p->left, tmp->value);
            }
        } else {
            *tree = (p->left) ? p->left : p->right;
            free(p);
        }
    } else if (value < p->value) {
        _remove(&(*tree)->left, value);
        p = *tree;

        if (GET_HEIGHT(p->right) - GET_HEIGHT(p->left) == 2) {
            bst_node_t * tmp = p->right;

            if (GET_HEIGHT(tmp->left) > GET_HEIGHT(tmp->right)) {
                // rl
                rl_rotate(tree);
            } else {
                // rr
                rr_rotate(tree);
            }
        }
    } else {

        if (GET_HEIGHT(p->left) - GET_HEIGHT(p->right) == 2) {
            bst_node_t * tmp = p->left;

            if (GET_HEIGHT(tmp->left) > GET_HEIGHT(tmp->right)) {
                // ll
                ll_rotate(tree);
            } else {
                // lr
                lr_rotate(tree);
            }
        }
        _remove(&(*tree)->right, value);
    }

    return 0;
}

int is_bst_node(bst_node_t * tree) {
    if (!tree || !tree->left || !tree->right) {
        return 1;
    }

    return (tree->left->value < tree->value && tree->right->value > tree->value) && is_bst_node(tree->left) && is_bst_node(tree->right);
};


int bst_init(bst_t * tree) {
    return tree_init(tree);
}

bst_node_t * bst_search(bst_t * tree, int value) {
    return node_search(&tree->root, value);
};


int bst_insert(bst_t * tree, int value) {
    return insert(&tree->root, create_node(value));;
};


int bst_remove(bst_t * tree, int value) {
    return _remove(&tree->root, value);
};


int is_bst_type(bst_t * tree) {
    return is_bst_node(tree->root);
};


bst_t * create_bst_from_array(int arr[], int size) {
    bst_t * tree = malloc(sizeof(bst_t));

    tree_init(tree);

    for (int i = 0; i < size; i++)
    {
        bst_insert(tree, arr[i]);
    }

    return tree;
}