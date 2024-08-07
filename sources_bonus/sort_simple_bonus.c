/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:37:56 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/07 19:55:13 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_simple_sort(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_3(t_stack **stack_a);
void	ps_sort_3_aux(t_stack **stack_a, t_stack *current, \
		int next_min, int min);
void	ps_sort_4(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_5(t_stack **stack_a, t_stack **stack_b);

void	ps_simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_lstsize(stack_a) == 2)
		ps_ra(stack_a);
	if (ps_lstsize(stack_a) == 3)
		ps_sort_3(stack_a);
	if (ps_lstsize(stack_a) == 4)
		ps_sort_4(stack_a, stack_b);
	if (ps_lstsize(stack_a) == 5)
		ps_sort_5(stack_a, stack_b);
}

void	ps_sort_3(t_stack **stack_a)
{
	t_stack	*current;
	int		min;
	int		next_min;

	current = *stack_a;
	min = ps_min_index(stack_a, -1);
	next_min = ps_min_index(stack_a, min);
	if (current->index == min && current->next->index != next_min)
	{
		ps_ra(stack_a);
		ps_sa(stack_a);
		ps_rra(stack_a);
	}
	else
		ps_sort_3_aux(stack_a, current, next_min, min);
}

void	ps_sort_3_aux(t_stack **stack_a, t_stack *current, \
int next_min, int min)
{
	if (current->index == next_min)
	{
		if (current->next->index == min)
			ps_sa(stack_a);
		else
			ps_rra(stack_a);
	}
	else
	{
		if (current->next->index == min)
			ps_ra(stack_a);
		else
		{
			ps_sa(stack_a);
			ps_rra(stack_a);
		}
	}
}

void	ps_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ps_distance(stack_a, ps_min_index(stack_a, -1));
	if (distance == 1)
		ps_ra(stack_a);
	else if (distance == 2)
	{
		ps_ra(stack_a);
		ps_ra(stack_a);
	}
	else if (distance == 3)
		ps_rra(stack_a);
	if (ps_checkif_sorted(stack_a))
		return ;
	ps_pb(stack_a, stack_b);
	ps_sort_3(stack_a);
	ps_pa(stack_b, stack_a);
}

void	ps_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ps_distance(stack_a, ps_min_index(stack_a, -1));
	if (distance == 1)
		ps_ra(stack_a);
	else if (distance == 2)
	{
		ps_ra(stack_a);
		ps_ra(stack_a);
	}
	else if (distance == 3)
	{
		ps_rra(stack_a);
		ps_rra(stack_a);
	}
	else if (distance == 4)
		ps_rra(stack_a);
	if (ps_checkif_sorted(stack_a))
		return ;
	ps_pb(stack_a, stack_b);
	ps_sort_4(stack_a, stack_b);
	ps_pa(stack_b, stack_a);
}
