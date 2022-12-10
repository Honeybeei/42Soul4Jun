# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 20:16:40 by seoyoo            #+#    #+#              #
#    Updated: 2022/12/10 15:30:15 by seoyoo           ###   ########.fr        #
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
NAME = minishell

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g3
EXTRAFLAGS =
# EXTRAFLAGS = -lreadline

# basic directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# include
INC_DIR = ./inc/
INC_FLAGS = -I $(INC_DIR)

COMPILE_FLAGS = $(CC) $(EXTRAFLAGS) $(CFLAGS) $(INC_FLAGS)
COMPILE_FLAGS_FOR_TEST = $(CC) $(DBFLAG) $(EXTRAFLAGS) $(INC_FLAGS)	# without -WWW
LINKING_FLAGS = $(CC) $(CFLAGS)

# **************************************************************************** #

# main_function
MAIN_FUNCTION_DIR = main_function/
MAIN_FUNCTION_SRC_FILE = main_function.c
MAIN_FUNCTION_SRCS = $(addprefix $(SRC_DIR)$(MAIN_FUNCTION_DIR), $(MAIN_FUNCTION_SRC_FILE))
MAIN_FUNCTION_OBJS = $(addprefix $(OBJ_DIR), $($(MAIN_FUNCTION_SRC_FILE):.c=.o))

# utils_and_etc
UTILS_AND_ETC_DIR = utils_and_etc/
UTILS_AND_ETC_SRC_FILE = \
		makefile_test_functions.c

UTILS_AND_ETC_SRCS = $(addprefix $(SRC_DIR)$(UTILS_AND_ETC_DIR), $(UTILS_AND_ETC_SRC_FILE))
UTILS_AND_ETC_OBJS = $(addprefix $(OBJ_DIR), $($(UTILS_AND_ETC_SRC_FILE):.c=.o))

# **************************************************************************** #

SRCS = \
		$(MAIN_FUNCTION_SRCS) \
		$(SRCS_WITHOUT_MAIN)

OBJS_WITHOUT_MAIN = $(UTILS_AND_ETC_OBJS)

OBJS = $(MAIN_FUNCTION_OBJS) $(OBJS_WITHOUT_MAIN)

#main rule
all : $(NAME)

$(NAME) : $(OBJS)
	@mkdir -p $(OBJ_DIR)
	$(LINKING_FLAGS) -o $@ $^

$(OBJS) : $(SRCS)
	$(COMPILE_FLAGS) -c $< -o $@

# **************************************************************************** #

# test

# TEST_NAME = minishell_test
# TEST_SRC_FILE = \
# 		minishell_test_main.c

# TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE));

# TEST_OBJS = $(TEST_SRCS:.c=.o)

# test : clean $(TEST_NAME)
# 	@printf "$(Red)\n[ minishell test ver compile finished!!] \n$(Color_Off)"
# 	@./$(TEST_NAME)

# $(TEST_NAME) : $(OBJS_WITHOUT_MAIN) $(TEST_OBJS)
# 	$(CC) $(DBFLAG) $(MY_LIB) -o $@ $^

# $(TEST_DIR)%.o : $(TEST_DIR)%.cd
# 	$(CC) $(DBFLAG) $(INCLUDE) -c $< -o $@
# **************************************************************************** #

# main rules


# $(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
# 	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
# 	$(CC) $(CFLAGS) $(DBFLAG) $(INCLUDE) -c $< -o $@

# $(UTILS_AND_ETC_OBJ_DIR)%.o : $(UTILS_AND_ETC_SRC_DIR)%.c
# 	@mkdir -p $(UTILS_AND_ETC_OBJ_DIR)
# 	$(CC) $(CFLAGS) $(DBFLAG) $(INCLUDE) -c $< -o $@

# # **************************************************************************** #

# # test

# TEST_NAME = pipex_test
# TEST_SRC_FILE = \
# 		pipex_test_main.c

# TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE));

# TEST_OBJS = $(TEST_SRCS:.c=.o)

# test : mylib $(TEST_NAME)
# 	@printf "$(Red)\n[ PIPEX TEST VER compile finished!!] \n$(Color_Off)"
# 	@./$(TEST_NAME)

# $(TEST_NAME) : $(OBJS_WITHOUT_MAIN) $(TEST_OBJS)
# 	$(CC) $(DBFLAG) $(MY_LIB) -o $@ $^

# $(TEST_DIR)%.o : $(TEST_DIR)%.c
# 	$(CC) $(DBFLAG) $(INCLUDE) -c $< -o $@

# **************************************************************************** #

# debug : clean
# 	LETS_DEBUG=1 make

# clean :
# 	rm -rf ./obj
# 	rm -rf ./test/*.o

# fclean : clean
# 	@make fclean -C $(MY_LIB_DIR)
# 	rm -f $(NAME)
# 	rm -f $(TEST_NAME)
# 	rm -f infile.txt outfile.txt

# re : fclean all

# mylib :
# 	@make -C $(MY_LIB_DIR)

# .PONEY : all test clean fclean re mylib


# main_function

# MAIN_FUNCTION_SRC_FILE = \
# 		main_philo.c

# MAIN_FUNCTION_SRCS = $(addprefix $(SRC_DIR), $(MAIN_FUNCTION_SRC_FILE))
# MAIN_FUNCTION_OBJ_FILE = $(MAIN_FUNCTION_SRC_FILE:.c=.o)
# MAIN_FUNCTION_OBJS = $(addprefix $(OBJ_DIR), $(MAIN_FUNCTION_OBJ_FILE))

# # **************************************************************************** # 

# # utils

# UTILS_SRC_FILE = \
# 		makefile_test_functions.c

# UTILS_SRCS = $(addprefix $(SRC_DIR), $(UTILS_SRC_FILE))
# UTILS_OBJ_FILE = $(UTILS_SRC_FILE:.c=.o)
# UTILS_OBJS = $(addprefix $(OBJ_DIR), $(UTILS_OBJ_FILE))

# # **************************************************************************** #

# OBJS_WITHOUT_MAIN = \
# 		$(UTILS_OBJS)

# OBJS = $(MAIN_FUNCTION_OBJS) $(OBJS_WITHOUT_MAIN)

# # **************************************************************************** #

# # main rules

# all : $(NAME)

# #	linking
# $(NAME) : $(OBJS)
# 	$(LINKING_FLAGS) -o $@ $^
# 	@printf "$(Blue)\n[ STUPID PHILOSOPHERS...... ]\n$(Color_Off)"

# #	compiling
# $(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
# 	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
# 	$(COMPILE_FLAGS) -c $< -o $@

# $(UTILS_OBJ_DIR)%.o : $(UTILS_SRC_DIR)%.c
# 	@mkdir -p $(UTILS_OBJ_DIR)
# 	$(COMPILE_FLAGS) -c $< -o $@

# # **************************************************************************** #

# # test

# TEST_NAME = philo_test
# TEST_SRC_FILE = \
# 		test_main_philo.c \
# 		utils_for_test.c

# TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE))

# TEST_OBJS = $(TEST_SRCS:.c=.o) $(OBJS_WITHOUT_MAIN)

# #	test argvs
# TEST_ARGS = 10 2 3 4 

# # To activate testing area, decommentize the code below and also .PONEY
# # # test : clean $(TEST_NAME)
# # 	@printf "$(Green)\n[ LETS TEST THOSE STUPID PHILOSOPHERS! ]\n\n$(Color_Off)"
# # 	@./$(TEST_NAME) $(TEST_ARGS)

# $(TEST_NAME) : $(TEST_OBJS)
# 	$(LINKING_FLAGS) -o $@ $^

# $(TEST_DIR)%.o : $(TEST_DIR)%.c
# 	$(COMPILE_FLAGS_FOR_TEST) -c $< -o $@

# # **************************************************************************** #

# # etc rules

# clean :
# 	rm -rf $(OBJ_DIR)
# 	rm -rf $(TEST_OBJS)

# fclean : clean
# 	rm -f $(NAME)
# 	rm -f $(TEST_NAME)

# re : fclean all

# ree : clean all

# norm :
# 	@norminette ./inc ./src

# .PONEY : all clean fclean re ree norm #test

# # **************************************************************************** #
