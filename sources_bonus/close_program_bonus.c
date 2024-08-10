/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:58:58 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/10 18:46:21 by dani             ###   ########.fr       */
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
	ft_printf("Error\n");
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
	ft_printf("Error\n");
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
	ft_printf("Error\n");
	exit (0);
}