/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:52:43 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/09 19:28:49 by dani             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
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
# define PS_BUFFER_SIZE 2000

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}		t_stack;

//check_input
void		ps_check_input(int argc, char **argv);
void		ps_check_str(int argc, char **argv);
int			ps_check_ifnumber(int argc, char **args);
int			ps_check_maxint(int argc, char **args);
int			ps_check_duplicates(int argc, char **args);

//close_program
int			ps_error(char *message);
int			ps_error2(char *message, char **args);
int			ps_error3(char *m, t_stack **stack_a, \
			t_stack **stack_b, char *mv);
void		ps_free_stack(t_stack **stack);

//manage_lists1
t_stack		*ps_lstnew(int value);
void		ps_lstadd_front(t_stack **stack, t_stack *new_node);
void		ps_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *stack);
int			ps_lstsize(t_stack **stack);

//manage_lists2
void		ps_lstprint(t_stack *stack);

//move1
void		ps_rotate(t_stack **stack);
void		ps_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ps_reverse_rotate(t_stack **stack);
void		ps_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ps_rrr_both(t_stack **stack_a, t_stack **stack_b);

//move2
void		ps_push(t_stack **origin, t_stack **target);
void		ps_swap(t_stack **stack);
void		ps_swap_both(t_stack **origin, t_stack **target);

//move_initiate
void		ps_initiate_mv(t_stack **stack_a, t_stack \
			**stack_b, char *movements);
void		ps_check_mv(t_stack **stack_a, t_stack **stack_b, char *movements);
void		ps_execute_mv(t_stack **stack_a, t_stack **stack_b, char **moves);
void		ps_choose_mv(t_stack **stack_a, t_stack **stack_b, char *moves);

//move_print1
void		ps_sa(t_stack **stack);
void		ps_sb(t_stack **stack);
void		ps_ss(t_stack **stack_a, t_stack **stack_b);
void		ps_pa(t_stack **origin, t_stack **target);
void		ps_pb(t_stack **origin, t_stack **target);

//move_print2
void		ps_ra(t_stack **stack);
void		ps_rb(t_stack **stack);
void		ps_rr(t_stack **stack_a, t_stack **stack_b);

//move_print3
void		ps_rra(t_stack **stack);
void		ps_rrb(t_stack **stack);
void		ps_rrr(t_stack **stack_a, t_stack **stack_b);

//others
long		ps_atoi(const char *str);
int			ps_distance(t_stack **stack, int index);
int			ps_strncmp(const char *str1, const char *str2);
void		ps_isokay(t_stack **stack_a, t_stack **stack_b);
char		*ps_strjoin(char *s1, const char *s2);

//sort_initiate
void		ps_initiate_stack(t_stack **stack_a, int argc, char **argv);
void		ps_assign_index(t_stack *stack);
int			ps_checkif_sorted(t_stack **stack);

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

/* ARG="NUMBERS"; ./push_swap $ARG | ./checker_linux $ARG  */