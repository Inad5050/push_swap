/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlg_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:10:43 by dani              #+#    #+#             */
/*   Updated: 2024/08/11 00:38:53 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	**ps_sort_a(t_stack **stack_a, t_stack **stack_b);
int		ps_rotate_type_ba(t_stack *a, t_stack *b);

t_stack	**ps_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ps_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ps_case_rarb_a(*stack_a, *stack_b, tmp->value))
				i = ps_apply_rarb(stack_a, stack_b, tmp->value, 'b');
			else if (i == ps_case_rarrb_a(*stack_a, *stack_b, tmp->value))
				i = ps_apply_rarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == ps_case_rrarrb_a(*stack_a, *stack_b, tmp->value))
				i = ps_apply_rrarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == ps_case_rrarb_a(*stack_a, *stack_b, tmp->value))
				i = ps_apply_rrarb(stack_a, stack_b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

int	ps_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = ps_case_rrarrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > ps_case_rarb_a(a, b, tmp->value))
			i = ps_case_rarb_a(a, b, tmp->value);
		if (i > ps_case_rrarrb_a(a, b, tmp->value))
			i = ps_case_rrarrb_a(a, b, tmp->value);
		if (i > ps_case_rarrb_a(a, b, tmp->value))
			i = ps_case_rarrb_a(a, b, tmp->value);
		if (i > ps_case_rrarb_a(a, b, tmp->value))
			i = ps_case_rrarb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}
