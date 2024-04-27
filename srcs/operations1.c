#include "../includes/push_swap.h"

void args_5_new(int len, t_stack **head)
{
    int min_value;
    int min_value_index;
    t_stack *b_head;

    b_head = NULL;
    min_value_index = get_min_index(*head , &min_value);
    if (min_value_index < (len / 2))
    {
        while ((*head)->data != min_value)
            ra(head, 1);
    }
    else
    {
        while ((*head)->data != min_value)
            rra(head, 1);
    }
    pb(head, &b_head, 1);
    args_4_new(len - 1, head);
    pa(head, &b_head, 1);
}

void empty_stack_a(t_stack **head, t_stack **b_head, int len, int *sorted_array)
{
    int start;
    int end;

    start = 0;
    end = get_end(len);
    while ((*head) != NULL)
    {
        if ((*head)->data >= sorted_array[start] && (*head)->data <= sorted_array[end])
            {
                pb(head, b_head, 1);
                increment_border(&len, &start, &end);
                if (((*b_head)->next != NULL) && ((*b_head)->data < (*b_head)->next->data))
                    sb(b_head, 1);
            }
        else if ((*head)->data < sorted_array[start])
        {
            pb(head, b_head, 1);
            increment_border(&len, &start, &end);
                rb(b_head, 1); 
            if (((*b_head)->next != NULL) && ((*b_head)->data < (*b_head)->next->data))
                sb(b_head, 1);
        }
        else
            ra(head, 1);
    }
}
void empty_stack_b(t_stack **head, t_stack **b_head, int len)
{
    int max_value;
    int x;

    x = 0;
    max_value = 0;
    while ((*b_head) != NULL)
    {
        x = get_max_index(*b_head, &max_value);
        if (x != 0)
        {
            if (x < len / 2)
            {
                while ((*b_head)->data != max_value)
                    rb(b_head, 1);
            }
            else
            {
                while ((*b_head)->data != max_value)
                    rrb(b_head, 1);
            }
        }
        pa(head, b_head, 1);
        len--;
    }
}