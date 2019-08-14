#include "binary_search.h"
#include "assert.h"
#include "../toolkit.h"


int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4};

    assert(binary_search(arr, 0, ARRAY_SIZE(arr) - 1, 1) == 0);
    assert(binary_search(arr, 0, ARRAY_SIZE(arr) - 1, 2) == 1);
    assert(binary_search(arr, 0, ARRAY_SIZE(arr) - 1, 3) == 2);
    assert(binary_search(arr, 0, ARRAY_SIZE(arr) - 1, 4) == 3);
    assert(binary_search(arr, 0, ARRAY_SIZE(arr) - 1, 5) == 4);

    assert(binary_search(arr2, 0, ARRAY_SIZE(arr2) - 1, 1) == 0);
    assert(binary_search(arr2, 0, ARRAY_SIZE(arr2) - 1, 2) == 1);
    assert(binary_search(arr2, 0, ARRAY_SIZE(arr2) - 1, 3) == 2);
    assert(binary_search(arr2, 0, ARRAY_SIZE(arr2) - 1, 4) == 3);
    return 0;
}
