/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:01:21 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/28 13:42:46 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_radix_sort(t_stack **stack_a, t_stack **stack_b);
int		ps_max_bits(t_stack *stack);

void	ps_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	int		size_a;
	int		max_bits;
	int		i;
	int		j;

	current_a = *stack_a;
	size_a = ps_lstsize(*stack_a);
	max_bits = ps_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size_a)
		{
			current_a = *stack_a;
			if (((current_a->index >> i) & 1) == 1)
				ps_ra(stack_a);
			else
				ps_pb(stack_a, stack_b);
		}
		while (ps_lstsize(*stack_b) != 0)
			ps_pa(stack_a, stack_b);
		i++;
	}
}

int	ps_max_bits(t_stack *stack)
{
	t_stack	*current;
	int		max_index;
	int		max_bits;

	current = stack;
	max_index = current->index;
	max_bits = 0;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
