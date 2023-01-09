/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:52:11 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/09 21:38:18 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// static size_t	count_pipes(t_tkn_lst *tkn_lst);

// /* ************************************************************************** */

// // Redirection will also be handled here. 
// void	parse_token_list(t_ptrs *ptrs)
// {
// 	t_tkn_nd	*cmd_start;
// 	t_tkn_nd	*cmd_end;

// 	ptrs->pipe_cnt_ = count_pipes(tkn_lst);
// 	ptrs->pipe_arr_ = my_calloc(ptrs->pipe_cnt_ + 1, sizeof(t_pipe));
// 	set_pipes(ptrs->pipe_arr_, ptrs->pipe_cnt_);  // TODO
// 	cmd_start = ptrs->tkn_lst_.head_;
// 	while (true)
// 	{
// 		cmd_end = cmd_start;
// 		if (cmd_end == NULL)
// 			return (push_cmd_nd_to_lst(ptrs->cmd_lst_, convert_tkns_to_cmd(cmd_start, cmd_end)));
// 		else if (cmd_end->type_ == op_pipe_)
// 		{
// 			push_cmd_nd_to_lst(ptrs->cmd_lst_, convert_tkns_to_cmd(cmd_start, cmd_end));
// 			cmd_start = cmd_end->next_;
// 		}
// 		else
// 			cmd_end = cmd_end->next_;
// 	}
	
// }

// /* ************************************************************************** */

// static size_t	count_pipes(t_tkn_lst *tkn_lst)
// {
// 	size_t		pipe_cnt;
// 	t_tkn_nd	*nd_ptr;

// 	pipe_cnt = 0;
// 	nd_ptr = tkn_lst->head_;
// 	while (nd_ptr != NULL)
// 	{
// 		if (nd_ptr->type_ == op_pipe_)
// 			pipe_cnt++;
// 		nd_ptr = nd_ptr->next_;
// 	}
// 	return (pipe_cnt);
// }

// /* ************************************************************************** */

// /**
//  * @brief Convert tokens to cmd_nd(newly created) and returns it. 
//  * 
//  */
// t_cmd_nd	*convert_tkns_to_cmd(t_tkn_nd *start, t_tkn_nd *end)
// {
// 	t_cmd_nd	*new_cmd;

// 	new_cmd.
// }

// /* ************************************************************************** */



// /* ************************************************************************** */



// /* ************************************************************************** */