# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dani <dani@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 09:09:40 by dangonz3          #+#    #+#              #
#    Updated: 2024/08/11 00:56:39 by dani             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

# colors
COLOR_GREEN = \033[0;32m
COLOR_RESET = \033[0m

# sources
SRC_DIR = sources/
SRC_FILES = auxiliars.c check_input.c close_program.c main.c manage_lists.c manage_lists2.c move_print.c move_stack.c move_stack2.c sort_initiate.c sort_simple_aux.c sort_simple.c sortlg_a_case.c sortlg_a.c sortlg_apply.c sortlg_auxiliars.c sortlg_b_case.c sortlg_b.c sortlg_movements.c sortlg_movements2.c sortlg_movements3.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)

SRC_BONUS_DIR = sources_bonus/
SRC_BONUS_FILES = check_input_bonus.c close_program_bonus.c main_bonus.c manage_lists_bonus1.c manage_lists_bonus2.c move_bonus1.c move_bonus2.c move_initiate_bonus.c move_print_bonus1.c move_print_bonus2.c move_print_bonus3.c others_bonus.c sort_initiate_bonus.c
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES))
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# headers
INCLUDE = -I./includes/

# library LIBFT
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
	
# program
all: $(LIBFT_LIB) $(NAME)
	@echo "$(COLOR_GREEN)------------ PROCESS FINISHED ------------ $(COLOR_RESET)"

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME) $(INCLUDE)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR) all -s
	
%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(COLOR_GREEN)------------ MESSAGE: $@ COMPILED ------------ $(COLOR_RESET)"
	
# additional functions

bonus: $(LIBFT_LIB) $(NAME_BONUS)
	@echo "$(COLOR_GREEN)------------ PROCESS FINISHED ------------ $(COLOR_RESET)"

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CCFLAGS) $(OBJ_BONUS) $(LIBFT_LIB) -o $(NAME_BONUS) $(INCLUDE)
	
clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean -s
	@echo "$(COLOR_GREEN)------------ MESSAGE: CLEANING COMPLETED ------------ $(COLOR_RESET)"
	
fclean: 
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean -s
	@echo "$(COLOR_GREEN)------------ MESSAGE: CLEANING COMPLETED ------------ $(COLOR_RESET)"

re: fclean all

rebonus: fclean all bonus

.PHONY:	all clean fclean re
