/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:58:58 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/26 20:00:44 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ps_error(char *message);
void	ps_free_stack(t_stack **stack);

int	ps_error(char *message)
{
	ft_printf(COLOR_RED "ERROR:\n%s\n" COLOR_RESET, message);
	/* exit (0); */
}

void	ps_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = *stack;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}