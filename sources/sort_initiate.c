/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_initiate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:19:32 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/11 00:34:51 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv);
void	ps_assign_index(t_stack *stack);
void	ps_initiate_sort(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_method(t_stack **stack_a, t_stack **stack_b);
void	ps_lg_sort(t_stack **stack_a, t_stack **stack_b);

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &(argv[1]);
	while (args[i])
	{
		new = ps_lstnew(ft_atoi(args[i]));
		ps_lstadd_back(stack_a, new);
		i++;
	}
	ps_assign_index(*stack_a);
	if (argc == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
}

void	ps_assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		i;

	current = stack;
	while (current)
	{
		i = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}

void	ps_initiate_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_checkif_sorted(stack_a) == 1)
	{
		ps_free_stack(stack_a);
		ps_free_stack(stack_b);
		return ;
	}
	ps_sort_method(stack_a, stack_b);
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
}

void	ps_sort_method(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_lstsize(*stack_a) <= 5)
		ps_simple_sort(stack_a, stack_b);
	else
		ps_lg_sort(stack_a, stack_b);
}

void	ps_lg_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	stack_b = ps_sort_b(stack_a, stack_b);
	stack_a = ps_sort_a(stack_a, stack_b);
	i = ps_find_index(*stack_a, ps_minvalue(*stack_a));
	if (i < ps_lstsize(*stack_a) - i)
	{
		while ((*stack_a)->value != ps_minvalue(*stack_a))
			ft_ra(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->value != ps_minvalue(*stack_a))
			ft_rra(stack_a, 0);
	}			
}	