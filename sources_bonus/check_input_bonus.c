/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:45:09 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/07 19:54:45 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_check_input(int argc, char **argv);
void	ps_check_str(int argc, char **argv);
int		ps_check_ifnumber(int argc, char **args);
int		ps_check_maxint(int argc, char **args);
int		ps_check_duplicates(int argc, char **args);

void	ps_check_input(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		ps_check_str(argc, argv);
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
	if (ps_check_ifnumber(argc, args) == 0)
		ps_error("Non-number argument");
	if (ps_check_maxint(argc, args) == 0)
		ps_error("Argument exceeds int limits");
	if (ps_check_duplicates(argc, args) == 0)
		ps_error("Duplicated number");
}

void	ps_check_str(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(argv[1], ' ');
	while (i < argc - 1)
	{
		if (!args[i])
			ps_error2("Wrong argument", args);
		i++;
	}
	if (ps_check_ifnumber(argc, args) == 0)
		ps_error2("Non-number argument", args);
	if (ps_check_maxint(argc, args) == 0)
		ps_error2("Argument exceeds int limits", args);
	if (ps_check_duplicates(argc, args) == 0)
		ps_error2("Duplicated number", args);
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	ps_check_ifnumber(int argc, char **args)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < argc - 1 && args[i][x])
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

int	ps_check_maxint(int argc, char **args)
{
	int		i;
	long	min;
	long	max;

	i = 0;
	min = MIN_INT;
	max = MAX_INT;
	while (i < argc - 1)
	{
		if (ps_atoi(args[i]) < min || max < ps_atoi(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ps_check_duplicates(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		argc = 0;
		while (args[argc])
			argc++;
		argc++;
	}
	while (i + 1 < argc - 1)
	{
		j = 1;
		while (i + j < argc - 1)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
