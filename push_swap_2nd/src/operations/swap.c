/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:55:11 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/28 14:57:23 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ************************************************************************** */

/**
 * @brief Swap top two node in the stack. Only works when there are two or more 
 * nodes at top of top chunk of the list. 
 * 
 * @param stacks 
 * @param s_id 
 * @return t_bool 
 */
t_bool	op_swap(t_stacks *stacks, t_s_id s_id)
{
	t_chunk	*top_chunk;
	t_nd	*nd_1;
	t_nd	*nd_2;

	if (stacks == NULL || get_nd_cnt(stacks, s_id) < 2)
		return (fail_);
	if (get_chunk(stacks, s_id, top_)->nd_cnt_ < 2)
		return (fail_);
	top_chunk = get_chunk(stacks, s_id, top_);
	nd_1 = pick_node(top_chunk, top_);
	nd_2 = pick_node(top_chunk, top_);
	push_node(nd_1, top_chunk, top_);
	push_node(nd_2, top_chunk, top_);
	return (success_);
}

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */