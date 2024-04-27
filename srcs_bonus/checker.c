#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int is_valid_arg(char *str)
{
    int i;

    i = 0;
    if (ft_strlen(str) != 3 && ft_strlen(str) != 4)
        return (-1);
    char *args[]= {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
    while (i < 11)
    {
        if (strncmp(str, args[i], ft_strlen(args[i])) == 0)
            return (0);
        i++;
    }
    return (-1);
}
int ft_strncmp(char *s1, char *s2, int len)
{
  int i;

  i = 0;

  while (s1[i] && i < len)
  {
    if (s1[i] != s2[i])
      return (1);
    i++;
  }
  return (0);
}

int get_instruction(t_stack **head, t_stack **b_head)
{
    char *line;

    while (1)
    {
        line = get_next_line(0);
        if (line == NULL || is_valid_arg(line) < 0)
        {
            if (line == NULL)
                break;
            write (2, "Error\n", 6);
            return (-1);
        }
        apply_instruction(head, b_head, line);
        free(line);
    }
    if (*b_head != NULL)
        checker_error_handle(head, b_head);
    return (0);
}


int apply_instruction(t_stack **head, t_stack **b_head, char *line)
{
  if (strncmp(line, "pa", strlen(line) - 1) == 0)
    return (pa(head, b_head, 0));
  if (strncmp(line, "pb", strlen(line) - 1) == 0)
    return (pb(head, b_head, 0));
  if (strncmp(line, "sa", strlen(line) - 1) == 0)
    return (sa(head, 0));
  if (strncmp(line, "sb", strlen(line) - 1) == 0)
    return (sb(b_head, 0));
  if (strncmp(line, "ss", strlen(line) - 1) == 0)
    return (ss(head, b_head, 0));
  if (strncmp(line, "ra", strlen(line) - 1) == 0)
    return (ra(head, 0));
  if (strncmp(line, "rr", strlen(line) - 1) == 0)
    return (rr(head, b_head, 0));
  if (strncmp(line, "rb", strlen(line) - 1) == 0)
    return (rb(b_head, 0));
  if (strncmp(line, "rra", strlen(line) - 1) == 0)
    return (rra(head, 0));
  if (strncmp(line, "rrb", strlen(line) - 1) == 0)
    return (rrb(b_head, 0));
  if (strncmp(line, "rrr", strlen(line) - 1) == 0)
    return (rrr(head, b_head, 0));
  return (0);
}

int main(int ac, char **av)
{
  t_stack *head;
  int *values;
  t_stack *b_head;
  int len;

  b_head = NULL;
  if (ac < 3) /* or 2 ?*/
    return (0);
  head = ft_parse(ac, av);
  if (check_sorted_stack(head, 0) == 0)
    return (0);
  len = stack_len(head);
  values = stack_to_array(head, len);
  if (check_duplicates(values, len) < 0)
      ft_error(values, head, 2);
  free(values);
  if (get_instruction(&head, &b_head) < 0)
  {
    free_list(head, 0);
    free_list(b_head, 0);
    return (0);
  }
  check_sorted_stack(head, 1);
  free_list(head, 0);
  return (0);  
}