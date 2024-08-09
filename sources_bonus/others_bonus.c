/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:58:58 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/09 19:49:35 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

long	ps_atoi(const char *str);
int		ps_distance(t_stack **stack, int index);
int		ps_strncmp(const char *str1, const char *str2);
char	*ps_strjoin(char *s1, const char *s2);

long	ps_atoi(const char *str)
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
	return (b * a);
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


char	*ps_strjoin(char *s1, const char *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*result;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[len_s1 + i] = s2[i];
		i++;
	}
	result[len_s1 + i] = '\0';
	free(s1);
	return (result);
}