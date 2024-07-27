/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:07:06 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/27 23:32:12 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.
sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.
ss swap a y swap b a la vez
 */

void	ps_swap(t_stack **stack);
void	ps_swap_both(t_stack **origin, t_stack **target);

void	ps_swap(t_stack **stack)
{
	t_stack first;
	t_stack	second;
	t_stack	temp;

	if (ps_lstsize(*stack) < 2)
		return ;
	first = *stack;
	second = *stack->next;
	first->next = second->next;
	second->next = first;
	temp = first->index;
	first->index = second->index;
	second->index = first->index;
	*stack = second;
}

void	ps_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ps_swap(stack_a);
	ps_swap(stack_b);	
}