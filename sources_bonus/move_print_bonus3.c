/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_print_bonus3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:53:42 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/08 20:00:58 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_rra(t_stack **stack);
void	ps_rrb(t_stack **stack);
void	ps_rrr(t_stack **stack_a, t_stack **stack_b);

void	ps_rra(t_stack **stack)
{
	ps_reverse_rotate(stack);
}

void	ps_rrb(t_stack **stack)
{
	ps_reverse_rotate(stack);
}

void	ps_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ps_reverse_rotate_both(stack_a, stack_b);
}
