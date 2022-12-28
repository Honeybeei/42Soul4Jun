/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_management_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:16:43 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/26 22:04:57 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ************************************************************************** */

/**
 * @brief Returns matching t_stack.
 * 
 * @param stacks 
 * @param stack_id 
 * @return t_stack* 
 */
t_stack	*get_stack(t_stacks *stacks, t_s_id stack_id)
{
	if (stack_id == a_)
		return (stacks->a_);
	else if (stack_id == b_)
		return (stacks->b_);
	else
		return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Malloc and initialize t_chunk
 * 
 * @return t_chunk* 
 */
t_chunk	*init_t_chunk(void)
{
	t_chunk	*new_chunk;

	new_chunk = ft_calloc(1, sizeof(t_chunk));
	if (new_chunk == NULL)
		return (NULL);
	new_chunk->nd_cnt_ = 0;
	return (new_chunk);
}

/* ************************************************************************** */

void	*terminate_t_chunk(t_chunk *del_chunk)
{
	if (del_chunk == NULL)
		return (NULL);
	free(del_chunk);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Malloc and initialize t_ch_list.
 * 
 * @return t_ch_list* 
 */
t_ch_list	*init_t_ch_list(void)
{
	t_ch_list	*new_ch_list;

	new_ch_list = ft_calloc(1, sizeof(t_ch_list));
	if (new_ch_list == NULL)
		return (NULL);
	new_ch_list->chunk_cnt_ = 0;
	return (new_ch_list);
}

/* ************************************************************************** */

void	*terminate_t_ch_list(t_ch_list *del_list)
{
	t_chunk	*del_chunk;

	if (del_list == NULL)
		return (NULL);
	del_chunk = del_list->btm_;
	while (del_list->btm_ != NULL)
	{
		del_chunk = del_list->btm_;
		del_list->btm_ = del_list->btm_->next_;
		terminate_t_chunk(del_chunk);
	}
	free(del_list);
	return (NULL);
}

/* ************************************************************************** */