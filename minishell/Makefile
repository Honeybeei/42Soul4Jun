# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 14:29:41 by seoyoo            #+#    #+#              #
#    Updated: 2023/01/05 14:40:08 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Red = \033[0;31m		# Red
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME = minishell

# compiling options
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g
RDLINE = -lreadline
OPTIMMIZATION = -O3
INC = -I ./

# directories
SRC_DIR = ./src/
INC_DIR = ./inc/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# COMPILE = $(CC) $(CFLAGS) $(OPTIMMIZATION) # -> this will be the final flag
COMPILE = $(CC) $(CFLAGS) $(DBFLAG)
# LINKING = $(CC) $(CFLAGS) $(INC)  # incase for error
LINKING = $(CC) $(CFLAGS) $(RDLINE)

# **************************************************************************** #

# main_function

MAIN_FUNCTION_DIR = main_function/

MAIN_FUNCTION_SRC_DIR = $(SRC_DIR)$(MAIN_FUNCTION_DIR)

MAIN_FUNCTION_SRC_FILE = \
		main.c 

MAIN_FUNCTION_SRCS = \
		$(addprefix $(MAIN_FUNCTION_SRC_DIR), \
		$(MAIN_FUNCTION_SRC_FILE))

MAIN_FUNCTION_OBJ_DIR = $(OBJ_DIR)$(MAIN_FUNCTION_DIR)
MAIN_FUNCTION_OBJ_FILE = $(MAIN_FUNCTION_SRC_FILE:.c=.o)
MAIN_FUNCTION_OBJS = $(addprefix $(MAIN_FUNCTION_OBJ_DIR), $(MAIN_FUNCTION_OBJ_FILE))
OBJS += $(MAIN_FUNCTION_OBJS)

# **************************************************************************** # 

# conversion

CONVERSION_DIR = conversion/

# CONVERSION - src
CONVERSION_SRC_DIR = $(SRC_DIR)$(CONVERSION_DIR)
CONVERSION_SRC_FILE = \
		token_list_conversion.c

CONVERSION_SRCS = $(addprefix $(CONVERSION_SRC_DIR), $(CONVERSION_SRC_FILE))

CONVERSION_OBJ_DIR = $(OBJ_DIR)$(CONVERSION_DIR)
CONVERSION_OBJ_FILE = $(CONVERSION_SRC_FILE:.c=.o)
CONVERSION_OBJS = $(addprefix $(CONVERSION_OBJ_DIR), $(CONVERSION_OBJ_FILE))
OBJS_WITHOUT_MAIN += $(CONVERSION_OBJS)

# **************************************************************************** # 

# etc

ETC_DIR = etc/

# etc - src
ETC_SRC_DIR = $(SRC_DIR)$(ETC_DIR)
ETC_SRC_FILE = \
		error_management.c \
		init_and_termination.c \
		input_management.c \
		safe_malloc.c \
		start_shell.c \
		variable_control.c

ETC_SRCS = $(addprefix $(ETC_SRC_DIR), $(ETC_SRC_FILE))

ETC_OBJ_DIR = $(OBJ_DIR)$(ETC_DIR)
ETC_OBJ_FILE = $(ETC_SRC_FILE:.c=.o)
ETC_OBJS = $(addprefix $(ETC_OBJ_DIR), $(ETC_OBJ_FILE))
OBJS_WITHOUT_MAIN += $(ETC_OBJS)

# **************************************************************************** #

# execution

EXECUTION_DIR = execution/

# execution - src
EXECUTION_SRC_DIR = $(SRC_DIR)$(EXECUTION_DIR)
EXECUTION_SRC_FILE = \
		execution_main.c \

EXECUTION_SRCS = $(addprefix $(EXECUTION_SRC_DIR), $(EXECUTION_SRC_FILE))

EXECUTION_OBJ_DIR = $(OBJ_DIR)$(EXECUTION_DIR)
EXECUTION_OBJ_FILE = $(EXECUTION_SRC_FILE:.c=.o)
EXECUTION_OBJS = $(addprefix $(EXECUTION_OBJ_DIR), $(EXECUTION_OBJ_FILE))
OBJS_WITHOUT_MAIN += $(EXECUTION_OBJS)

# **************************************************************************** #

# libft_functions

LIBFT_FUNCTIONS_DIR = libft_functions/

# LIBFT_FUNCTIONS - src
LIBFT_FUNCTIONS_SRC_DIR = $(SRC_DIR)$(LIBFT_FUNCTIONS_DIR)
LIBFT_FUNCTIONS_SRC_FILE = \
        str_functions_1.c \
		str_functions_2.c

LIBFT_FUNCTIONS_SRCS = $(addprefix $(LIBFT_FUNCTIONS_SRC_DIR), $(LIBFT_FUNCTIONS_SRC_FILE))

LIBFT_FUNCTIONS_OBJ_DIR = $(OBJ_DIR)$(LIBFT_FUNCTIONS_DIR)
LIBFT_FUNCTIONS_OBJ_FILE = $(LIBFT_FUNCTIONS_SRC_FILE:.c=.o)
LIBFT_FUNCTIONS_OBJS = $(addprefix $(LIBFT_FUNCTIONS_OBJ_DIR), $(LIBFT_FUNCTIONS_OBJ_FILE))
OBJS_WITHOUT_MAIN += $(LIBFT_FUNCTIONS_OBJS)

# **************************************************************************** #

# object_management

OBJECT_MANAGEMENT_DIR = object_management/

# OBJECT_MANAGEMENT - src
OBJECT_MANAGEMENT_SRC_DIR = $(SRC_DIR)$(OBJECT_MANAGEMENT_DIR)
OBJECT_MANAGEMENT_SRC_FILE = \
		cmd_management.c \
		token_management.c \
		variable_management.c

OBJECT_MANAGEMENT_SRCS = $(addprefix $(OBJECT_MANAGEMENT_SRC_DIR), $(OBJECT_MANAGEMENT_SRC_FILE))

OBJECT_MANAGEMENT_OBJ_DIR = $(OBJ_DIR)$(OBJECT_MANAGEMENT_DIR)
OBJECT_MANAGEMENT_OBJ_FILE = $(OBJECT_MANAGEMENT_SRC_FILE:.c=.o)
OBJECT_MANAGEMENT_OBJS = $(addprefix $(OBJECT_MANAGEMENT_OBJ_DIR), $(OBJECT_MANAGEMENT_OBJ_FILE))
OBJS_WITHOUT_MAIN += $(OBJECT_MANAGEMENT_OBJS)

# **************************************************************************** #

# tokenizer

TOKENIZER_DIR = tokenizer/

# TOKENIZER - src
TOKENIZER_SRC_DIR = $(SRC_DIR)$(TOKENIZER_DIR)
TOKENIZER_SRC_FILE = \
		tokenizer.c

TOKENIZER_SRCS = $(addprefix $(TOKENIZER_SRC_DIR), $(TOKENIZER_SRC_FILE))

TOKENIZER_OBJ_DIR = $(OBJ_DIR)$(TOKENIZER_DIR)
TOKENIZER_OBJ_FILE = $(TOKENIZER_SRC_FILE:.c=.o)
TOKENIZER_OBJS = $(addprefix $(TOKENIZER_OBJ_DIR), $(TOKENIZER_OBJ_FILE))
OBJS_WITHOUT_MAIN += $(TOKENIZER_OBJS)

# **************************************************************************** #

OBJS += $(OBJS_WITHOUT_MAIN)

# **************************************************************************** #

# main rules

all : $(NAME)

$(NAME) : $(OBJS)
	$(LINKING) -o $@ $^

# add rules to compile src file in each folders

$(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
	$(COMPILE) -c $< -o $@ 

$(CONVERSION_OBJ_DIR)%.o : $(CONVERSION_SRC_DIR)%.c
	@mkdir -p $(CONVERSION_OBJ_DIR)
	$(COMPILE) -c $< -o $@

$(ETC_OBJ_DIR)%.o : $(ETC_SRC_DIR)%.c
	@mkdir -p $(ETC_OBJ_DIR)
	$(COMPILE) -c $< -o $@

$(EXECUTION_OBJ_DIR)%.o : $(EXECUTION_SRC_DIR)%.c
	@mkdir -p $(EXECUTION_OBJ_DIR)
	$(COMPILE) -c $< -o $@

$(LIBFT_FUNCTIONS_OBJ_DIR)%.o : $(LIBFT_FUNCTIONS_SRC_DIR)%.c
	@mkdir -p $(LIBFT_FUNCTIONS_OBJ_DIR)
	$(COMPILE) -c $< -o $@ 

$(OBJECT_MANAGEMENT_OBJ_DIR)%.o : $(OBJECT_MANAGEMENT_SRC_DIR)%.c
	@mkdir -p $(OBJECT_MANAGEMENT_OBJ_DIR)
	$(COMPILE) -c $< -o $@

$(TOKENIZER_OBJ_DIR)%.o : $(TOKENIZER_SRC_DIR)%.c
	@mkdir -p $(TOKENIZER_OBJ_DIR)
	$(COMPILE) -c $< -o $@ 

# **************************************************************************** #

# test

TEST_NAME = minishell_test.out
TEST_SRC_FILE = \
		minishell_test_main.c \

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE))

TEST_OBJS = $(TEST_SRCS:.c=.o)

# add $(*_OBJS) for unit-test
TESTING_TARGET = $(OBJS_WITHOUT_MAIN);

test : clean $(TEST_NAME)
	@./$(TEST_NAME)

$(TEST_NAME) : $(TEST_OBJS) $(TESTING_TARGET)
	$(LINKING) -o $@ $^

# test src file compile
$(TEST_DIR)%.o : $(TEST_DIR)%.c
	$(COMPILE) -c $< -o $@

# **************************************************************************** #

clean :
	rm -rf $(OBJ_DIR)
	rm -f $(TEST_OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re : fclean all

run : all
	@./$(NAME)

norm : 
	@norminette ./src ./inc

.PONEY : all test clean fclean re run
