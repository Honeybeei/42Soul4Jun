/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:08 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 11:39:47 by seoyoo           ###   ########.fr       */
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

# include "../my_lib/inc/libft.h"
# include "../my_lib/inc/my_str.h"
# include "ascii_art.h"

/* ************************************************************************** */

# define PROMPT_STR "Jsh -> "

# define META_CHAR "<>|"
//	There are more meta-characters but in minishell, only this three will be 
//	treated as a meta-character. 

/* ************************************************************************** */

typedef enum e_customized_error_number
{
	err_no_errors_ = 0
}	t_errno;

typedef enum e_customized_boolean
{
	success_ = 0,
	fail_ = 1
}	t_bool;

/* ************************************************************************** */

//	TOKEN

typedef enum e_token_type
{
	none_ = 0,			//	init value
	wd_non_quoted_,
	wd_single_quoted_,
	wd_double_quoted_,
	op_pipe_,			//	'|'
	op_redirect_in_1_,	// 	'<'
	op_redirect_in_2_,	// 	'<<'
	op_redirect_out_1_,	// 	'>'
	op_redirect_out_2_,	// 	'>>'
	etc_ = -1			
}	t_t_type;

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
	built_in_cmd_ = 0,
	executable_cmd_,
	cmd_type_err_ = -1
}	t_cmd_type;

typedef enum e_pipe_end
{
	P_WRITE_ = 1,
	P_READ_ = 0
}	t_p_end;

typedef struct s_command
{
	pid_t		pid_;
	t_cmd_type	type_;
	char		*cmd_path_;
	char		**args_;
	int			fd_r_;
	int			fd_w_;
}	t_cmd;

typedef struct s_pipe
{
	int		fd_[2];
	t_cmd	*cmd_to_read_;
	t_cmd	*cmd_to_write_;
}	t_pipe;

typedef struct s_command_array
{
	t_cmd	*arr_;
	size_t	cmd_cnt_;
	t_pipe	*pipe_arr_;
}	t_cmd_arr;

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

typedef struct s_minishell_pointers
{
	char		**envp_;
	t_errno		errno_;
	int			exit_status_;
	t_var_lst	var_lst_;
	t_tkn_lst	tkn_lst_;

}   t_ptrs;

t_ptrs g_ptrs;

/* ************************************************************************** */

//	etc

//		error_handler.c
void		set_t_errno(t_errno errno);

//		s_token_1.c
void		initialize_tkn_lst(t_tkn_lst *tkn_lst);
void		clear_tkn_lst(t_tkn_lst *tkn_lst);
void		push_tkn_nd_to_lst(t_tkn_lst *tkn_lst, const char *str, t_t_type type);

//		s_variable_1.c
void		terminate_var_nd(t_var_nd *del_nd);
t_var_nd	*search_var(t_var_lst *lst, char *name);
t_bool		update_var(t_var_lst *lst, char *target_name, char *new_val);
void		push_var_to_lst(t_var_lst *var_lst, char *name, char *val);

//		s_variable_2.c
void		initialize_var_lst(t_var_lst *var_lst);
void		clear_var_lst(t_var_lst *var_lst);
void		push_envp_to_var_lst(char **envp, t_var_lst *var_list);

//		safe_malloc.c
void		*malloc_safe(size_t size);
void		*calloc_safe(size_t count, size_t size);

//		start_shell.c
void		start_shell(char **envp);
void		print_banner(void);
void		initialize_global_variable(char **envp);
void		handle_signals(void);
void		signal_handler(int signo);

/* ************************************************************************** */
//	tokenize

//		tokenize_1.c
void		tokenize_input(t_tkn_lst *lst);

#endif