/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_management_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:23:19 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/26 22:31:40 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_chunk	*set_t_chunk(t_chunk *chunk, t_nd *head, t_nd *tail)
{
	t_nd	*nd_ptr;

	if (chunk == NULL || head == NULL || tail == NULL)
		return (NULL);
	chunk->btm_ = head;
	chunk->top_ = tail;
	chunk->nd_cnt_ = 0;
	nd_ptr = head;
	while (nd_ptr != tail)
	{
		chunk->nd_cnt_++;
		nd_ptr = nd_ptr->next_;
		if (nd_ptr == NULL)
			
	}
	
}