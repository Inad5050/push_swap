/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:08:33 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/11 00:34:43 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_push(t_stack **origin, t_stack **target);
void	ps_swap(t_stack **stack);
void	ps_swap_both(t_stack **origin, t_stack **target);

void	ps_push(t_stack **origin, t_stack **target)
{
	t_stack	*tmp;

	if (*origin == NULL)
		return ;
	tmp = (*origin)->next;
	(*origin)->next = *target;
	*target = *origin;
	*origin = tmp;
}

void	ps_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (ps_lstsize(*stack) < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ps_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ps_swap(stack_a);
	ps_swap(stack_b);
}
