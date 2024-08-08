/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_initiate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:33:47 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/08 19:55:09 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_initiate_mv(t_stack **stack_a, t_stack **stack_b, char *movements);
void	ps_check_mv(t_stack **stack_a, t_stack **stack_b, char *movements);
void	ps_execute_mv(t_stack **stack_a, t_stack **stack_b, char **moves);
void	ps_choose_mv(t_stack **stack_a, t_stack **stack_b, char *moves);

void	ps_initiate_mv(t_stack **stack_a, t_stack **stack_b, char *movements)
{
	if (ps_checkif_sorted(stack_a) == 1)
	{
		ps_free_stack(stack_a);
		ps_free_stack(stack_b);
		return ;
	}
	ps_check_mv(stack_a, stack_b, movements);
	ps_isokay(stack_a, stack_b);
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
}

void	ps_check_mv(t_stack **stack_a, t_stack **stack_b, char *movements)
{
	int		i;
	char	**moves;

	i = 0;
	moves = ft_split(movements, '\n');
	while (moves[i])
	{
		if (ft_strncmp(moves[i], "sa", 3) != 0 && \
	ft_strncmp(moves[i], "sb", 3) != 0 && ft_strncmp(moves[i], "ss", 3) != 0 && \
	ft_strncmp(moves[i], "pa", 3) != 0 && ft_strncmp(moves[i], "pb", 3) != 0 && \
	ft_strncmp(moves[i], "ra", 3) != 0 && ft_strncmp(moves[i], "rb", 3) != 0 && \
	ft_strncmp(moves[i], "rr", 3) != 0 && ft_strncmp(moves[i], "rra", 3) != 0 \
	&& ft_strncmp(moves[i], "rrb", 3) != 0 && \
	ft_strncmp(moves[i], "rrr", 3) != 0)
		{
			i = 0;
			while (moves[i])
				free(moves[i]);
			free(moves);
			ps_error("Icorrect movements");
		}
		i++;
	}
	ps_execute_mv(stack_a, stack_b, moves);
}

void	ps_execute_mv(t_stack **stack_a, t_stack **stack_b, char **moves)
{
	int	i;

	i = 0;
	while (moves[i])
		ps_choose_mv(stack_a, stack_b, moves[i]);
}

void	ps_choose_mv(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	if (ft_strncmp(moves, "sa", 3) == 0)
		ps_sa(stack_a);
	else if (ft_strncmp(moves, "sb", 3) == 0)
		ps_sb(stack_b);
	else if (ft_strncmp(moves, "ss", 3) == 0)
		ps_ss(stack_a, stack_b);
	else if (ft_strncmp(moves, "pa", 3) == 0)
		ps_pa(stack_a, stack_b);
	else if (ft_strncmp(moves, "pb", 3) == 0)
		ps_pb(stack_a, stack_b);
	else if (ft_strncmp(moves, "ra", 3) == 0)
		ps_ra(stack_a);
	else if (ft_strncmp(moves, "rb", 3) == 0)
		ps_rb(stack_b);
	else if (ft_strncmp(moves, "rr", 3) == 0)
		ps_rr(stack_a, stack_b);
	else if (ft_strncmp(moves, "rra", 3) == 0)
		ps_rra(stack_a);
	else if (ft_strncmp(moves, "rrb", 3) == 0)
		ps_rrb(stack_b);
	else if (ft_strncmp(moves, "rrr", 3) == 0)
		ps_rrr(stack_a, stack_b);
}
