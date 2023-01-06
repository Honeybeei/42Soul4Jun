/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:08 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 21:55:49 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */
# include <unistd.h>		//  STDIN_FILENO, STDERR_FILENO, 
# include <stdlib.h>        //  EXIT_FAILURE, 
# include <stdbool.h>		//	true, false
# include <stdio.h>			//	printf(), perror()
# include <errno.h>
# include <termios.h>		//	tcgetattr(), tcsetattr()

# include "../my_lib/inc/libft.h"
# include "../my_lib/inc/my_str.h"
# include "ascii_art.h"

/* ************************************************************************** */

# define PROMPT_STR "Jsh -> "

/* ************************************************************************** */

typedef enum e_customized_error_number
{
	err_no_ = 0
}	t_errno;

typedef enum e_customized_boolean
{
	success_ = 0,
	fail_ = 1
}	t_bool;

/* ************************************************************************** */

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
	char		*user_input_;
	t_var_lst	var_lst_;
	t_errno		errno_;

}   t_ptrs;

t_ptrs g_ptrs;

/* ************************************************************************** */

//	etc

//		error_handler.c
void		set_t_errno(t_errno errno);

//		s_variable_1.c
void		terminate_var_nd(t_var_nd *del_nd);
t_var_nd	*search_var(t_var_lst *lst, char *name);
t_bool		update_var(t_var_lst *lst, char *target_name, char *new_val);
void		push_var_to_lst(t_var_lst *var_lst, char *name, char *val);

//		s_variable_2.c
void		initialize_var_lst(t_var_lst *var_lst);
void		clear_var_lst(t_var_lst *var_lst);

//		safe_malloc.c
void		*malloc_safe(size_t size);
void		*calloc_safe(size_t count, size_t size);

//		start_shell.c
void		start_shell(char **envp);

/* ************************************************************************** */

#endif