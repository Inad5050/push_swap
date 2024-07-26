/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:52:43 by dangonz3          #+#    #+#             */
/*   Updated: 2024/07/26 20:23:40 by dangonz3         ###   ########.fr       */
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
# define MAX_INT	2147483648

typedef struct s_stack
{
	int		value;
	int		index;
	t_stack	*next;
}		t_stack;

//initiate_stack
void		ps_initiate_stack(t_list **stack, int argc, char **argv);

//check_input
void		ps_check_input(int argc, char **argv);
int			ps_check_ifnumber(int argc, char **argv);
int			ps_check_maxint(int argc, char **argv);
int			ps_check_duplicates(int argc, char **argv);

//others
void		ps_index_stack(t_stack **stack);
int 		ps_checkif_sorted(t_stack **stack);
void		ps_sort_stack(t_list **stack_a, t_list **stack_b);
int			ps_strncmp(const char *str1, const char *str2);

//manage_lists
t_stack		*ps_lstnew(void *value);
void		ps_lstadd_front(t_stack **stack, t_stack *new_node);
void		ps_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack		*ps_lstlast(t_stack *stack);
int			ps_lstsize(t_stack *stack);

//close_program
int			ps_error(char *message);
void		ps_free_stack(t_stack **stack);

#endif