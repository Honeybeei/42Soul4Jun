/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:26:38 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/28 17:06:32 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static t_bool	pick_and_push(t_stacks *stacks, t_s_id dst_stack);

/* ************************************************************************** */

static t_bool	pick_and_push(t_stacks *stacks, t_s_id dst_stack)
{
	t_nd	*node_to_move;

	if (stacks == NULL
		|| get_chunk(stacks, a_, top_) == NULL
		|| get_chunk(stacks, b_, top_) == NULL
		|| get_chunk(stacks, dst_stack * -1, top_)->nd_cnt_ < 1)
		return (fail_);
	node_to_move = pick_node(get_chunk(stacks, dst_stack * -1, top_));
	push_node(node_to_move, get_chunk(stacks, dst_stack, top_), top_);
	return (success_);
}

/* ************************************************************************** */

/**
 * @brief Push a node to dst_stack from src(opposite stack of dst_stack).
 * This function only works when there are one or more node at src_stack's top 
 * chunk. 
 * 
 * @param stacks 
 * @param dst_stack 
 * @return t_bool 
 */
void	op_push(t_stacks *stacks, t_s_id dst_stack)
{
	if (pick_and_push(stacks, dst_stack) == fail_)
		ft_putstr_fd("ERROR : op_push fail.....\n", STDERR_FILENO);
	if (dst_stack == a_)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	else
		ft_putstr_fd("pb\n", STDOUT_FILENO);
}

/* ************************************************************************** */