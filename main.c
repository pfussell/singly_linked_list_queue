#ifndef __cplusplus 
typedef char bool;
#define true 1
#define false 0
#endif

struct list_element
{
    struct list_element * next;
};
typedef struct list_element list_element;

typedef struct
{
    list_element * first;
    list_element * last;
} list;

void list_init(list * container)
{
    container->first = 0;
    container->last = 0;
}

bool list_empty(list * container)
{
    return 0 == container->first;
}

list_element * list_begin(list * container)
{
    return container->first;
}

list_element * list_next(list_element * element)
{
    return element->next;
}

list_element * list_pop_front(list * container)
{
    list_element * element = container->first;
    container->first = container->first->next;
    return element;
}

void list_push_back(list * container, list_element * element)
{
    if (list_empty(container))
    {
        container->first = element;
        container->last = element;
    }
    else
    {
        container->last->next = element;
        container->last = element;
    }
    
    element->next = 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    list_element header;
    int value;
    
} item;

int main()
{
    list items;
    item * a = (item *) malloc(sizeof(item));
    item * b = (item *) malloc(sizeof(item));
    item * c = (item *) malloc(sizeof(item));
    
    a->value = 1;
    b->value = 2;
    c->value = 3;
    
    list_init(&items);
    
    list_push_back(&items, &a->header);
    list_push_back(&items, &b->header);
    list_push_back(&items, &c->header);
    
    printf("empty %d\n", list_empty(&items));
    
    for (a = (item *) list_begin(&items); a; a = (item *) list_next(&a->header))
    {
        printf("%d\n", a->value);
    }
    
    while (!list_empty(&items))
    {
        a = (item *) list_pop_front(&items);
        printf("%d\n", a->value);
        printf("empty %d\n", list_empty(&items));
        free(a);
    }
    
    return 0;
}
