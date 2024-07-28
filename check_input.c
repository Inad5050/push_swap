/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:45:09 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/28 16:17:50 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_check_input(int argc, char **argv);
int		ps_check_ifnumber(int argc, char **argv);
int		ps_check_maxint(int argc, char **argv);
int		ps_check_duplicates(int argc, char **argv);
int		ps_strncmp(const char *str1, const char *str2);

void	ps_check_input(int argc, char **argv)
{
	if (ps_check_ifnumber(argc, argv) == 0)
		ps_error("Non-number argument");
	if (ps_check_maxint(argc, argv) == 0)
		ps_error("Argument exceeds MAX_INT");
	if (ps_check_duplicates(argc, argv) == 0)
		ps_error("Duplicated number");
}

int	ps_check_ifnumber(int argc, char **argv)
{
	int	i;
	int	x;

	i = 1;
	while (i <= argc)
	{
		x = 0;
		if (argv[i][x] == '-' && ('0' <= argv[i][x + 1] && \
		argv[i][x + 1] <= '9'))
			x++;
		while (argv[i][x])
		{
			if (!('0' <= argv[i][x] && argv[i][x] <= '9'))
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	ps_check_maxint(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc)
	{
		if (ps_atoi(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ps_check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (i + j < argc)
		{
			if (ps_strncmp(argv[i + j], argv[i + j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
