/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:07:47 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/26 21:43:31 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap_top_two_node(t_stack *stack);

/* ************************************************************************** */

/**
 * @brief Swap top two node from target_stack and print name of the rule.
 * 
 * @param stacks 
 * @param target_stack 
 */
void	op_swap(t_stacks *stacks, t_s_id target_stack)
{
	if (target_stack == a_ && stacks->a_->nd_cnt_ > 1)
	{
		swap_top_two_node(stacks->a_);
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	}
	else if (target_stack == b_ && stacks->b_->nd_cnt_ > 1)
	{
		swap_top_two_node(stacks->b_);
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	}
	else if (target_stack == both_ && stacks->a_->nd_cnt_ > 1
		&& stacks->b_->nd_cnt_ > 1)
	{
		swap_top_two_node(stacks->a_);
		swap_top_two_node(stacks->b_);
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	}
}

/* ************************************************************************** */

// WARNING!! Only use this when there is more than a single node in the stack
static void	swap_top_two_node(t_stack *stack)
{
	t_nd	*first_nd;
	t_nd	*second_nd;

	first_nd = pick_t_nd(stack, top_);
	second_nd = pick_t_nd(stack, top_);
	push_t_nd(stack, first_nd, top_);
	push_t_nd(stack, second_nd, top_);
}

/* ************************************************************************** */