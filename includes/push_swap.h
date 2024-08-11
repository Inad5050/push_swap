/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dani <dani@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:52:43 by dangonz3          #+#    #+#             */
/*   Updated: 2024/08/11 12:31:01 by dani             ###   ########.fr       */
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
	long			value;
	long			index;
	struct s_stack	*next;
}	t_stack;

//auxiliars
long		ps_atoi(const char *str);
int			ps_strncmp(const char *str1, const char *str2);
void		ps_lstprint(t_stack *stack);

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

//initiate_stack
void		ps_initiate_stack(t_stack **stack_a, int argc, char **argv);
void		ps_assign_index(t_stack *stack);

//manage_lists
t_stack		*ps_lstnew(int value);
void		ps_lstadd_front(t_stack **stack, t_stack *new_node);
void		ps_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *stack);
int			ps_lstsize(t_stack *stack);

//move_print
void		ps_ra(t_stack **stack);
void		ps_pb(t_stack **origin, t_stack **target);
void		ps_pa(t_stack **origin, t_stack **target);
void		ps_sa(t_stack **stack);
void		ps_rra(t_stack **stack);

//move_stack
void		ps_push(t_stack **origin, t_stack **target);
void		ps_swap(t_stack **stack);
void		ps_swap_both(t_stack **origin, t_stack **target);

//move_stack2
void		ps_rotate(t_stack **stack);
void		ps_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ps_reverse_rotate(t_stack **stack);
void		ps_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ps_rrr(t_stack **stack_a, t_stack **stack_b);

//sort_initiate
void		ps_initiate_sort(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_method(t_stack **stack_a, t_stack **stack_b);
void		ps_lg_sort(t_stack **stack_a, t_stack **stack_b);

//sort_simple_aux
int			ps_checkif_sorted(t_stack **stack);
int			ps_min_index(t_stack **stack, int val);
int			ps_distance(t_stack **stack, int index);

//sort_simple
void		ps_simple_sort(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_3(t_stack **stack_a);
void		ps_sort_3_aux(t_stack **stack_a, t_stack *current, \
			int next_min, int min);
void		ps_sort_4(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_5(t_stack **stack_a, t_stack **stack_b);

//sortlg_a_case
int			ps_find_place_a(t_stack *stack_a, int nbr_push);
int			ps_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int			ps_case_rarb_a(t_stack *a, t_stack *b, int c);
int			ps_case_rarrb_a(t_stack *a, t_stack *b, int c);
int			ps_case_rrarb_a(t_stack *a, t_stack *b, int c);

//sortlg_a
t_stack		**ps_sort_a(t_stack **stack_a, t_stack **stack_b);
int			ps_rotate_type_ba(t_stack *a, t_stack *b);

//sortlg_apply
int			ps_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			ps_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int			ps_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ps_apply_rrarb(t_stack **a, t_stack **b, int c, char s);

//sortlg_auxiliars
int			ps_find_index(t_stack *a, int value);
int			ps_maxvalue(t_stack *a);
int			ps_minvalue(t_stack *a);
void		ps_sort_three(t_stack **stack_a);

//sortlg_b_apply
int			ps_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int			ps_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ps_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int			ps_apply_rrarb(t_stack **a, t_stack **b, int c, char s);

//sortlg_b_case
int			ps_find_place_b(t_stack *stack_b, int value);
int			ps_case_rrarrb(t_stack *a, t_stack *b, int c);
int			ps_case_rarb(t_stack *a, t_stack *b, int c);
int			ps_case_rarrb(t_stack *a, t_stack *b, int c);
int			ps_case_rrarb(t_stack *a, t_stack *b, int c);

//sortlg_b
t_stack		**ps_sort_b(t_stack **stack_a, t_stack **stack_b);
void		ps_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
int			ps_rotate_type_ab(t_stack *a, t_stack *b);

//sortlg_movements
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void		ft_sa(t_stack **a, int j);
void		ft_sb(t_stack **b, int j);
void		ft_ss(t_stack **a, t_stack **b, int j);

//sortlg_movements
void		ft_rr(t_stack **a, t_stack **b, int j);
void		ft_ra(t_stack **a, int j);
void		ft_rb(t_stack **b, int j);

//sortlg_movements3
void		ft_rrr(t_stack **a, t_stack **b, int j);
void		ft_rrr_2(t_stack **b, int j);
void		ft_rra(t_stack **a, int j);
void		ft_rrb(t_stack **b, int j);

#endif
