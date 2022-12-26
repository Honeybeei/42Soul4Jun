/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:03:55 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/26 22:31:43 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	sort_top3_in_ascending_order(t_stacks *stacks, t_s_id target);
static void	sort_top3_in_descending_order(t_stacks *stacks, t_s_id target);

/* ************************************************************************** */

/**
 * @brief Sort stack A in ascending order. 
 * 
 * @param stacks 
 */
void	sort(t_stacks *stacks)
{
	// t_ch_list	*chunk_list;

	if (stacks->a_->nd_cnt_ < 2)
		return ;
	else if (check_is_sorted(stacks->a_, asc_) == true)
		return ;
	else if (check_is_sorted(stacks->a_, desc_) == true)
		return ;
	else if (stacks->a_->nd_cnt_ == 2)
		sort_top2(stacks, a_, asc_);
	else if (stacks->a_->nd_cnt_ == 3)
		sort_top3(stacks, a_, asc_);
	else
	{
		split_stack_into_chunks(stacks);
		merge_chunks(stacks);  // TODO
	}
}

/* ************************************************************************** */

/**
 * @brief Sort top 2 node in target_stack.
 * 
 * @param stacks 
 * @param target_stack 
 * @param order 
 */
void sort_top2(t_stacks *stacks, t_s_id target_stack, t_dir order)
{
	t_nd	*nd_1;
	t_nd	*nd_2;

	nd_1 = get_stack(stacks, target_stack)->top_;
	nd_2 = nd_1->prev_;
	if (nd_1->n_ > nd_2->n_ && order == desc_)
		op_swap(stacks, target_stack);
	else if (nd_1->n_ < nd_2->n_ && order == asc_)
		op_swap(stacks, target_stack);
}

/* ************************************************************************** */

void	sort_top3(t_stacks *stacks, t_s_id target_stack, t_dir order)
{
	if (order == asc_)
		sort_top3_in_ascending_order(stacks, target_stack);
	else
		sort_top3_in_descending_order(stacks, target_stack);
}

/* ************************************************************************** */

static void	sort_top3_in_ascending_order(t_stacks *stacks, t_s_id target)
{
	t_nd	*nd[3];

	nd[0] = get_stack(stacks, target)->top_;
	nd[1] = nd[0]->prev_;
	nd[2] = nd[1]->prev_;
	if (nd[0]->n_ > nd[2]->n_ && nd[2]->n_ > nd[1]->n_)
	{
		op_rotate(stacks, target, up_);
		op_swap(stacks, target);
		op_rotate(stacks, target, down_);
	}
	else if (nd[1]->n_ > nd[0]->n_ && nd[1]->n_ > nd[2]->n_)
	{
		op_swap(stacks, target);
		op_rotate(stacks, target, up_);
		sort_top2(stacks, target, asc_);
		op_rotate(stacks, target, down_);
	}
	else if (nd[2]->n_ > nd[0]->n_ && nd[2]->n_ > nd[1]->n_)
	{
		op_push_n(stacks, target * -1, 2);
		op_rotate(stacks, target, up_);
		op_push_n(stacks, target, 2);
		sort_top2(stacks, target, asc_);
		op_rotate(stacks, target, down_);
	}
}

/* ************************************************************************** */

static void	sort_top3_in_descending_order(t_stacks *stacks, t_s_id target)
{
	t_nd	*nd[3];

	nd[0] = get_stack(stacks, target)->top_;
	nd[1] = nd[0]->prev_;
	nd[2] = nd[1]->prev_;
	if (nd[0]->n_ < nd[2]->n_ && nd[2]->n_ < nd[1]->n_)
	{
		op_rotate(stacks, target, up_);
		op_swap(stacks, target);
		op_rotate(stacks, target, down_);
	}
	else if (nd[1]->n_ < nd[0]->n_ && nd[1]->n_ < nd[2]->n_)
	{
		op_swap(stacks, target);
		op_rotate(stacks, target, up_);
		sort_top2(stacks, target, desc_);
		op_rotate(stacks, target, down_);
	}
	else if (nd[2]->n_ < nd[0]->n_ && nd[2]->n_ < nd[1]->n_)
	{
		op_push_n(stacks, target * -1, 2);
		op_rotate(stacks, target, up_);
		op_push_n(stacks, target, 2);
		sort_top2(stacks, target, desc_);
		op_rotate(stacks, target, down_);
	}
}

/* ************************************************************************** */