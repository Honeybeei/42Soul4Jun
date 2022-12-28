/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:59:39 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/28 14:47:56 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ************************************************************************** */

/**
 * @brief Get the stack by t_s_id.
 * 
 * @param stacks 
 * @param s_id 
 * @return t_ch_lst* 
 */
t_ch_lst	*get_stack(t_stacks *stacks, t_s_id s_id)
{
	if (s_id == a_)
		return (&stacks->a_);
	else if (s_id == b_)
		return (&stacks->b_);
	else
		return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Get the chunk by t_s_id and t_dir. 
 * 
 * @param stacks 
 * @param s_id 
 * @param top_or_btm 
 * @return t_chunk 
 */
t_chunk		*get_chunk(t_stacks *stacks, t_s_id s_id, t_dir top_or_btm)
{
	if (s_id == a_)
	{
		if (top_or_btm == top_)
			return (stacks->a_.tail_);
		else if (top_or_btm == btm_)
			return (stacks->a_.head_);
	}
	else if (s_id == b_)
	{
		if (top_or_btm == top_)
			return (stacks->b_.tail_);
		else if (top_or_btm == btm_)
			return (stacks->b_.head_);
	}
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Count all nodes in a stack. 
 * 
 * @param stacks 
 * @param s_id 
 * @return size_t 
 */
size_t	get_nd_cnt(t_stacks *stacks, t_s_id s_id)
{
	size_t	nd_cnt;
	t_chunk	*chunk_ptr;

	nd_cnt = 0;
	chunk_ptr = get_chunk(stacks, s_id, btm_);
	while (chunk_ptr != NULL)
	{
		nd_cnt += chunk_ptr->nd_cnt_;
		chunk_ptr = chunk_ptr->next_;
	}
	return (nd_cnt);
}

/* ************************************************************************** */