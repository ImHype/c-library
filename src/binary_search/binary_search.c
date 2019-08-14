#include "binary_search.h"

int binary_search(int arr[], int start, int end, int data) {
    if (end < start) {
        return -1;
    }

    int idx = start + ((end - start) / 2);

    if (arr[idx] == data) {
        return idx;
    }
    
    if (data < arr[idx])
    {
        return binary_search(arr, start, idx, data);
    }

    return binary_search(arr, idx + 1, end, data);
}