/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:08:33 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/07 19:55:00 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

/* 
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
*/

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

/* 
sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.
sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.
ss swap a y swap b a la vez
 */

void	ps_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (ps_lstsize(stack) < 2)
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
