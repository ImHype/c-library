#include "./linked_list.h"
#include "../toolkit.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int callback(int index, void * element) {
    printf("%d - %d\n", index, *((int *) element));
    return 0;
}

int test_linked_list() {
    linked_list_t * linked_list = malloc(sizeof(linked_list_t));

    create_linked_list(linked_list);
    
    int size = linked_list_size(linked_list);

    assert(size == 0);

    assert(linked_list_head(linked_list) == NULL);

    int arr[] = { 1, 2, 3};

    linked_list_add(linked_list, (void *)(&arr[0]));

    node_t * tmp = linked_list_head(linked_list);

    assert(tmp != NULL);

    int index0 = linked_list_index_of(linked_list, tmp->element);

    int index = linked_list_remove(linked_list, tmp->element);

    assert(index0 == index);

    assert(index > -1);

    assert(linked_list_head(linked_list) == NULL);

    assert(linked_list_is_empty(linked_list) == 1);

    linked_list_add(linked_list, (void *)(&arr[1]));

    assert((linked_list_element_at(linked_list, 0)->element) == &arr[1]);
    assert(*((int *) linked_list_element_at(linked_list, 0)->element) == arr[1]);

    linked_list_add_at(linked_list, 0, (void *)(&arr[2]));

    assert(*((int *) (linked_list_head(linked_list))->element) == arr[2]);

    linked_list_remove_at(linked_list, 0);

    assert(linked_list_head(linked_list) == NULL);

    for (int i = 0; i < ARRAY_SIZE(arr); i++)
    {
        linked_list_add(linked_list, &arr[i]);
    }

    linked_list_foreach(linked_list, &callback);

    return 0;
}


typedef struct 
{
    linked_list_t * stack1;
    linked_list_t * stack2;
} queue_t;





int init_queue(queue_t * q) {
    q->stack1 = malloc(sizeof(linked_list_t));
    create_linked_list(q->stack1);

    q->stack2 = malloc(sizeof(linked_list_t));
    create_linked_list(q->stack2);

    return 0;
}

int push_queue(queue_t * q, void * data) {
    linked_list_add(q->stack1, data);
    return 0;
}

void * shift_queue(queue_t * q) {
    if (q->stack2->length != 0) {
        return linked_list_pop(q->stack2);
    }

    while (q->stack1->length != 0)
    {
        linked_list_add(q->stack2, linked_list_pop(q->stack1));
    }

    return linked_list_pop(q->stack2);
}

int test_queue() {
    queue_t queue;
    queue_t * q = &queue;
    init_queue(q);

    int arr[] = {1, 2, 3, 4, 5};
    int arr1[5];

    for (int i = 0; i < ARRAY_SIZE(arr); i++)
    {
        push_queue(q, arr + i);
    }

    for (int i = 0; i < ARRAY_SIZE(arr); i++)
    {
        arr1[i] = *((int*) shift_queue(q));
        assert(arr1[i] == arr[i]);
    }

    return 0;
}

typedef struct 
{
    linked_list_t * queue1;
    linked_list_t * queue2;
    int temp_queue;
} my_stack_t;


int init_stack(my_stack_t * stack) {
    stack->queue1 = malloc(sizeof(linked_list_t));
    create_linked_list(stack->queue1);

    stack->queue2 = malloc(sizeof(linked_list_t));
    create_linked_list(stack->queue2);

    stack->temp_queue = 0;
    return 0;
}


int push_stack(my_stack_t* stack, void * data) {
    if (stack->temp_queue == 0) {
        linked_list_add(stack->queue1, data);
    } else {
        linked_list_add(stack->queue2, data);
    }
    return 0;
}

void * pop_stack(my_stack_t * stack) {
    linked_list_t * queue_shift = stack->temp_queue == 0 ? stack->queue1: stack->queue2;
    linked_list_t * queue_push = stack->temp_queue == 0 ? stack->queue2: stack->queue1;

    while (queue_shift->length > 1)
    {
        linked_list_add(queue_push, linked_list_shift(queue_shift));
    }

    stack->temp_queue = stack->temp_queue == 0 ? 1: 0;

    return linked_list_shift(queue_shift);
}


int test_stack() {
    my_stack_t stack;
    my_stack_t * p = &stack;

    init_stack(p);

    int arr[] = {1, 2, 3, 4, 5};
    int arr1[5];

    for (int i = 0; i < ARRAY_SIZE(arr); i++)
    {
        push_stack(p, arr + i);
    }

    for (int i = 0; i < ARRAY_SIZE(arr); i++)
    {
        arr1[i] = *((int*) pop_stack(p));
        assert(arr1[i] == arr[4 - i]);
    }

    return 0;
}

int main(int argc, char const *argv[])
{

    test_linked_list();
    test_queue();
    test_stack();

    return 0;
}
