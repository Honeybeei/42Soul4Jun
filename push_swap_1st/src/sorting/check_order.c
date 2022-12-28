/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:37:40 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/25 15:06:01 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static bool	check_sorted_asc_order(t_stack *stack);
static bool	check_sorted_desc_order(t_stack *stack);

/* ************************************************************************** */

/**
 * @brief Checks if stack is sorted in following(param) order. 
 * 
 * @param stack 
 * @param order 
 * @return true 
 * @return false 
 */
bool	check_is_sorted(t_stack *stack, t_dir order)
{
	if (order == asc_)
		return (check_sorted_asc_order(stack));
	else
		return (check_sorted_desc_order(stack));
}

/* ************************************************************************** */

static bool	check_sorted_asc_order(t_stack *stack)
{
	t_nd	*nd_ptr;

	if (stack->nd_cnt_ < 2)
		return (true);
	nd_ptr = stack->btm_;
	while (nd_ptr->next_ != NULL)
	{
		if (nd_ptr->n_ > nd_ptr->next_->n_)
			return (false);
		nd_ptr = nd_ptr->next_;
	}
	return (true);
}

/* ************************************************************************** */

static bool	check_sorted_desc_order(t_stack *stack)
{
	t_nd	*nd_ptr;

	if (stack->nd_cnt_ < 2)
		return (true);
	nd_ptr = stack->btm_;
	while (nd_ptr->next_ != NULL)
	{
		if (nd_ptr->n_ < nd_ptr->next_->n_)
			return (false);
		nd_ptr = nd_ptr->next_;
	}
	return (true);
}

/* ************************************************************************** */