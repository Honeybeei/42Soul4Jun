/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:08 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/09 21:36:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# include <unistd.h>			//  STDIN_FILENO, STDERR_FILENO, 
# include <stdlib.h>        	//  EXIT_FAILURE, 
# include <stdbool.h>			//	true, false
# include <stdio.h>				//	printf(), perror()
# include <errno.h>
# include <termios.h>			//	tcgetattr(), tcsetattr()
# include <readline/readline.h>	// readline(), 
# include <readline/history.h>	// add_history(),

# include "../my_lib/inc/improved_libft.h"
# include "ascii_art.h"

/* ************************************************************************** */

# define PROMPT_STR_ "Jsh -> "

# define OPERATIONAL_CHAR_ "<>|"
# define ETC_META_CHAR_ "\"\'$"

# define OP_PIPE_ "|"
# define OP_REDIR_IN_1_ "<"
# define OP_REDIR_IN_2_ "<<"
# define OP_REDIR_OUT_1_ ">"
# define OP_REDIR_OUT_2_ ">>"

/* ************************************************************************** */

typedef enum e_customized_error_number
{
	errno_no_errors_ = 0,
	errno_tokenize_no_matching_operator_
}	t_errno;

typedef enum e_customized_boolean
{
	success_ = 0,
	fail_ = 1
}	t_bool;

typedef enum e_flag
{
	up_ = -1,
	down_ = 1
}	t_flag;

/* ************************************************************************** */

// FUUUCCCCKKKKING IMPORTANT!!
 
 /**
  * @brief If new struct type added, add initialize functions
  * 1. initialize_global_variable() in start_shell.c
  * 2. clear_loop() in clear_loop.c 
  * 
  */


/* ************************************************************************** */

//	typedefs for tokenize

typedef struct s_quote_flags
{
	t_flag	double_q_;
	t_flag	single_q_;
}	t_q_flg;


/* ************************************************************************** */

//	TOKEN

/**
 * If operation token type is modified, push_operator() in tokenize_2.c should 
 * also be modified. Also define part of this file which saves the char of 
 * operators should be modified. 
 */
typedef enum e_token_type
{
	none_ = 0,			//	init value
	wd_,				//	initial value of word
	op_pipe_,			//	'|'
	op_redirect_in_1_,	// 	'<'
	op_redirect_in_2_,	// 	'<<'
	op_redirect_out_1_,	// 	'>'
	op_redirect_out_2_,	// 	'>>'
	etc_ = -1			
}	t_t_type;
/**
 * '|' -> delimiter between commands. ';' can be a delimiter of command in 
 * bash. However, in this project, ';' will not be handled. 
 */
typedef struct s_token_node
{
	char				*val_;
	t_t_type			type_;
	struct s_token_node	*next_;
	struct s_token_node	*prev_;
}	t_tkn_nd;

typedef struct s_token_list
{
	t_tkn_nd	*head_;
	t_tkn_nd	*tail_;
	size_t		tkn_cnt_;
}	t_tkn_lst;

/* ************************************************************************** */

//	CMD

typedef enum e_command_type
{
	cmd_non_type_ = 0,
	cmd_built_in_,
	cmd_executable_,
	cmd_type_err_ = -1
}	t_cmd_type;

typedef struct s_command_node
{
	t_cmd_type				type_;
	char					*cmd_path_;
	char					**args_;
	int						fd_read_;
	int						fd_write_;
	struct s_command_node	*next_;
	struct s_command_node	*prev_;
}	t_cmd_nd;

typedef struct s_command_list
{
	t_cmd_nd	*head_;
	t_cmd_nd	*tail_;
	size_t		cmd_cnt_;
}	t_cmd_lst;

/* ************************************************************************** */

//	PIPE

typedef enum e_pipe_end
{
	P_WRITE_ = 1,
	P_READ_ = 0
}	t_p_end;

typedef struct s_pipe
{
	int	fd_[2];
}	t_pipe;


/* ************************************************************************** */

//	VARIABLE

typedef struct s_variable_node
{
	char					*name_;
	char					*val_;
	struct s_variable_node	*next_;
	struct s_variable_node	*prev_;
}	t_var_nd;

typedef struct s_variable_list
{
	t_var_nd	*head_;
	t_var_nd	*tail_;
	size_t		var_cnt_;
}	t_var_lst;

/* ************************************************************************** */

//	t_ptrs : Global variable

typedef struct s_minishell_pointers
{
	char		**envp_;
	t_errno		errno_;
	int			exit_status_;
	t_var_lst	var_lst_;
	t_tkn_lst	tkn_lst_;
	t_cmd_lst	cmd_lst_;
	t_pipe		*pipe_arr_;
	size_t		pipe_cnt_;
}   t_ptrs;

t_ptrs g_ptrs;

/* ************************************************************************** */

//	etc

//		clear_loop.c
void		clear_loop(void);

//		error_handler.c
void		set_t_errno(t_errno error_number);
void		print_error(t_errno error_number);
void		error_handler(t_errno error_number, bool reset_errno);

//		s_command_1.c
t_cmd_nd	*create_cmd_nd(void);
void		terminate_cmd_nd(t_cmd_nd *del_nd);
void		push_cmd_nd_to_lst(t_cmd_lst *cmd_lst, t_cmd_nd *nd_to_push);
void		initialize_cmd_lst(t_cmd_lst *cmd_lst);
void		clear_cmd_lst(t_cmd_lst *cmd_lst);

//		s_token_1.c
void		initialize_tkn_lst(t_tkn_lst *tkn_lst);
void		clear_tkn_lst(t_tkn_lst *tkn_lst);
size_t		push_tkn_nd_to_lst(t_tkn_lst *tkn_lst, const char *str, t_t_type type);

//		s_variable_1.c
void		terminate_var_nd(t_var_nd *del_nd);
t_var_nd	*search_var(t_var_lst *lst, char *name);
t_bool		update_var(t_var_lst *lst, char *target_name, char *new_val);
void		push_var_to_lst(t_var_lst *var_lst, char *name, char *val);

//		s_variable_2.c
void		initialize_var_lst(t_var_lst *var_lst);
void		clear_var_lst(t_var_lst *var_lst);
void		push_envp_to_var_lst(char **envp, t_var_lst *var_list);

//		start_shell.c
void		start_shell(char **envp);
void		print_banner(void);
void		initialize_global_variable(char **envp);
void		handle_signals(void);
void		signal_handler(int signo);

//		utils_for_test.c
void		print_token_list(t_tkn_lst *lst);
/* ************************************************************************** */

//	parsing

//		parsing_1.c
void		parse_token_list(t_tkn_lst *tkn_lst, t_cmd_lst *cmd_lst);


/* ************************************************************************** */

//	tokenize

//		tokenize_1.c
void		tokenize_input(t_tkn_lst *lst);
void		split_input_to_tokens(char *user_input, t_tkn_lst *lst);
bool		is_white_space(unsigned char c);
bool		is_operator(unsigned char c);
bool		is_meta_char(unsigned char c);

//		tokenize_2.c
size_t		push_operator(t_tkn_lst *lst, char *str_ptr);
size_t		push_word(t_tkn_lst *lst, char *str_ptr);
void		convert_variables(t_tkn_lst *lst);

//		tokenize_3.c
void		convert_quoted_strings(t_tkn_lst *lst);

/* ************************************************************************** */

#endif