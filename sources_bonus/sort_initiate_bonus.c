/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_initiate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:19:32 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/08 15:39:30 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv);
void	ps_assign_index(t_stack *stack);
int		ps_checkif_sorted(t_stack **stack);

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

int	ps_checkif_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
