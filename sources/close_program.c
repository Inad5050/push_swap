/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:58:58 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/11 20:10:28 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ps_error(char *message);
int		ps_error2(char *message, char **args);
void	ps_free_stack(t_stack **stack);

int	ps_error(char *message)
{
	ft_putstr_fd(COLOR_RED "ERROR:\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(COLOR_RESET "\n", 2);
	exit (0);
}

int	ps_error2(char *message, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	ft_putstr_fd(COLOR_RED "ERROR:\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(COLOR_RESET "\n", 2);
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
