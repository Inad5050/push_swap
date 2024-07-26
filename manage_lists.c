/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:26:51 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/26 19:43:07 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*ps_lstnew(void *value);
void		ps_lstadd_front(t_stack **stack, t_stack *new_node);
void		ps_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *stack);
int			ps_lstsize(t_stack *stack);

t_stack	*ps_lstnew(void *value)
{
	t_stack	*new_node;

	new_node = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	ps_lstadd_front(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

void	ps_lstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	last = ps_lstlast(*stack);
	if (last)
		last->next = new_node;
	else
		*stack = new_node;
}

t_stack	*ps_lstlast(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!stack)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

int	ps_lstsize(t_stack *stack)
{
	t_stack	*current;
	size_t	i;

	current = stack;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

/* void	printList(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
} */
