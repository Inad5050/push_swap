/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:19:32 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/26 20:20:52 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_index_stack(t_stack **stack);
int 	ps_checkif_sorted(t_stack **stack);
void	ps_sort_stack(t_list **stack_a, t_list **stack_b);
int		ps_strncmp(const char *str1, const char *str2);

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

void	ps_sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ps_lstsize(*stack_a) <= 5)
		ps_simple_sort(stack_a, stack_b);
	else
		ps_radix_sort(stack_a, stack_b);
}

int	ps_strncmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}