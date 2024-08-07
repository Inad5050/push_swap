/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lists2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:45:22 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/07 19:54:58 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_lstprint(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		ft_printf("VALUE[%i] == %i\n", current->index, current->value);
		current = current->next;
	}
}
