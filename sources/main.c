/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:52:28 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/28 15:52:10 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (1);
	ps_check_input(argc, argv);
	stack_a = (t_stack **)ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (1);
	stack_b = (t_stack **)ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (1);
	*stack_a = NULL;
	*stack_b = NULL;
	ps_initiate_stack(stack_a, argc, argv);
	ps_initiate_sort(stack_a, stack_b);
	return (0);
}
