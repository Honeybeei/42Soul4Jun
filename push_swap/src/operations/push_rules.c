/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:36:52 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/24 18:48:32 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ************************************************************************** */

/**
 * @brief Pick top node from the opposite stack of target_stack and push it to 
 * the top of target_stack and print name of the rule.
 * 
 * @param stacks 
 * @param target_stack 
 */
void	op_push(t_stacks *stacks, t_s_id target_stack)
{
	t_nd	*node_to_move;

	if (target_stack == a_ && stacks->b_->nd_cnt_ > 0)
	{
		node_to_move = pick_t_nd(stacks->b_, top_);
		push_t_nd(stacks->a_, node_to_move, top_);
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
	else if (target_stack == b_ && stacks->a_->nd_cnt_ > 0)
	{
		node_to_move = pick_t_nd(stacks->a_, top_);
		push_t_nd(stacks->b_, node_to_move, top_);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
}

/* ************************************************************************** */