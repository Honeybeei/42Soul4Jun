/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:10:55 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/28 14:47:22 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ************************************************************************** */

/**
 * @brief Push arguments(arg_arr) to stack. 
 * 
 * @param stacks 
 * @param arg_arr 
 * @param argc 
 */
void	push_args_to_stack(t_stacks *stacks, int *arg_arr, int argc)
{
	int	idx;

	push_chunk(make_chunk(), &stacks->a_, head_);
	idx = 0;
	while (idx < argc - 1)
	{
		push_node(make_node(arg_arr[idx]), stacks->a_.head_, head_);
		idx++;
	}
}

/* ************************************************************************** */

void	sort(t_stacks *stacks)
{
	if (stacks->a_.ch_cnt_ < 2)
		return;
	// else if (stacks->a_.ch_cnt_ == 2)
	// 	sort_top2_node(stacks);
	// else if (stacks->a_.ch_cnt_ == 3)
	// 	sort_top3_node(stacks);
	// else
	// 	divide_and_merge(stacks);
}

/* ************************************************************************** */

/**
 * @brief Sort top two nodes. This function will only be used in hardcoded 
 * sorting. Which means it will be used in the case when there are only a single
 * chunk at stack A.
 * 
 * @param stacks 
 */
void	sort_top2_node(t_stacks *stacks, t_order order)
{
	t_nd	*nd_1;
	t_nd	*nd_2;

	nd_1 = get_chunk(stacks, a_, top_)->tail_;
	nd_2 = nd_1->prev_;
	if ((order == asc_ && nd_1->n_ < nd_2->n_) || (order == desc_ && nd_1->n_ > nd_2->n_))
		op_swap(stacks, a_);
}

/* ************************************************************************** */


/* ************************************************************************** */


/* ************************************************************************** */


/* ************************************************************************** */