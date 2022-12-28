/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:08 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/19 13:39:22 by seoyoo           ###   ########.fr       */
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
# include "my_booleans.h"

# include "libft_functions.h"

/* ************************************************************************** */

typedef enum e_token_type
{
    single_quoted_string_ = 0,
    double_quoted_string_,
    redirection_,
    pipe,
    dollar_variable,  // NEED TO BE FIXED, 
    ctrl_commands_,
    builtins_,
    etc = -1
}   t_t_type;

typedef struct s_token_node
{
    char                *str_;
    t_t_type            type_;
    struct s_token_node *next_;
    struct s_token_node *prev_;

}   t_tkn_nd;

typedef struct s_token_list
{
    t_tkn_nd    *head_;
    t_tkn_nd    *tail_;
    size_t      nd_cnt_;
}   t_tkn_lst;


//	etc

//		user_interface.c
void	enter_shell(void);
char	*get_input_from_user(void);

/* ************************************************************************** */

#endif