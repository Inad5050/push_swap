/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlg_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:52:27 by dani              #+#    #+#             */
/*   Updated: 2024/08/11 00:42:41 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	**ps_sort_b(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
int		ps_rotate_type_ab(t_stack *a, t_stack *b);

t_stack	**ps_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ps_lstsize(*stack_a) > 3 && !ps_checkif_sorted(stack_a))
		ft_pb(stack_a, stack_b, 0);
	if (ps_lstsize(*stack_a) > 3 && !ps_checkif_sorted(stack_a))
		ft_pb(stack_a, stack_b, 0);
	if (ps_lstsize(*stack_a) > 3 && !ps_checkif_sorted(stack_a))
		ps_sort_b_till_3(stack_a, stack_b);
	if (!ps_checkif_sorted(stack_a))
		ps_sort_three(stack_a);
	return (stack_b);
}

void	ps_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ps_lstsize(*stack_a) > 3 && !ps_checkif_sorted(stack_a))
	{
		tmp = *stack_a;
		i = ps_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ps_case_rarb(*stack_a, *stack_b, tmp->value))
				i = ps_apply_rarb(stack_a, stack_b, tmp->value, 'a');
			else if (i == ps_case_rrarrb(*stack_a, *stack_b, tmp->value))
				i = ps_apply_rrarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == ps_case_rarrb(*stack_a, *stack_b, tmp->value))
				i = ps_apply_rarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == ps_case_rrarb(*stack_a, *stack_b, tmp->value))
				i = ps_apply_rrarb(stack_a, stack_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

int	ps_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = ps_case_rrarrb(a, b, a->value);
	while (tmp)
	{
		if (i > ps_case_rarb(a, b, tmp->value))
			i = ps_case_rarb(a, b, tmp->value);
		if (i > ps_case_rrarrb(a, b, tmp->value))
			i = ps_case_rrarrb(a, b, tmp->value);
		if (i > ps_case_rarrb(a, b, tmp->value))
			i = ps_case_rarrb(a, b, tmp->value);
		if (i > ps_case_rrarb(a, b, tmp->value))
			i = ps_case_rrarb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}
