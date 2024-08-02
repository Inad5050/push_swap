/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:19:32 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/28 16:21:28 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_initiate_sort(t_stack **stack_a, t_stack **stack_b);
int		ps_checkif_sorted(t_stack **stack);
void	ps_assign_index(t_stack *stack);
void	ps_sort(t_stack **stack_a, t_stack **stack_b);

void	ps_initiate_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_checkif_sorted(stack_a) == 1)
	{
		ps_free_stack(stack_a);
		ps_free_stack(stack_b);
		return ;
	}
	ps_assign_index(*stack_a);
	ps_sort(stack_a, stack_b);
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

void	ps_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_lstsize(*stack_a) <= 5)
		ps_simple_sort(stack_a, stack_b);
	else
		ps_radix_sort(stack_a, stack_b);
}
