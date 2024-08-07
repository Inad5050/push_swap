# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 09:09:40 by dangonz3          #+#    #+#              #
#    Updated: 2024/08/07 20:07:42 by dangonz3         ###   ########.fr        #
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
SRC_FILES = check_input.c close_program.c main.c manage_lists.c manage_lists2.c move_other.c move_print.c move_rotate.c others.c sort_initiate.c sort_radix.c sort_simple.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)

SRC_BONUS_DIR = sources_bonus/
SRC_BONUS_FILES = check_input_bonus.c close_program_bonus.c main_bonus.c manage_lists_bonus.c manage_lists2_bonus.c move_other_bonus.c move_print_bonus.c move_rotate_bonus.c others_bonus.c sort_initiate_bonus.c sort_radix_bonus.c sort_simple_bonus.c
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES))
OBJ_BONUS = $(SRC:.c=.o)

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

.PHONY:	all clean fclean re
