/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:51:11 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/26 21:41:34 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_stack(t_stack *stack, t_dir shift_dir);
static void	shift_up(t_stack *stack);
static void	shift_down(t_stack *stack);

/* ************************************************************************** */

/**
 * @brief Rotate stack. Actually shift stack will be better. 
 * 
 * @param stacks 
 * @param target_stack 
 * @param shift_dir 
 */
void	op_rotate(t_stacks *stacks, t_s_id target_stack, t_dir shift_dir)
{
	if (target_stack == a_)
	{
		rotate_stack(stacks->a_, shift_dir);
		if (shift_dir == up_)
			ft_putstr_fd("ra\n", STDOUT_FILENO);
		else
			ft_putstr_fd("rra\n", STDOUT_FILENO);
	}
	else if (target_stack == b_)
	{
		rotate_stack(stacks->b_, shift_dir);
		if (shift_dir == up_)
			ft_putstr_fd("rb\n", STDOUT_FILENO);
		else
			ft_putstr_fd("rrb\n", STDOUT_FILENO);
	}
	else
	{
		rotate_stack(stacks->a_, shift_dir);
		rotate_stack(stacks->b_, shift_dir);
		if (shift_dir == up_)
			ft_putstr_fd("rr\n", STDOUT_FILENO);
		else
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
	}
}

/* ************************************************************************** */

static void	rotate_stack(t_stack *stack, t_dir shift_dir)
{
	if (shift_dir == up_)
		shift_up(stack);
	else
		shift_down(stack);
}

/* ************************************************************************** */

static void	shift_up(t_stack *stack)
{
	t_nd	*node_to_move;

	node_to_move = pick_t_nd(stack, top_);
	push_t_nd(stack, node_to_move, btm_);
}

/* ************************************************************************** */

static void	shift_down(t_stack *stack)
{
	t_nd	*node_to_move;

	node_to_move = pick_t_nd(stack, btm_);
	push_t_nd(stack, node_to_move, top_);
}

/* ************************************************************************** */
