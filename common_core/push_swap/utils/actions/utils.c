#include "../../push_swap.h"

void    swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    add_element(t_stack *a, int n)
{
    int *arr;
    int i;
    int top;

    top = a->top;
    i = 0;
    arr = malloc(sizeof(int ) * (a->size + 1));
    if (!arr)
        raise_error();
    while (i <= top)
    {
        arr[i] = a->arr[i];
        i++;
    }
    arr[i] = n;
    free(a->arr);
    a->arr = arr;
    a->top++;
    a->size++;
}

void    remove_element(t_stack *b)
{
    int *arr;
    int i;
    int top;

    top = b->top--;
    i = 0;
    arr = malloc(sizeof(int ) * (b->size - 1));
    if (!arr)
        raise_error();
    while (i <= top)
    {
        arr[i] = b->arr[i];
        i++;
    }
    free(b->arr);
    b->arr = arr;
    b->size--;
}