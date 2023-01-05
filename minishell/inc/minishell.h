/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:08 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/04 16:02:31 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */

# include <stdio.h>				// printf()
# include <stdlib.h>			// malloc(), free()
# include <stdbool.h>           // true, false
# include <readline/readline.h>	// readline(), 
# include <readline/history.h>	// add_history()
# include <unistd.h>			// STDERR_FILENO
# include <signal.h>			// signal(), SIGINT, SIGQUIT
# include <stddef.h>			// size_t
# include "ascii_art.h"

/* ************************************************************************** */

# define PROMPT_STR "Jsh -> "

/* ************************************************************************** */

// Customized booleans
typedef enum e_my_booleans
{
	head_ = -1,
	tail_ = 1,
	down_ = -1,
	up_ = 1,
	invalid_ = -1,
	valid_ = 1,
	fail_ = -1,
	success_ = 1
}	t_bool;

typedef	enum e_my_errno
{
	no_err_ = 0,
	err_malloc_fail_,
	err_etc_
}	t_errno;

/* ************************************************************************** */

// TOKEN AND TOKEN LIST

/**
 * Token types
 * 
 *	1. Word
 * 		a. Filename
 * 		b. Argument
 * 	2. Operator
 * 		a. Control operator
 * 		b. Redirection operator
 * 
 */

typedef enum e_token_type
{
	none_ = 0,			//	type init value
	wd_filename_,		//	name of command or directory of command files. 
	wd_argument_,		//	arguments in a single string. 
	op_control_,		//	'|'
	op_redirection_,	// 	'>', '>>', '<', '<<'
	etc_ = -1			//	Rest of types. Will be treated as an error
}	t_t_type;

typedef struct s_token_node
{
	char                *str_;
	t_t_type            type_;
	struct s_token_node *next_;
	struct s_token_node *prev_;
}	t_tkn_nd;

typedef struct s_token_list
{
	t_tkn_nd    *head_;
	t_tkn_nd    *tail_;
	size_t      tkn_cnt_;
	size_t		pipe_cnt_;
}	t_tkn_lst;

/* ************************************************************************** */

// VARIABLE AND VARIABLE LIST

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

//	COMMAND AND COMMAND ARRAY

typedef enum e_pipe_end
{
	P_WRITE_ = 1,
	P_READ_ = 0
}	t_p_end;

typedef struct s_pipe
{
	int fd_[2];
	int	pipe_id_;
}	t_pipe;

typedef struct s_command
{
	pid_t	pid_;
	char	*cmd_name_;
	char	*cmd_dir_;		// if cmd_dir_ == NULL -> it is built in command
	char	*args_;
	int		fd_r_;
	int		fd_w_;
}	t_cmd;

typedef struct s_command_array
{
	t_cmd	*arr_;
	size_t	cmd_cnt_;
	t_pipe	*pipe_arr_;
}	t_cmd_arr;

/* ************************************************************************** */

// Global variable

typedef struct s_minishell_pointers
{
	char		**envp_;
	char		*user_input_;
	t_tkn_lst	token_list_;
	t_var_lst	variable_list_;
	t_cmd_arr	cmd_arr_;
	t_errno		errno_;		// It should be setted to no_err_ right after error is printed. 
}	t_ptrs;

t_ptrs g_ptrs;

/* ************************************************************************** */

//	conversion

//		token_list_conversion.c
t_bool		convert_tkn_lst_to_cmd_arr(t_tkn_lst *tkn_lst, t_cmd_arr *cmd_arr);

/* ************************************************************************** */

//	etc

//		error_management.c
void		print_error_msg(t_errno errno);
void		manage_error_cases(void);

//		init_and_termination.c
void		init_ptrs(t_ptrs *ptrs, char **envp);
void		clear_loop(t_ptrs *ptrs);
void		termination_ptcl(t_ptrs *ptrs);

//		input_management.c
char		*get_input_from_user(void);

//		safe_malloc.c
void		*calloc_safe(size_t count, size_t size);

//		start_shell.c
void		start_shell(void);

//		variable_control.c
void		push_envp_to_var_lst(char **envp, t_var_lst *var_list);

/* ************************************************************************** */

//	execution

//		execution_main.c
void		execute_commands(t_cmd_arr *cmd_arr);

/* ************************************************************************** */

//	libft_functions

//		str_functions_1.c
size_t		ft_strlen(const char *str);
char		*ft_strncpy(char *dst, const char *src, size_t cpy_len);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t cmp_len);

//		str_functions_2.c
void		ft_putstr_fd(char *str, int fd);
int			ft_strcmp(const char *s1, const char *s2);

/* ************************************************************************** */

//	object_management

//		cmd_management.c
void		init_cmd_arr(t_cmd_arr *cmd_arr);
void		clear_cmd_arr(t_cmd_arr *cmd_arr);
void		init_cmd(t_cmd *cmd);

//		token_management.c
void		init_token_list(t_tkn_lst *token_list);
void		clear_token_list(t_tkn_lst *token_list);
void		push_tkn_nd_to_list(t_tkn_lst *list, const char *str, t_t_type type);

//		variable_management.c
void		init_variable_list(t_var_lst *var_list);
void		clear_variable_list(t_var_lst *var_list);
void		terminate_variable_node(t_var_nd *del_nd);
void		push_var_nd_to_list(t_var_lst *list, const char *name, const char *value);
t_var_nd	*search_matching_var(t_var_lst *list, const char *name);
void		update_var_val_(t_var_lst *list, const char *target_name, const char *update_val);

/* ************************************************************************** */

//	tokenizer
void		tokenize_user_input(t_tkn_lst *list, char *user_input);

/* ************************************************************************** */

#endif