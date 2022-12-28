/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_management_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:30:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/27 20:10:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	disconnect_nodes(t_nd *nd1, t_nd *nd2);

/* ************************************************************************** */

/**
 * @brief Pop chunk from src(param2) of list(param1).
 * 
 * @param list 
 * @param src 
 */
void	pop_chunk(t_ch_lst *list, t_dir src)
{
	terminate_chunk(pick_chunk(list, src));
}

/* ************************************************************************** */

/**
 * @brief Push node(param1) to dst(param3) of chunk(param2).
 * WARNING : If node or chunk is NULL, using this function will cause 
 * segmentation fault.
 * 
 * @param node 
 * @param chunk 
 * @param dst 
 */
void	push_node(t_nd *node, t_chunk *chunk, t_dir dst)
{
	if (chunk->nd_cnt_ == 0)
	{
		chunk->head_ = node;
		chunk->tail_ = node;
	}
	else if (dst == head_)
	{
		node->next_ = chunk->head_;
		chunk->head_->prev_ = node;
		chunk->head_ = node;
	}
	else
	{
		chunk->tail_->next_ = node;
		node->prev_ = chunk->tail_;
		chunk->tail_ = node;
	}
	chunk->nd_cnt_++;
}

/* ************************************************************************** */

/**
 * @brief Pick node from src(param2) of chunk(param1) and returns it. 
 * WARNING : If chunk is NULL, using this function will cause segmentation fault
 * .
 * 
 * @param chunk 
 * @param src 
 * @return t_nd* 
 */
t_nd	*pick_node(t_chunk *chunk, t_dir src)
{
	t_nd	*node_to_return;

	if (chunk->nd_cnt_ == 0)
		return (NULL);
	else if (chunk->nd_cnt_ == 1)
	{
		node_to_return = chunk->head_;
		chunk->head_ = NULL;
		chunk->tail_ = NULL;
	}
	else if (src == head_)
	{
		node_to_return = chunk->head_;
		chunk->head_ = chunk->head_->next_;
		disconnect_nodes(node_to_return, chunk->head_);
	}
	else
	{
		node_to_return = chunk->tail_;
		chunk->tail_ = chunk->tail_->prev_;
		disconnect_nodes(chunk->tail_, node_to_return);
	}
	chunk->nd_cnt_--;
	return (node_to_return);
}

/* ************************************************************************** */

static void	disconnect_nodes(t_nd *nd1, t_nd *nd2)
{
	nd1->next_ = NULL;
	nd2->prev_ = NULL;
}

/* ************************************************************************** */

/**
 * @brief Pop chunk from src(param2) of chunk(param1)
 * 
 * @param chunk 
 * @param src 
 */
void	pop_node(t_chunk *chunk, t_dir src)
{
	terminate_node(pick_node(chunk, src));
}

/* ************************************************************************** */