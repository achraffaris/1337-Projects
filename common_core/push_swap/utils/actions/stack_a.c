#include "../../push_swap.h"

void    swap_a(t_stack a)
{
    int top;

    top = a.top;
    swap(&a.arr[top], &a.arr[top - 1]);
    write(1, "sa\n", 3);
}


void    rotate_a(t_stack a)
{
    int top;
    int tmp;

    top = a.top;
    tmp = a.arr[top];
    while (top)
    {
        a.arr[top] = a.arr[top - 1];
        top--;
    }
    a.arr[top] = tmp;
    write(1, "ra\n", 3);
}

void    rev_rotate_a(t_stack a)
{
    int top;
    int tmp;
    int i;

    i = 0;
    top = a.top;
    tmp = a.arr[0];
    while (i < top)
    {
        a.arr[i] = a.arr[i + 1];
        i++;
    }
    a.arr[top] = tmp;
    write(1, "rra\n", 4);
}

void    push_a(t_stack *a, t_stack *b)
{
    if (b->arr[b->top])
    {
        add_element(a, b->arr[b->top]);
        remove_element(b);
    }
}
