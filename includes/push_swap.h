/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:52:43 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/28 16:35:35 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

//colors
# define COLOR_RED		"\033[0;31m"
# define COLOR_GREEN	"\033[0;32m"
# define COLOR_RESET	"\033[0m"

//others
# define MAX_INT	2147483647
# define MIN_INT	-2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}		t_stack;

//check_input
void		ps_check_input(int argc, char **argv);
int			ps_check_ifnumber(int argc, char **argv);
int			ps_check_maxint(int argc, char **argv);
int			ps_check_duplicates(int argc, char **argv);
int			ps_strncmp(const char *str1, const char *str2);

//initiate_stack
void		ps_initiate_stack(t_stack **stack, int argc, char **argv);

//initiate_sort
void		ps_initiate_sort(t_stack **stack_a, t_stack **stack_b);
int			ps_checkif_sorted(t_stack **stack);
void		ps_assign_index(t_stack *stack);
void		ps_sort(t_stack **stack_a, t_stack **stack_b);

//simple_sort
void		ps_simple_sort(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_3(t_stack **stack_a);
void		ps_sort_4(t_stack **stack_a, t_stack **stack_b);
int			ps_get_min(t_stack **stack, int val);
int			ps_distance(t_stack **stack, int index);

//radix_sort
void		ps_radix_sort(t_stack **stack_a, t_stack **stack_b);
int			ps_max_bits(t_stack *stack);

//manage_lists
t_stack		*ps_lstnew(int value);
void		ps_lstadd_front(t_stack **stack, t_stack *new_node);
void		ps_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *stack);
int			ps_lstsize(t_stack *stack);

//move_other
void		ps_push(t_stack **origin, t_stack **target);
void		ps_swap(t_stack **stack);
void		ps_swap_both(t_stack **origin, t_stack **target);

//move_rotate
void		ps_rotate(t_stack **stack);
void		ps_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ps_reverse_rotate(t_stack **stack);
void		ps_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ps_rrr(t_stack **stack_a, t_stack **stack_b);

//move_print
void		ps_ra(t_stack **stack);
void		ps_pb(t_stack **origin, t_stack **target);
void		ps_pa(t_stack **origin, t_stack **target);
void		ps_sa(t_stack **stack);
void		ps_rra(t_stack **stack);

//others
int			ps_error(char *message);
int			ps_atoi(const char *str);
void		ps_free_stack(t_stack **stack);
int			ps_min_index(t_stack **stack, int val);
int			ps_distance(t_stack **stack, int index);

#endif

/* 
sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.
sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.
ss swap a y swap b a la vez.

pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.

ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.
rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.
rr ra y rb al mismo tiempo.

rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.
rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.

rrr rra y rrb al mismo tiempo.
 */