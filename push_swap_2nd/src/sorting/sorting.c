/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:10:55 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/27 21:07:37 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* ************************************************************************** */

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
	else if (stacks->a_.ch_cnt_ == 2)
		
}