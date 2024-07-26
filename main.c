/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:52:28 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/26 19:33:33 by dangonz3         ###   ########.fr       */
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
	if (ps_checkif_sorted(stack_a) == 1)
	{
		ps_free_stack(stack_a);
		ps_free_stack(stack_b);
		return (0);
	}
	ps_sort_stack(stack_a, stack_b);
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
	
	return (0);	
}
