# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 14:29:41 by seoyoo            #+#    #+#              #
#    Updated: 2023/01/06 14:14:17 by seoyoo           ###   ########.fr        #
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

# directories
SRC_DIR = ./src/
INC_DIR = ./inc/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# compiling options
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g
RDLINE = -lreadline
OPTIMMIZATION = -O3
INC = -I $(INC_DIR)

# my_lib
MY_LIB_DIR = ./my_lib/
MY_LIB_ARC = my_lib.a
MY_LIB = $(MY_LIB_DIR)$(MY_LIB_ARC)

# COMPILE = $(CC) $(CFLAGS) $(OPTIMMIZATION) # -> this will be the final flag
COMPILE = $(CC) $(CFLAGS) $(DBFLAG)
# LINKING = $(CC) $(CFLAGS) $(INC)  # incase for error
LINKING = $(CC) $(CFLAGS) $(RDLINE) $(MY_LIB)

# **************************************************************************** #

# main_function

MAIN_FUNCTION_DIR = main/

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
ETC_SRC_FILE = 

ETC_SRCS = $(addprefix $(ETC_SRC_DIR), $(ETC_SRC_FILE))

ETC_OBJ_DIR = $(OBJ_DIR)$(ETC_DIR)
ETC_OBJ_FILE = $(ETC_SRC_FILE:.c=.o)
ETC_OBJS = $(addprefix $(ETC_OBJ_DIR), $(ETC_OBJ_FILE))
OBJS_WITHOUT_MAIN += $(ETC_OBJS)

# **************************************************************************** #

OBJS += $(OBJS_WITHOUT_MAIN)

# **************************************************************************** #

# main rules

all : $(NAME)

$(NAME) : $(OBJS)
	@make mylib
	@printf "$(Green)\n[ my_lib compile finished!!] \n$(Color_Off)"
	$(LINKING) -o $@ $^

# add rules to compile src file in each folders

$(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
	$(COMPILE) -c $< -o $@ 

$(ETC_OBJ_DIR)%.o : $(ETC_SRC_DIR)%.c
	@mkdir -p $(ETC_OBJ_DIR)
	$(COMPILE) -c $< -o $@

# **************************************************************************** #

# test

TEST_NAME = minishell_test.out
TEST_SRC_FILE = \
		test_main.c \

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE))

TEST_OBJS = $(TEST_SRCS:.c=.o)

# add $(*_OBJS) for unit-test
TESTING_TARGET = $(OBJS_WITHOUT_MAIN);

test : clean mylib $(TEST_NAME)
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
	@make fclean -C $(MY_LIB_DIR)
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re : fclean all

run : all
	@./$(NAME)

norm : 
	@norminette ./src ./inc

mylib :
	@make -C $(MY_LIB_DIR)

.PONEY : all test clean fclean re run norm mylib
