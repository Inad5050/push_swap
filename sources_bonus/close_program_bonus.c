/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:58:58 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/07 19:54:51 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int		ps_error(char *message);
int		ps_error2(char *message, char **args);
void	ps_free_stack(t_stack **stack);

int	ps_error(char *message)
{
	ft_printf(COLOR_RED "ERROR:\n%s\n" COLOR_RESET, message);
	exit (0);
}

int	ps_error2(char *message, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	ft_printf(COLOR_RED "ERROR:\n%s\n" COLOR_RESET, message);
	exit (0);
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
