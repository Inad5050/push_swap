/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_initiate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:33:47 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/12 18:22:41 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ps_initiate_mv(t_stack **stack_a, t_stack **stack_b, char *movements);
void	ps_check_mv(t_stack **stack_a, t_stack **stack_b, char *movements);
void	ps_execute_mv(t_stack **stack_a, t_stack **stack_b, char **moves);
void	ps_choose_mv(t_stack **stack_a, t_stack **stack_b, char *moves);
void	ps_isokay(t_stack **stack_a, t_stack **stack_b);

void	ps_initiate_mv(t_stack **stack_a, t_stack **stack_b, char *movements)
{
	ps_check_mv(stack_a, stack_b, movements);
	ps_isokay(stack_a, stack_b);
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
	free(movements);
}

void	ps_check_mv(t_stack **stack_a, t_stack **stack_b, char *movements)
{
	int		i;
	int		x;
	char	**m;

	i = 0;
	m = ft_split(movements, '\n');
	while (m[i])
	{
		if (ft_strncmp(m[i], "sa\0", 3) != 0 && \
	ft_strncmp(m[i], "sb\0", 3) != 0 && ft_strncmp(m[i], "ss\0", 3) != 0 && \
	ft_strncmp(m[i], "pa\0", 3) != 0 && ft_strncmp(m[i], "pb\0", 3) != 0 && \
	ft_strncmp(m[i], "ra\0", 3) != 0 && ft_strncmp(m[i], "rb\0", 3) != 0 && \
	ft_strncmp(m[i], "rr\0", 3) != 0 && ft_strncmp(m[i], "rra\0", 4) != 0 \
	&& ft_strncmp(m[i], "rrb\0", 4) != 0 && \
	ft_strncmp(m[i], "rrr\0", 4) != 0)
		{
			x = 0;
			while (m[x])
				free(m[x++]);
			free(m);
			ps_error3(" ", stack_a, stack_b, movements);
		}
		i++;
	}
	ps_execute_mv(stack_a, stack_b, m);
}

void	ps_execute_mv(t_stack **stack_a, t_stack **stack_b, char **moves)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (moves[i])
		ps_choose_mv(stack_a, stack_b, moves[i++]);
	while (moves[x])
		free(moves[x++]);
	free(moves);
}

void	ps_choose_mv(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	if (ft_strncmp(moves, "sa\0", 3) == 0)
		ps_sa(stack_a);
	else if (ft_strncmp(moves, "sb\0", 3) == 0)
		ps_sb(stack_b);
	else if (ft_strncmp(moves, "ss\0", 3) == 0)
		ps_ss(stack_a, stack_b);
	else if (ft_strncmp(moves, "pa\0", 3) == 0)
		ps_pa(stack_b, stack_a);
	else if (ft_strncmp(moves, "pb\0", 3) == 0)
		ps_pb(stack_a, stack_b);
	else if (ft_strncmp(moves, "ra\0", 3) == 0)
		ps_ra(stack_a);
	else if (ft_strncmp(moves, "rb\0", 3) == 0)
		ps_rb(stack_b);
	else if (ft_strncmp(moves, "rra\0", 4) == 0)
		ps_rra(stack_a);
	else if (ft_strncmp(moves, "rrb\0", 4) == 0)
		ps_rrb(stack_b);
	else if (ft_strncmp(moves, "rrr\0", 4) == 0)
		ps_rrr(stack_a, stack_b);
	else if (ft_strncmp(moves, "rr\0", 3) == 0)
		ps_rr(stack_a, stack_b);
}

void	ps_isokay(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a))
		ft_printf("KO\n");
	else if (ps_checkif_sorted(stack_a) == 1 && !(*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
