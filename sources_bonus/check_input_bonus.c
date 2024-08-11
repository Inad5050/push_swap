/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:45:09 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/11 20:12:30 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_check_input(int argc, char **argv);
void	ps_check_str(char **argv);
int		ps_check_ifnumber(char **args);
int		ps_check_maxint(char **args);
int		ps_check_duplicates(char **args);

void	ps_check_input(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		ps_check_str(argv);
		return ;
	}
	else
		args = &(argv[1]);
	while (i < argc - 1)
	{
		if (!args[i])
			ps_error("Wrong argument");
		i++;
	}
	if (ps_check_ifnumber(args) == 0)
		ps_error("Non-number argument");
	if (ps_check_maxint(args) == 0)
		ps_error("Argument exceeds int limits");
	if (ps_check_duplicates(args) == 0)
		ps_error("Duplicated number");
}

void	ps_check_str(char **argv)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(argv[1], ' ');
	if (ps_check_ifnumber(args) == 0)
		ps_error2("Non-number argument", args);
	if (ps_check_maxint(args) == 0)
		ps_error2("Argument exceeds int limits", args);
	if (ps_check_duplicates(args) == 0)
		ps_error2("Duplicated number", args);
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	ps_check_ifnumber(char **args)
{
	int	i;
	int	x;

	i = 0;
	while (args[i])
	{
		x = 0;
		if (args[i][x] == '-' && ('0' <= args[i][x + 1] && \
		args[i][x + 1] <= '9'))
			x++;
		while (args[i][x])
		{
			if (!('0' <= args[i][x] && args[i][x] <= '9'))
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	ps_check_maxint(char **args)
{
	int		i;
	long	min;
	long	max;

	i = 0;
	min = MIN_INT;
	max = MAX_INT;
	while (args[i])
	{
		if (ps_atoi(args[i]) < min || max < ps_atoi(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ps_check_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		j = 1;
		while (args[i + j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
