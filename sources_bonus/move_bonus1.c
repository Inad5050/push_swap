/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:15:40 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/12 18:20:52 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

	if (ps_lstsize(stack) < 2)
		return ;
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
	t_stack	*last;

	if (ps_lstsize(stack) < 2)
		return ;
	current = *stack;
	last = ps_lstlast(*stack);
	while (current)
	{
		if (current->next->next == NULL)
		{
			current->next = NULL;
			break ;
		}
		current = current->next;
	}
	last->next = *stack;
	*stack = last;
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
