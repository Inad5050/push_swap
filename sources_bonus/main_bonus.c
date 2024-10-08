/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:52:28 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/12 18:41:16 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	*line;
	char	*movements;

	if (argc < 2)
		return (1);
	ps_check_input(argc, argv);
	stack_a = (t_stack **)ft_calloc(1, sizeof(t_stack));
	stack_b = (t_stack **)ft_calloc(1, sizeof(t_stack));
	if (!stack_a | !stack_b)
		return (1);
	*stack_a = NULL;
	*stack_b = NULL;
	ps_initiate_stack(stack_a, argc, argv);
	movements = ft_strdup("");
	line = ft_get_next_line(0);
	while (line)
	{
		movements = ps_strjoin(movements, line);
		free(line);
		line = ft_get_next_line(0);
	}
	ps_initiate_mv(stack_a, stack_b, movements);
	return (0);
}
