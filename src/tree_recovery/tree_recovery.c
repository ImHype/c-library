#include "tree_recovery.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

int array_find(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int * array_cpy(int src[], int start, int size) {
    int * dist = malloc(sizeof(int) * size);

    for (size_t i = 0; i < size; i++)
    {
        dist[i] = src[start + i];
    }

    return dist;
}

int preorder_inorder_tree_recovery(int preorder[], int inorder[], int size, tree_node_t ** node) {
    if (size == 0) {
        return 0;
    }

    int root = preorder[0];

    int root_inorder_index = array_find(inorder, size, root);

    *node = node_init(root);

    int left_node_size = root_inorder_index;
    int right_node_size = size - root_inorder_index - 1;

    int * preorder_left = array_cpy(preorder, 1, left_node_size);
    int * inorder_left =  array_cpy(inorder, 0, left_node_size);
    int * preorder_right = array_cpy(preorder, left_node_size + 1, right_node_size);
    int * inorder_right = array_cpy(inorder, root_inorder_index + 1, right_node_size);

    preorder_inorder_tree_recovery(preorder_left, inorder_left, left_node_size, &((*node)->left));
    preorder_inorder_tree_recovery(preorder_right, inorder_right, right_node_size, &((*node)->right));

    return 0;
}