/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:58:05 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/28 16:35:56 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv);

void	ps_initiate_stack(t_stack **stack_a, int argc, char **argv)
{
	t_stack	*new;
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
	ps_assign_index(*stack_a);
	if (argc == 2)
		free(args);
}
