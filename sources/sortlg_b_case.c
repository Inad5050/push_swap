/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlg_b_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:59:24 by dani              #+#    #+#             */
/*   Updated: 2024/08/11 00:02:42 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_find_place_b(t_stack *stack_b, int value);
int	ps_case_rrarrb(t_stack *a, t_stack *b, int c);
int	ps_case_rarb(t_stack *a, t_stack *b, int c);
int	ps_case_rarrb(t_stack *a, t_stack *b, int c);
int	ps_case_rrarb(t_stack *a, t_stack *b, int c);

int	ps_find_place_b(t_stack *stack_b, int value)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (value > stack_b->value && value < ps_lstlast(stack_b)->value)
		i = 0;
	else if (value > ps_maxvalue(stack_b) || \
	value < ps_minvalue(stack_b))
		i = ps_find_index(stack_b, ps_maxvalue(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->value < value || tmp->value > value)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ps_case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ps_find_place_b(b, c))
		i = ps_lstsize(b) - ps_find_place_b(b, c);
	if ((i < (ps_lstsize(a) - ps_find_index(a, c))) && ps_find_index(a, c))
		i = ps_lstsize(a) - ps_find_index(a, c);
	return (i);
}

int	ps_case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ps_find_place_b(b, c);
	if (i < ps_find_index(a, c))
		i = ps_find_index(a, c);
	return (i);
}

int	ps_case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ps_find_place_b(b, c))
		i = ps_lstsize(b) - ps_find_place_b(b, c);
	i = ps_find_index(a, c) + i;
	return (i);
}

int	ps_case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ps_find_index(a, c))
		i = ps_lstsize(a) - ps_find_index(a, c);
	i = ps_find_place_b(b, c) + i;
	return (i);
}