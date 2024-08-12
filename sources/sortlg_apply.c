/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlg_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:47:39 by dani              #+#    #+#             */
/*   Updated: 2024/08/12 18:18:23 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ps_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int		ps_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int		ps_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int		ps_apply_rrarb(t_stack **a, t_stack **b, int c, char s);

int	ps_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && ps_find_place_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->value != c)
			ft_ra(a, 0);
		while (ps_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && ps_find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->value != c)
			ft_rb(b, 0);
		while (ps_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ps_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ft_ra(a, 0);
		while (ps_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ps_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b)->value != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ps_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && ps_find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->value != c)
			ft_rra(a, 0);
		while (ps_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && ps_find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->value != c)
			ft_rrb(b, 0);
		while (ps_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ps_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ft_rra(a, 0);
		while (ps_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ps_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->value != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
