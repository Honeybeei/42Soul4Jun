/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:25:53 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/28 14:49:38 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_test.h"

/* ************************************************************************** */

void	print_chunk(t_chunk	*chunk)
{
	t_nd	*nd_ptr;

	printf("[ ");
	nd_ptr = chunk->head_;
	while (nd_ptr != NULL)
	{
		printf("%d", nd_ptr->n_);
		nd_ptr = nd_ptr->next_;
		if (nd_ptr != NULL)
			printf(", ");
	}
	printf(" ]");
}

/* ************************************************************************** */

void	print_stack(t_ch_lst *list, t_s_id id)
{
	t_chunk	*chunk_ptr;

	if (id == a_)
		printf("STACK A [chunk cnt : %3zu]", list->ch_cnt_);
	else
		printf("STACK A [chunk cnt : %3zu]", list->ch_cnt_);
	printf(" BTM | ");
	chunk_ptr = list->head_;
	while (chunk_ptr != NULL)
	{
		print_chunk(chunk_ptr);
		chunk_ptr = chunk_ptr->next_;
		if (chunk_ptr != NULL)
			printf(" - ");
	}
	printf(" | TOP\n");
}

/* ************************************************************************** */

void	print_stacks(t_stacks *stacks)
{
	printf("\n");
	print_stack(&stacks->a_, a_);
	print_stack(&stacks->b_, b_);
	printf("\n");
}

/* ************************************************************************** */