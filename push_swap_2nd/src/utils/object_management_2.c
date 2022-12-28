/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_management_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:30:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/27 16:43:26 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	disconnect_chunks(t_chunk *chunk1, t_chunk *chunk2);

/* ************************************************************************** */

/**
 * @brief Initializing function for push_swap.
 * 
 * @param stacks 
 */
void	push_swap_init(t_stacks *stacks)
{
	stacks->a_.head_ = NULL;
	stacks->a_.tail_ = NULL;
	stacks->a_.ch_cnt_ = 0;
	stacks->b_.head_ = NULL;
	stacks->b_.tail_ = NULL;
	stacks->b_.ch_cnt_ = 0;
}

/* ************************************************************************** */

/**
 * @brief Termination function for push_swap.
 * 
 * @param stacks 
 */
void	push_swap_termination(t_stacks *stacks)
{
	clear_chunk_list(&stacks->a_);
	clear_chunk_list(&stacks->b_);
}

/* ************************************************************************** */

/**
 * @brief Push chunk(param1) to dst(param3) of list(param2).
 * WARNING : If chunk or list is NULL, using this function will cause 
 * segmentation fault.
 * 
 * @param chunk 
 * @param list 
 * @param dst 
 */
void	push_chunk(t_chunk *chunk, t_ch_lst *list, t_dir dst)
{
	if (list->ch_cnt_ == 0)
	{
		list->head_ = chunk;
		list->tail_ = chunk;
	}
	else if (dst == head_)
	{
		chunk->next_ = list->head_;
		list->head_->prev_ = chunk;
		list->head_ = chunk;
	}
	else
	{
		list->tail_->next_ = chunk;
		chunk->prev_ = list->tail_;
		list->tail_ = chunk;
	}
	list->ch_cnt_++;
}

/* ************************************************************************** */

/**
 * @brief Pick chunk from src(param2) of list(param1) and returns it. 
 * WARNING : If list is NULL, using this function will cause segmentation fault.
 * 
 * @param list 
 * @param src 
 * @return t_chunk* 
 */
t_chunk	*pick_chunk(t_ch_lst *list, t_dir src)
{
	t_chunk	*chunk_to_return;

	if (list->ch_cnt_ == 0)
		return (NULL);
	else if (list->ch_cnt_ == 1)
	{
		chunk_to_return = list->head_;
		list->head_ = NULL;
		list->tail_ = NULL;
	}
	else if (src == head_)
	{
		chunk_to_return = list->head_;
		list->head_ = list->head_->next_;
		disconnect_chunks(chunk_to_return, list->head_);
	}
	else
	{
		chunk_to_return = list->tail_;
		list->tail_ = list->tail_->prev_;
		disconnect_chunks(list->tail_, chunk_to_return);
	}
	list->ch_cnt_--;
	return (chunk_to_return);
}

/* ************************************************************************** */

static void	disconnect_chunks(t_chunk *chunk1, t_chunk *chunk2)
{
	chunk1->next_ = NULL;
	chunk2->prev_ = NULL;
}

/* ************************************************************************** */