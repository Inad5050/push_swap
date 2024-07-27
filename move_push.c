/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:08:33 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/27 23:27:31 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
*/

void	ps_push(t_stack **origin, t_stack **target);

void	ps_push(t_stack **origin, t_stack **target)
{
	t_stack	*first;
	t_stack	*current;
	
	if (!*origin)
		return ;
	first = *origin;
	ps_lstadd_front(target, first);
	current = first->next;
	while (current)
	{
		current->index += 1;
		current = current->next;	
	}
	origin = origin->next;
	if (*origin)
	{
		current = *origin;
		while (current)
		{
			current->index -= 1;
			current = current->next;		
		}
	}
}
