# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 22:40:00 by seoyoo            #+#    #+#              #
#    Updated: 2022/12/27 20:21:25 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Green = \033[0;31m		# Green
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME = push_swap
NAME_BONUS = checker

# compiler
CC = cc
DBFLAGS = -g
CFLAGS = -Wall -Wextra -Werror

# basic directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# include
INC_DIR = ./inc/
INC_FLAGS = -I $(INC_DIR)

# my_lib
MY_LIB_DIR = ./my_lib/
MY_LIB_ARC = my_lib.a
MY_LIB = $(MY_LIB_DIR)$(MY_LIB_ARC)

COMPILE_FLAGS = $(CC) $(DBFLAGS) $(CFLAGS) $(INC_FLAGS)
LINKING_FLAGS = $(CC) $(MY_LIB)

# **************************************************************************** #

# main_function

MAIN_FUNCTION_DIR = main_function/

MAIN_FUNCTION_SRC_DIR = $(SRC_DIR)$(MAIN_FUNCTION_DIR)

MAIN_FUNCTION_SRC_FILE = \
		push_swap_main.c

MAIN_FUNCTION_SRCS = \
		$(addprefix $(MAIN_FUNCTION_SRC_DIR), \
		$(MAIN_FUNCTION_SRC_FILE))

MAIN_FUNCTION_OBJ_DIR = $(OBJ_DIR)$(MAIN_FUNCTION_DIR)
MAIN_FUNCTION_OBJ_FILE = $(MAIN_FUNCTION_SRC_FILE:.c=.o)
MAIN_FUNCTION_OBJS = \
		$(addprefix $(MAIN_FUNCTION_OBJ_DIR), \
		$(MAIN_FUNCTION_OBJ_FILE))

# **************************************************************************** # 

# operations

OPERATIONS_DIR = ./operations/

OPERATIONS_SRC_DIR = $(SRC_DIR)$(OPERATIONS_DIR)
OPERATIONS_SRC_FILE = 

OPERATIONS_SRCS = \
		$(addprefix $(OPERATIONS_SRC_DIR), \
		$(OPERATIONS_SRC_FILE))

OPERATIONS_OBJ_DIR = $(OBJ_DIR)$(OPERATIONS_DIR)
OPERATIONS_OBJ_FILE = $(OPERATIONS_SRC_FILE:.c=.o)
OPERATIONS_OBJS = \
		$(addprefix $(OPERATIONS_OBJ_DIR), \
		$(OPERATIONS_OBJ_FILE))

# **************************************************************************** # 

# sorting

SORTING_DIR = ./sorting/

SORTING_SRC_DIR = $(SRC_DIR)$(SORTING_DIR)
SORTING_SRC_FILE = \
		sorting.c

SORTING_SRCS = \
		$(addprefix $(SORTING_SRC_DIR), \
		$(SORTING_SRC_FILE))

SORTING_OBJ_DIR = $(OBJ_DIR)$(SORTING_DIR)
SORTING_OBJ_FILE = $(SORTING_SRC_FILE:.c=.o)
SORTING_OBJS = \
		$(addprefix $(SORTING_OBJ_DIR), \
		$(SORTING_OBJ_FILE))

# **************************************************************************** # 

# utils

UTILS_DIR = ./utils/

UTILS_SRC_DIR = $(SRC_DIR)$(UTILS_DIR)
UTILS_SRC_FILE = \
		error_management.c \
		get_arguments.c \
		object_management_1.c \
		object_management_2.c \
		object_management_3.c

UTILS_SRCS = \
		$(addprefix $(UTILS_SRC_DIR), \
		$(UTILS_SRC_FILE))

UTILS_OBJ_DIR = $(OBJ_DIR)$(UTILS_DIR)
UTILS_OBJ_FILE = $(UTILS_SRC_FILE:.c=.o)
UTILS_OBJS = \
		$(addprefix $(UTILS_OBJ_DIR), \
		$(UTILS_OBJ_FILE))

# **************************************************************************** # 

OBJS_WITHOUT_MAIN = \
		$(OPERATIONS_OBJS) \
		$(SORTING_OBJS) \
		$(UTILS_OBJS)

OBJS = $(MAIN_FUNCTION_OBJS) $(OBJS_WITHOUT_MAIN)

# **************************************************************************** #

# main rules

all : $(NAME)

#	linking
$(NAME) : $(OBJS)
	@make mylib
	@printf "$(Green)\n[ mylib compile finished!!] \n$(Color_Off)"
	$(LINKING_FLAGS) -o $@ $^
	@printf "$(Blue)\n[ ENJOY PUSH_SWAP!! ]\n$(Color_Off)"

#	compiling
$(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

$(OPERATIONS_OBJ_DIR)%.o : $(OPERATIONS_SRC_DIR)%.c
	@mkdir -p $(OPERATIONS_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

$(SORTING_OBJ_DIR)%.o : $(SORTING_SRC_DIR)%.c
	@mkdir -p $(SORTING_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

$(UTILS_OBJ_DIR)%.o : $(UTILS_SRC_DIR)%.c
	@mkdir -p $(UTILS_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

# **************************************************************************** #

# test

TEST_NAME = push_swap_test
TEST_SRC_FILE = \
		test_main.c \
		print_objects.c

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE))

TEST_OBJS = $(TEST_SRCS:.c=.o)

#	Change arguments file here
TEST_ARGS = 5 4 3 2 1 0

test : mylib clean $(TEST_NAME)
	@printf "$(Green)\n[ PUSH_SWAP TEST VER compile finished!!] \n\n\n$(Color_Off)"
	@./$(TEST_NAME) $(TEST_ARGS)

$(TEST_NAME) : $(OBJS_WITHOUT_MAIN) $(TEST_OBJS)
	$(LINKING_FLAGS) -o $@ $^

$(TEST_DIR)%.o : $(TEST_DIR)%.c
	$(COMPILE_FLAGS) -c $< -o $@

# **************************************************************************** #

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_OBJS)

fclean : clean
	@make -C $(MY_LIB_DIR) fclean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re : fclean all

ree : clean all

run : ree
	./$(NAME)

mylib :
	@make -C $(MY_LIB_DIR)

norm :
	@norminette ./inc ./my_lib ./src | grep "Error"

.PONEY : all test clean fclean re ree run mylib norm
