# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 14:29:41 by seoyoo            #+#    #+#              #
#    Updated: 2022/12/13 14:42:00 by seoyoo           ###   ########.fr        #
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

# etc

ETC_DIR = etc/

# etc - src
ETC_SRC_DIR = $(SRC_DIR)$(ETC_DIR)
ETC_SRC_FILE = \
		blabla1.c \
		user_interface.c

ETC_SRCS = $(addprefix $(ETC_SRC_DIR), $(ETC_SRC_FILE))

ETC_OBJ_DIR = $(OBJ_DIR)$(ETC_DIR)
ETC_OBJ_FILE = $(ETC_SRC_FILE:.c=.o)
ETC_OBJS = $(addprefix $(ETC_OBJ_DIR), $(ETC_OBJ_FILE))
OBJS += $(ETC_OBJS)

# **************************************************************************** #

# object_management

OBJECT_MANAGEMENT_DIR = object_management/

# OBJECT_MANAGEMENT - src
OBJECT_MANAGEMENT_SRC_DIR = $(SRC_DIR)$(OBJECT_MANAGEMENT_DIR)
OBJECT_MANAGEMENT_SRC_FILE = \
        manage_t_input.c

OBJECT_MANAGEMENT_SRCS = $(addprefix $(OBJECT_MANAGEMENT_SRC_DIR), $(OBJECT_MANAGEMENT_SRC_FILE))

OBJECT_MANAGEMENT_OBJ_DIR = $(OBJ_DIR)$(OBJECT_MANAGEMENT_DIR)
OBJECT_MANAGEMENT_OBJ_FILE = $(OBJECT_MANAGEMENT_SRC_FILE:.c=.o)
OBJECT_MANAGEMENT_OBJS = $(addprefix $(OBJECT_MANAGEMENT_OBJ_DIR), $(OBJECT_MANAGEMENT_OBJ_FILE))
OBJS += $(OBJECT_MANAGEMENT_OBJS)

# **************************************************************************** #

# main rules

all : $(NAME)

$(NAME) : $(OBJS)
	$(LINKING) -o $@ $^

# add rules to compile src file in each folders

$(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
	$(COMPILE) -c $< -o $@ 

$(ETC_OBJ_DIR)%.o : $(ETC_SRC_DIR)%.c
	@mkdir -p $(ETC_OBJ_DIR)
	$(COMPILE) -c $< -o $@

$(OBJECT_MANAGEMENT_OBJ_DIR)%.o : $(OBJECT_MANAGEMENT_SRC_DIR)%.c
	@mkdir -p $(OBJECT_MANAGEMENT_OBJ_DIR)
	$(COMPILE) -c $< -o $@

# **************************************************************************** #

# test

TEST_NAME = minishell_test.out
TEST_SRC_FILE = \
		minishell_test_main.c \

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE))

TEST_OBJS = $(TEST_SRCS:.c=.o)

# add $(*_OBJS) for unit-test
TESTING_TARGET = $(ETC_OBJS)

test : $(TEST_NAME)
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

.PONEY : all test clean fclean re run
