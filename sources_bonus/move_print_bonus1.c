/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_print_bonus1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:34:45 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/09 20:21:49 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

/* 
void	ps_push(t_stack **origin, t_stack **target);
void	ps_swap(t_stack **stack);
void	ps_swap_both(t_stack **origin, t_stack **target);

void	ps_rotate(t_stack **stack);
void	ps_rotate_both(t_stack **stack_a, t_stack **stack_b);

void	ps_reverse_rotate(t_stack **stack);
void	ps_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	ps_rrr(t_stack **stack_a, t_stack **stack_b); 
*/

void	ps_sa(t_stack **stack);
void	ps_sb(t_stack **stack);
void	ps_ss(t_stack **stack_a, t_stack **stack_b);
void	ps_pa(t_stack **origin, t_stack **target);
void	ps_pb(t_stack **origin, t_stack **target);

void	ps_sa(t_stack **stack_a)
{
	ps_swap(stack_a);
}

void	ps_sb(t_stack **stack_b)
{
	ps_swap(stack_b);
}

void	ps_ss(t_stack **stack_a, t_stack **stack_b)
{
	ps_swap_both(stack_a, stack_b);
}

void	ps_pa(t_stack **origin, t_stack **target)
{
	ps_push(origin, target);
}

void	ps_pb(t_stack **origin, t_stack **target)
{
	ps_push(origin, target);
}
