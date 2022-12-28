/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_management_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:30:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/23 16:21:05 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static t_nd	*pick_top_t_nd(t_stack *stack);
static t_nd	*pick_btm_t_nd(t_stack *stack);

/* ************************************************************************** */

/**
 * @brief Terminate t_stacks.
 * 
 * @param stacks 
 * @return void* 
 */
void	*terminate_t_stacks(t_stacks *stacks)
{
	if (stacks == NULL)
		return (NULL);
	terminate_t_stack(stacks->a_);
	terminate_t_stack(stacks->b_);
	free(stacks);
	return (NULL);
}

/* ************************************************************************** */

/**
 * @brief Pick out a single node from t_stack. Picked node will be disconnected 
 * from connected nodes in t_stack. If there are no node to pick, NULL will be
 * returned. 
 * 
 * @param stack 
 * @param from 
 * @return t_nd* 
 */
t_nd	*pick_t_nd(t_stack *stack, t_dir from)
{
	t_nd	*picked_nd;

	if (stack == NULL || stack->nd_cnt_ == 0)
		return (NULL);
	if (stack->nd_cnt_ == 1)
	{
		picked_nd = stack->top_;
		stack->top_ = NULL;
		stack->btm_ = NULL;
	}
	else if (from == top_)
		picked_nd = pick_top_t_nd(stack);
	else
		picked_nd = pick_btm_t_nd(stack);
	stack->nd_cnt_--;
	return (picked_nd);
}

/* ************************************************************************** */

static t_nd	*pick_top_t_nd(t_stack *stack)
{
	t_nd	*picked_nd;

	picked_nd = stack->top_;
	stack->top_ = stack->top_->prev_;
	picked_nd->prev_ = NULL;
	stack->top_->next_ = NULL;
	return (picked_nd);
}

/* ************************************************************************** */

static t_nd	*pick_btm_t_nd(t_stack *stack)
{
	t_nd	*picked_nd;

	picked_nd = stack->btm_;
	stack->btm_ = stack->btm_->next_;
	picked_nd->next_ = NULL;
	stack->btm_->prev_ = NULL;
	return (picked_nd);
}

/* ************************************************************************** */

/**
 * @brief Push node to stack. Returns NULL when stack or node is NULL. 
 * 
 * @param stack 
 * @param node 
 * @param to 
 * @return t_stack* 
 */
t_stack	*push_t_nd(t_stack *stack, t_nd *node, t_dir to)
{
	if (stack == NULL || node == NULL)
		return (NULL);
	if (stack->nd_cnt_ == 0)
	{
		stack->btm_ = node;
		stack->top_ = node;
	}
	else if (to == btm_)
	{
		node->next_ = stack->btm_;
		stack->btm_->prev_ = node;
		stack->btm_ = node;
	}
	else
	{
		stack->top_->next_ = node;
		node->prev_ = stack->top_;
		stack->top_ = node;
	}
	stack->nd_cnt_++;
	return (stack);
}

/* ************************************************************************** */