#include "stdlib.h"
#include "linked_list.h"

int create_linked_list(linked_list_t * linked_list) {
    linked_list->length = 0;
    linked_list->head = NULL;
    return 0;
}

int linked_list_size(linked_list_t * linked_list) {
    return linked_list->length;
}


linked_list_node_t * linked_list_head(linked_list_t * linked_list) {
    return linked_list->head;
}
linked_list_node_t * create_node(void * element) {
    linked_list_node_t * node = malloc(sizeof(linked_list_node_t));
    node->element = element;
    node->next = NULL;

    return node;
}

int linked_list_add(linked_list_t * linked_list, void * element) {
    linked_list_node_t * node = create_node(element);

    linked_list_node_t ** n;
    n = &(linked_list->head);

    while (*n != NULL)
    {
        n = &(*n)->next;
    }

    *n = node;
    linked_list->length++;

    return 0;
}


int linked_list_remove(linked_list_t * linked_list, void * element) {
    int i = 0;
    linked_list_node_t ** n;
    linked_list_node_t * p;
    n = &(linked_list->head);

    while (*n != NULL)
    {
        if ((*n)->element == element) {
            p = *n;
            (*n) = p->next;
            free(p);
            linked_list->length--;
            return i;
        }

        n = &(*n)->next;
        i++;
    }

    return -1;
};


int linked_list_is_empty(linked_list_t * linked_list) {
    return linked_list_size(linked_list) == 0;
};


int linked_list_index_of(linked_list_t * linked_list, void * element) {
    int i = 0;
    linked_list_node_t ** n;
    n = &(linked_list->head);

    while (*n != NULL)
    {
        if ((*n)->element == element) {
            return i;
        }

        n = &(*n)->next;
        i++;
    }

    return -1;
};


linked_list_node_t * linked_list_element_at(linked_list_t * linked_list, int index) {
    int i = 0;
    linked_list_node_t ** n;

    n = &(linked_list->head);

    while (i < index)
    {
        if (*n == NULL) {
            return NULL;        
        }

        n = &(*n)->next;

        i++;
    }

    return *n;
};

int linked_list_add_at(linked_list_t * linked_list, int index, void * element) {
    int i = 0;
    linked_list_node_t ** n;
    n = &(linked_list->head);

    while (i < index)
    {
        if (*n == NULL) {
            (*n) = create_node(NULL);
        }

        n = &(*n)->next;
        i++;
    }

    linked_list_node_t * node = create_node(element);

    node->next = *n;

    (*n) = node;

    linked_list->length ++;

    return 0;
};


int linked_list_remove_at(linked_list_t * linked_list, int index) {
    int i = 0;
    linked_list_node_t ** n;
    linked_list_node_t * p;

    n = &(linked_list->head);

    while (i < index)
    {
        if (*n == NULL) {
            return -1;
        }

        n = &(*n)->next;
        i++;
    }

    p = *n;
    (*n) = p->next;
    free(p);

    linked_list->length--;

    return 0;
};


void * linked_list_remove_at_returned(linked_list_t * linked_list, int index) {
    int i = 0;
    linked_list_node_t ** n;
    linked_list_node_t * p;

    n = &(linked_list->head);

    while (i < index)
    {
        if (*n == NULL) {
            return NULL;
        }

        n = &(*n)->next;
        i++;
    }

    p = *n;
    (*n) = p->next;

    linked_list->length--;

    return p->element;
};



int linked_list_foreach(linked_list_t * linked_list, int (*callback)(int index, void *)) {
    int i = 0;
    linked_list_node_t ** n;
    n = &(linked_list->head);

    while (*n != NULL)
    {
        callback(i, (*n)->element);
        n = &(*n)->next;
        i++;
    }

    return 0;
};

void * linked_list_pop(linked_list_t * linked_list) {
    return linked_list_remove_at_returned(linked_list, linked_list->length - 1);
}

void * linked_list_shift(linked_list_t * linked_list) {
    return linked_list_remove_at_returned(linked_list, 0);
}

int linked_list_unshift(linked_list_t * linked_list, void * element) {
    return linked_list_add_at(linked_list, 0, element);
}