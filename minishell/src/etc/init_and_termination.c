/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_termination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:25:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/03 14:19:00 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Initialization at the beginning of JSH.
 * 
 * @param ptrs 
 * @param envp 
 */
void	init_ptrs(t_ptrs *ptrs, char **envp)
{
	ptrs->envp_ = envp;
	// init user input string
	ptrs->user_input_ = NULL;

	// init token list
	init_token_list(&ptrs->token_list_);

	// init variable list
	init_variable_list(&ptrs->variable_list_);
	push_envp_to_var_lst(envp, &ptrs->variable_list_);
	push_var_nd_to_list(&ptrs->variable_list_, "?", "0");

	// init command array
	init_cmd_arr(&ptrs->cmd_arr_);

	// init errno
	ptrs->errno_ = no_err_;
}

/* ************************************************************************** */

/**
 * @brief Clear malloced objects(except variable_list) and initialize it. 
 * 
 * @param ptrs 
 */
void	clear_loop(t_ptrs *ptrs)
{
	if (ptrs == NULL)
		return ;
	free(ptrs->user_input_);
	ptrs->user_input_ = NULL;
	clear_token_list(&ptrs->token_list_);
	init_token_list(&ptrs->token_list_);
	clear_cmd_arr(&ptrs->cmd_arr_);
	init_cmd_arr(&ptrs->cmd_arr_);
	ptrs->errno_ = no_err_;
}

/* ************************************************************************** */

/**
 * @brief Terminate every malloced object in current process. 
 * 
 * @param ptrs 
 */
void	termination_ptcl(t_ptrs *ptrs)
{
	clear_loop(ptrs);
	ptrs->envp_ = NULL;
	clear_variable_list(&ptrs->variable_list_);
}

/* ************************************************************************** */