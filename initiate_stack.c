/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:00:26 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/27 21:39:32 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv);
void	ps_index_stack(t_stack **stack);

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ps_lstnew(ft_atoi(args[i]));
		ps_lstadd_back(stack_a, new);
		i++;
	}
	ps_index_stack(stack_a);
	if (argc == 2)
		free(args);
}

void	ps_index_stack(t_stack **stack)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	current->index = i++;
	while (current->next)
	{
		current = current->next;
		current->index = i++;
	}
}