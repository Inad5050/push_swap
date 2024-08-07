/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_initiate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:19:32 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/07 19:55:08 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv);
void	ps_assign_index(t_stack *stack);
void	ps_initiate_sort(t_stack **stack_a, t_stack **stack_b);
int		ps_checkif_sorted(t_stack **stack);
void	ps_sort_method(t_stack **stack_a, t_stack **stack_b);

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

int	ps_checkif_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ps_sort_method(t_stack **stack_a, t_stack **stack_b)
{
/* 	ft_printf("STACKA\n");
	ps_lstprint(*stack_a);
	ft_printf("STACKB\n");
	ps_lstprint(*stack_b); */
	if (ps_lstsize(stack_a) <= 5)
		ps_simple_sort(stack_a, stack_b);
	else
		ps_radix_sort(stack_a, stack_b);
/* 	ft_printf("STACKA\n");
	ps_lstprint(*stack_a);
	ft_printf("STACKB\n");
	ps_lstprint(*stack_b); */
}
