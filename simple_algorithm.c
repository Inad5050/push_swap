/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:37:56 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/27 21:46:30 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_simple_sort(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_two(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_three(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_five(t_stack **stack_a, t_stack **stack_b);

ps_simple_sort(stack_a, stack_b)
{
	if (ps_lstsize(*stack_a) == 2)
		ps_sort_two(stack_a, stack_b);
	if (ps_lstsize(*stack_a) == 3)
		ps_sort_three(stack_a, stack_b);
	if (ps_lstsize(*stack_a) == 4)
		ps_sort_four(stack_a, stack_b);
	if (ps_lstsize(*stack_a) == 5)
		ps_sort_five(stack_a, stack_b);

}

void	ps_sort_two(t_stack **stack_a, t_stack **stack_b);
{
	




	
}


void	ps_sort_three(t_stack **stack_a, t_stack **stack_b);



void	ps_sort_four(t_stack **stack_a, t_stack **stack_b);




void	ps_sort_five(t_stack **stack_a, t_stack **stack_b);