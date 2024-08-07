/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:34:45 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/07 19:55:02 by dangonz3         ###   ########.fr       */
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

void	ps_ra(t_stack **stack);
void	ps_pb(t_stack **origin, t_stack **target);
void	ps_pa(t_stack **origin, t_stack **target);
void	ps_sa(t_stack **stack);
void	ps_rra(t_stack **stack);

void	ps_ra(t_stack **stack)
{
	ps_rotate(stack);
	ft_printf("ra\n");
}

void	ps_pb(t_stack **origin, t_stack **target)
{
	ps_push(origin, target);
	ft_printf("pb\n");
}

void	ps_pa(t_stack **origin, t_stack **target)
{
	ps_push(origin, target);
	ft_printf("pa\n");
}

void	ps_sa(t_stack **stack)
{
	ps_swap(stack);
	ft_printf("sa\n");
}

void	ps_rra(t_stack **stack)
{
	ps_reverse_rotate(stack);
	ft_printf("rra\n");
}
