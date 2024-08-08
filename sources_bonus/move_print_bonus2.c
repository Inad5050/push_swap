/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_print_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:47:22 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/08 20:00:53 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_ra(t_stack **stack);
void	ps_rb(t_stack **stack);
void	ps_rr(t_stack **stack_a, t_stack **stack_b);

void	ps_ra(t_stack **stack)
{
	ps_rotate(stack);
}

void	ps_rb(t_stack **stack)
{
	ps_rotate(stack);
}

void	ps_rr(t_stack **stack_a, t_stack **stack_b)
{
	ps_rotate_both(stack_a, stack_b);
}
