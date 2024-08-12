/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:58:58 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/12 18:19:18 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int		ps_error(char *message);
int		ps_error2(char *message, char **args);
int		ps_error3(char *m, t_stack **stack_a, \
		t_stack **stack_b, char *mv);
void	ps_free_stack(t_stack **stack);

int	ps_error(char *message)
{
	(void)message;
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

int	ps_error2(char *message, char **args)
{
	int	i;

	i = 0;
	(void)message;
	while (args[i])
		free(args[i++]);
	free(args);
	ft_putstr_fd("Error\n", 2);
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

int	ps_error3(char *m, t_stack **stack_a, \
t_stack **stack_b, char *mv)
{
	(void)m;
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
	free(mv);
	ft_putstr_fd("Error\n", 2);
	exit (0);
}
