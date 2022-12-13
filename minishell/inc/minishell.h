/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:08 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/13 15:52:19 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>				// printf()
# include <stdlib.h>			// free()
# include <stdbool.h>           // true, false
# include <readline/readline.h>	// readline(), 
# include <readline/history.h>	// add_history()

# include "ascii_art.h"
# include "def_str.h"

/* ************************************************************************** */

typedef enum e_my_booleans
{
	no_err_ = 0,
	yes_err_ = -1
}	t_bool;

typedef struct s_user_input
{
	int     str_cnt_;
	char    **str_arr_;
}	t_input;

/* ************************************************************************** */

//	etc

//		blabla1.c
void	say_hello(int n);

//		user_interface.c
void	enter_shell(void);

//		get_input.c
t_input	*get_input_from_user(void);

/* ************************************************************************** */

//	object_management

//		manage_t_input
t_input	*init_t_input(void);
int		terminate_t_input(t_input *input);

/* ************************************************************************** */

/* ************************************************************************** */


#endif