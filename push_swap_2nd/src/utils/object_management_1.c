/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_management_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:30:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/27 16:41:59 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ************************************************************************** */

/**
 * @brief Make new t_nd.
 * 
 * @param n 
 * @return t_nd* 
 */
t_nd	*make_node(int n)
{
	t_nd	*new_node;

	new_node = ft_calloc(1, sizeof(t_nd));
	if (new_node == NULL)
		return (NULL);
	new_node->n_ = n;
	return (new_node);
}

/* ************************************************************************** */

/**
 * @brief Terminate t_nd.
 * 
 * @param del_node 
 * @return void* 
 */
void	*terminate_node(t_nd *del_node)
{
	if (del_node != NULL)
		free(del_node);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Make new t_chunk.
 * 
 * @return t_chunk* 
 */
t_chunk	*make_chunk(void)
{
	t_chunk	*new_chunk;

	new_chunk = ft_calloc(1, sizeof(t_chunk));
	if (new_chunk == NULL)
		return (NULL);
	new_chunk->nd_cnt_ = 0;
	return (new_chunk);
}

/* ************************************************************************** */

/**
 * @brief Terminate t_chunk.
 * 
 * @param del_chunk 
 * @return void* 
 */
void	*terminate_chunk(t_chunk *del_chunk)
{
	t_nd	*del_nd;

	if (del_chunk == NULL)
		return (NULL);
	while (del_chunk->head_ != NULL)
	{
		del_nd = del_chunk->head_;
		del_chunk->head_ = del_chunk->head_->next_;
		terminate_node(del_nd);
	}
	free(del_chunk);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Clear t_ch_list. Terminate all chunks and nodes in del_list. 
 * 
 * @param del_list 
 * @return void* 
 */
void	clear_chunk_list(t_ch_lst *list)
{
	t_chunk	*del_chunk;

	while (list->head_ != NULL)
	{
		del_chunk = list->head_;
		list->head_ = list->head_->next_;
		terminate_chunk(del_chunk);
	}
}

/* ************************************************************************** */