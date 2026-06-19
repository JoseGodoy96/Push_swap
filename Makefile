# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgodoy-m <jgodoy-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 15:31:07 by jgodoy-m          #+#    #+#              #
#    Updated: 2025/11/12 19:39:21 by jgodoy-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library file name
NAME = push_swap

# Compiler and compilation flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I .

# Define directories
ALGORITHM_DIR = ./Algorithm
OPERATIONS_DIR = ./Operations
PARSING_DIR = ./Parsing

# Source files and object files
SRC = 	$(PARSING_DIR)/main.c \
		$(PARSING_DIR)/lst_utils_1.c \
		$(PARSING_DIR)/lst_utils_2.c \
		$(PARSING_DIR)/stack_init_utils_1.c \
		$(PARSING_DIR)/stack_init_utils_2.c \
		$(PARSING_DIR)/stack_init_utils_3.c \
		$(PARSING_DIR)/stack_init.c \
		$(OPERATIONS_DIR)/operations.c \
		$(OPERATIONS_DIR)/operations_1.c \
		$(OPERATIONS_DIR)/operations_2.c \
		$(ALGORITHM_DIR)/algorithms.c \
		$(ALGORITHM_DIR)/cost_algorithm_utils_2.c \
		$(ALGORITHM_DIR)/cost_algorithm_utils_1.c \
		$(ALGORITHM_DIR)/cost_algorithm.c 
OBJ = $(SRC:.c=.o)

# Header file
INCLUDE = push_swap.h

# Create libraries and delete files
AR = ar rcs
RM = rm -f

# Indicates that the following rules are not real files
.PHONY: all clean fclean re test_500 test_100 test_5 test_3 count_500 count_100 count_5 count_3 compare_500 compare_100 compare_5 compare_3

# Rule that compiles everything by default
all: $(NAME)

# Rule to create the push_swap
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Convert .c files to .o
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ 

# Rule to delete all created object files
clean:
	$(RM) $(OBJ)

# Delete all .o and .a files
fclean: clean
	$(RM) $(NAME)

test_500:
	@./$(NAME) `seq 1 500 | shuf`
test_100:
	@./$(NAME) `seq 1 100 | shuf`
test_5:
	@./$(NAME) `seq 1 5 | shuf`
test_3:
	@./$(NAME) `seq 1 3 | shuf`
count_500: 
	@./$(NAME) `seq 1 500 | shuf` | wc -l
count_100: 
	@./$(NAME) `seq 1 100 | shuf` | wc -l
count_5: 
	@./$(NAME) `seq 1 5 | shuf` | wc -l
count_3: 
	@./$(NAME) `seq 1 3 | shuf` | wc -l
compare_500:
	@ARG="`seq 1 500 | shuf`" && ./$(NAME) $$ARG | ./checker_linux $$ARG
compare_100:
	@ARG="`seq 1 100 | shuf`" && ./$(NAME) $$ARG | ./checker_linux $$ARG
compare_5:
	@ARG="`seq 1 5 | shuf`" && ./$(NAME) $$ARG | ./checker_linux $$ARG
compare_3:
	@ARG="`seq 1 3 | shuf`" && ./$(NAME) $$ARG | ./checker_linux $$ARG

re: fclean all
