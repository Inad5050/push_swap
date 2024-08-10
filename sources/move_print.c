/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:34:45 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/11 00:08:44 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
