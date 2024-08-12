/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_initiate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:19:32 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/12 18:07:09 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_initiate_sort(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_method(t_stack **stack_a, t_stack **stack_b);
void	ps_lg_sort(t_stack **stack_a, t_stack **stack_b);

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
