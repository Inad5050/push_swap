/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlg_a_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:49:08 by dani              #+#    #+#             */
/*   Updated: 2024/08/12 18:18:15 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ps_find_place_a(t_stack *stack_a, int nbr_push);
int		ps_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int		ps_case_rarb_a(t_stack *a, t_stack *b, int c);
int		ps_case_rarrb_a(t_stack *a, t_stack *b, int c);
int		ps_case_rrarb_a(t_stack *a, t_stack *b, int c);

int	ps_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->value && nbr_push > ps_lstlast(stack_a)->value)
		i = 0;
	else if (nbr_push > ps_maxvalue(stack_a) || nbr_push < ps_minvalue(stack_a))
		i = ps_find_index(stack_a, ps_minvalue(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > nbr_push || tmp->value < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

int	ps_case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ps_find_place_a(a, c))
		i = ps_lstsize(a) - ps_find_place_a(a, c);
	if ((i < (ps_lstsize(b) - ps_find_index(b, c))) && ps_find_index(b, c))
		i = ps_lstsize(b) - ps_find_index(b, c);
	return (i);
}

int	ps_case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ps_find_place_a(a, c);
	if (i < ps_find_index(b, c))
		i = ps_find_index(b, c);
	return (i);
}

int	ps_case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ps_find_index(b, c))
		i = ps_lstsize(b) - ps_find_index(b, c);
	i = ps_find_place_a(a, c) + i;
	return (i);
}

int	ps_case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ps_find_place_a(a, c))
		i = ps_lstsize(a) - ps_find_place_a(a, c);
	i = ps_find_index(b, c) + i;
	return (i);
}
