/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlg_auxiliars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:57:44 by dani              #+#    #+#             */
/*   Updated: 2024/08/11 00:39:42 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ps_find_index(t_stack *a, int value);
int		ps_maxvalue(t_stack *a);
int		ps_minvalue(t_stack *a);
void	ps_sort_three(t_stack **stack_a);

int	ps_find_index(t_stack *a, int value)
{
	int		i;

	i = 0;
	while (a->value != value)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

int	ps_maxvalue(t_stack *a)
{
	int		i;

	i = a->value;
	while (a)
	{
		if (a->value > i)
			i = a->value;
		a = a->next;
	}
	return (i);
}

int	ps_minvalue(t_stack *a)
{
	int		i;

	i = a->value;
	while (a)
	{
		if (a->value < i)
			i = a->value;
		a = a->next;
	}
	return (i);
}

void	ps_sort_three(t_stack **stack_a)
{
	if (ps_minvalue(*stack_a) == (*stack_a)->value)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ps_maxvalue(*stack_a) == (*stack_a)->value)
	{
		ft_ra(stack_a, 0);
		if (!ps_checkif_sorted(stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if (ps_find_index(*stack_a, ps_maxvalue(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}
}