/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:15:40 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/08 19:33:19 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

/* 
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.
rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.
rr ra y rb al mismo tiempo.
*/
/* 
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.
rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo.
 */

void	ps_rotate(t_stack **stack);
void	ps_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ps_reverse_rotate(t_stack **stack);
void	ps_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ps_rrr_both(t_stack **stack_a, t_stack **stack_b);

void	ps_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*current;

	first = *stack;
	last = ps_lstlast(*stack);
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	current = *stack;
	while (current)
		current = current->next;
}

void	ps_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ps_rotate(stack_a);
	ps_rotate(stack_b);
}

void	ps_reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*secondlast;

	current = *stack;
	if (!*stack)
		return ;
	while (current->next->next)
		current = current->next;
	secondlast = current;
	current = current->next;
	secondlast->next = NULL;
	ps_lstadd_front(stack, current);
}

void	ps_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ps_reverse_rotate(stack_a);
	ps_reverse_rotate(stack_b);
}

void	ps_rrr_both(t_stack **stack_a, t_stack **stack_b)
{
	ps_rotate_both(stack_a, stack_b);
	ps_reverse_rotate_both(stack_a, stack_b);
}
