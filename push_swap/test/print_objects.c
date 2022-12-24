/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:25:53 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/24 18:34:13 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_test.h"

void print_node(t_nd *node)
{
	printf("Node address : %p\n", node);
	printf("Node value   : %d\n", node->n_);
	printf("Next node    : %p\n", node->next_);
	printf("Prev node    : %p\n", node->prev_);
}

void print_stack(t_stack *stack)
{
	t_nd    *node_ptr;

	printf("STACK CNT : %3zu >> BTM | ", stack->nd_cnt_);
	node_ptr = stack->btm_;
	while (node_ptr != NULL)
	{
		printf("[%d]", node_ptr->n_);
		node_ptr = node_ptr->next_;
	}
	printf("  | TOP\n");
}

void print_stacks(t_stacks *stacks)
{
	print_stack(stacks->a_);
	print_stack(stacks->b_);
	ft_putchar_fd('\n', 1);
}