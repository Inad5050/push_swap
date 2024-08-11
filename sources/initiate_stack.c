/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:11:40 by dani              #+#    #+#             */
/*   Updated: 2024/08/11 12:12:15 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv);
void	ps_assign_index(t_stack *stack);

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &(argv[1]);
	while (args[i])
	{
		new = ps_lstnew(ft_atoi(args[i]));
		ps_lstadd_back(stack_a, new);
		i++;
	}
	ps_assign_index(*stack_a);
	if (argc == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
}

void	ps_assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		i;

	current = stack;
	while (current)
	{
		i = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}