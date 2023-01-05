/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:44:18 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/05 15:26:55 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

//	if invalid command or error -> return NULL;

/**
 * @brief Convert token list to command array. tkn_lst->pipe_cnt_ + 1 will be
 *  the number of commands executed. Therefore tkn_lst->pipe_cnt_ + 1 number 
 * of t_cmd will be malloced to cmd_arr.
 * 
 * @param tkn_lst 
 * @param cmd_arr 
 * @return t_bool 
 */
t_bool	convert_tkn_lst_to_cmd_arr(t_tkn_lst *tkn_lst, t_cmd_arr *cmd_arr)
{
	// split tokens
	// malloc command array
	// malloc pipes
	// read splitted token list 
	//		if error -> terminate splitted list
	t_tkn_lst	*lists;

	lists = split_token_list(tkn_lst);
	
}

/* ************************************************************************** */

t_tkn_lst	*split_token_list(t_tkn_lst *list)
{
	t_tkn_lst	*lists;
	size_t		i;
	t_tkn_nd	*ctrl_operator_ptr;

	lists = calloc_safe(list->pipe_cnt_ + 1, sizeof(t_tkn_lst));
	ctrl_operator_ptr = list->head_;
	i = 0;
	while (i < list->pipe_cnt_ + 1)
	{
		ctrl_operator_ptr = search_ctrl_operator(ctrl_operator_ptr);
		lists[i].
	}
	
}

/* ************************************************************************** */

t_tkn_nd	*search_ctrl_operator(t_tkn_nd *node)
{
	if (node == NULL)
		return (NULL);
	if (node->type_ == op_control_)
		node
}

/* ************************************************************************** */