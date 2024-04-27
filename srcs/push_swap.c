#include "../includes/push_swap.h"
#include <time.h>

int main(int ac, char **av)
{

    t_stack *head;
    int *values;

    if (ac < 3)
        return (0);
    head = ft_parse(ac, av);
    int len = stack_len(head);
    values = stack_to_array(head, len);
    if (check_duplicates(values, len) < 0)
        ft_error(values, head, 2);
    if (check_sorted_stack(head, 0) == 0)
        ft_error(values, head , 0);
    free(values);
    args(len , &head);
    free_list(head, 0);
    return (0);
}