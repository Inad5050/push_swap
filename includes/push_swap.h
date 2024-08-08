/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:52:43 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/08 19:36:18 by dangonz3         ###   ########.fr       */
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
void		ps_check_str(int argc, char **argv);
int			ps_check_ifnumber(int argc, char **args);
int			ps_check_maxint(int argc, char **args);
int			ps_check_duplicates(int argc, char **args);

//close_program
int			ps_error(char *message);
int			ps_error2(char *message, char **args);
void		ps_free_stack(t_stack **stack);

//manage_lists
t_stack		*ps_lstnew(int value);
void		ps_lstadd_front(t_stack **stack, t_stack *new_node);
void		ps_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *stack);
int			ps_lstsize(t_stack **stack);

//manage_lists2
void		ps_lstprint(t_stack *stack);

//move_other
void		ps_push(t_stack **origin, t_stack **target);
void		ps_swap(t_stack **stack);
void		ps_swap_both(t_stack **origin, t_stack **target);

//move_print
void		ps_ra(t_stack **stack);
void		ps_pb(t_stack **origin, t_stack **target);
void		ps_pa(t_stack **origin, t_stack **target);
void		ps_sa(t_stack **stack);
void		ps_rra(t_stack **stack);

//move_rotate
void		ps_rotate(t_stack **stack);
void		ps_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ps_reverse_rotate(t_stack **stack);
void		ps_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ps_rrr(t_stack **stack_a, t_stack **stack_b);

//others
long		ps_atoi(const char *str);
int			ps_min_index(t_stack **stack, int val);
int			ps_distance(t_stack **stack, int index);
int			ps_strncmp(const char *str1, const char *str2);

//sort_initiate
void		ps_initiate_stack(t_stack **stack_a, int argc, char **argv);
void		ps_assign_index(t_stack *stack);
void		ps_initiate_sort(t_stack **stack_a, t_stack **stack_b);
int			ps_checkif_sorted(t_stack **stack);
void		ps_sort_method(t_stack **stack_a, t_stack **stack_b);

//sort_radix
void		ps_radix_sort(t_stack **stack_a, t_stack **stack_b);
int			ps_max_bits(t_stack *stack);

//sort_simple
void		ps_simple_sort(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_3(t_stack **stack_a);
void		ps_sort_3_aux(t_stack **stack_a, t_stack *current, \
			int next_min, int min);
void		ps_sort_4(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_5(t_stack **stack_a, t_stack **stack_b);

#endif
