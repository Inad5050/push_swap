/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:27:52 by dani              #+#    #+#             */
/*   Updated: 2024/08/12 18:18:01 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_checkif_sorted(t_stack **stack);
int	ps_min_index(t_stack **stack, int val);
int	ps_distance(t_stack **stack, int index);

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

int	ps_min_index(t_stack **stack, int val)
{
	t_stack	*current;
	int		min;

	current = *stack;
	min = current->index;
	while (current->next)
	{
		current = current->next;
		if (current->index < min && current->index != val)
			min = current->index;
	}
	return (min);
}

int	ps_distance(t_stack **stack, int index)
{
	t_stack	*current;
	int		distance;

	distance = 0;
	current = *stack;
	while (current)
	{
		if (current->index == index)
			break ;
		distance++;
		current = current->next;
	}
	return (distance);
}
