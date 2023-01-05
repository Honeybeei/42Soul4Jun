/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:09:24 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/05 14:49:44 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Initialize command array.
 * 
 * @param cmd_arr 
 */
void	init_cmd_arr(t_cmd_arr *cmd_arr)
{
	if (cmd_arr == NULL)
		return ;
	cmd_arr->arr_ = NULL;
	cmd_arr->cmd_cnt_ = 0;
	cmd_arr->pipe_arr_ = NULL;
}

/* ************************************************************************** */

/**
 * @brief Clear command array. Free all malloced commands. 
 * 
 * @param cmd_arr 
 */
void	clear_cmd_arr(t_cmd_arr *cmd_arr)
{
	if (cmd_arr == NULL)
		return ;
	free(cmd_arr->arr_);
	cmd_arr->arr_ = NULL;
	cmd_arr->cmd_cnt_ = 0;
	free(cmd_arr->pipe_arr_);
}

/* ************************************************************************** */

/**
 * @brief Initialize t_cmd. 
 * 
 * @param cmd 
 */
void	init_cmd(t_cmd *cmd)
{
	cmd->pid_ = 0;
	cmd->cmd_name_ = NULL;
	cmd->cmd_dir_ = NULL;
	cmd->args_ = NULL;
	cmd->fd_r_ = STDIN_FILENO;
	cmd->fd_w_ = STDOUT_FILENO;
}

/* ************************************************************************** */
