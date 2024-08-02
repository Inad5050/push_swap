/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:58:58 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/28 16:16:48 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ps_error(char *message);
int		ps_atoi(const char *str);
void	ps_free_stack(t_stack **stack);
int		ps_min_index(t_stack **stack, int val);
int		ps_distance(t_stack **stack, int index);

int	ps_error(char *message)
{
	ft_printf(COLOR_RED "ERROR:\n%s\n" COLOR_RESET, message);
	exit (0);
}

int	ps_atoi(const char *str)
{
	long	a;
	long	b;

	a = 1;
	b = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			a *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		b = 10 * b + (*str - '0');
		str++;
	}
	if (b > MAX_INT || -b < MIN_INT)
		return (0);
	else
		return (b * a);
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

int	ps_min_index(t_stack **stack, int val)
{
	t_stack	*current;
	int		min;

	current = *stack;
	min = current->index;
	while (current->next)
	{
		current = current->next;
		if (current->index < min && current->index != val)
			min = current->index;
	}
	return (min);
}

int	ps_distance(t_stack **stack, int index)
{
	t_stack	*current;
	int		distance;

	distance = 0;
	current = *stack;
	while (current)
	{
		if (current->index == index)
			break ;
		distance++;
		current = current->next;
	}
	return (distance);
}
