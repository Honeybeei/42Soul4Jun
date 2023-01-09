/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:56:10 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/09 21:03:27 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Create a command node. 
 * 
 * @return t_cmd_nd* 
 */
t_cmd_nd	*create_cmd_nd(void)
{
	t_cmd_nd	*new_node;

	new_node = my_calloc(1, sizeof(t_cmd_nd));
	new_node->type_ = cmd_non_type_;
	new_node->fd_read_ = STDIN_FILENO;
	new_node->fd_write_ = STDOUT_FILENO;
	return (new_node);
}

/* ************************************************************************** */

/**
 * @brief Terminate designated node(param1)
 * 
 * @param del_nd 
 */
void	terminate_cmd_nd(t_cmd_nd *del_nd)
{
	size_t	i;

	if (del_nd == NULL)
		return ;
	free(del_nd->cmd_path_);
	i = 0;
	if (del_nd->args_ != NULL)
	{
		while (del_nd->args_[i] != NULL)
			free(del_nd->args_[i++]);
		free(del_nd->args_);
	}
}

/* ************************************************************************** */

/**
 * @brief Push a command node(param2) to the tail of the command list(param1)
 * 
 * @param cmd_lst 
 * @param nd_to_push 
 */
void	push_cmd_nd_to_lst(t_cmd_lst *cmd_lst, t_cmd_nd *nd_to_push)
{
	if (cmd_lst == NULL || nd_to_push == NULL)
		return ;
	if (cmd_lst->cmd_cnt_ == 0)
	{
		cmd_lst->head_ = nd_to_push;
		cmd_lst->tail_ = nd_to_push;
	}
	else
	{
		cmd_lst->tail_->next_ = nd_to_push;
		nd_to_push->prev_ = cmd_lst->tail_;
		cmd_lst->tail_ = cmd_lst->tail_->next_;
	}
	cmd_lst->cmd_cnt_++;
}

/* ************************************************************************** */

/**
 * @brief Initialize command list. 
 * 
 * @param cmd_lst 
 */
void	initialize_cmd_lst(t_cmd_lst *cmd_lst)
{
	if (cmd_lst == NULL)
		return ;
	cmd_lst->head_ = NULL;
	cmd_lst->tail_ = NULL;
	cmd_lst->cmd_cnt_ = 0;
}

/* ************************************************************************** */

/**
 * @brief Clear command list by terminating all command nodes in the list. 
 * 
 * @param cmd_lst 
 */
void	clear_cmd_lst(t_cmd_lst *cmd_lst)
{
	t_cmd_nd	*del_nd;

	if (cmd_lst == NULL)
		return ;
	while (cmd_lst->head_ != NULL)
	{
		del_nd = cmd_lst->head_;
		cmd_lst->head_ = cmd_lst->head_->next_;
		terminate_cmd_nd(del_nd);
	}
	initialize_cmd_lst(cmd_lst);
}

/* ************************************************************************** */