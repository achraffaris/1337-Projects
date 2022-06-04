#include "../../push_swap.h"

void    swap_b(t_stack b)
{
    int top;

    top = b.top;
    swap(&b.arr[top], &b.arr[top - 1]);
    write(1, "sb\n", 3);
}

void    rotate_b(t_stack b)
{
    int top;
    int tmp;

    top = b.top;
    tmp = b.arr[top];
    while (top)
    {
        b.arr[top] = b.arr[top - 1];
        top--;
    }
    b.arr[top] = tmp;
    write(1, "rb\n", 3);
}

void    rev_rotate_b(t_stack b)
{
    int top;
    int tmp;
    int i;

    i = 0;
    top = b.top;
    tmp = b.arr[0];
    while (i < top)
    {
        b.arr[i] = b.arr[i + 1];
        i++;
    }
    b.arr[top] = tmp;
    write(1, "rrb\n", 4);
}


void    push_b(t_stack *a, t_stack *b)
{
    if (a->arr[a->top])
    {
        add_element(b, a->arr[a->top]);
        remove_element(a);
    }
}