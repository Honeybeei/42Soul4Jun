/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_management_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:16:43 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/24 20:18:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*get_stack(t_stacks *stacks, t_s_id stack_id)
{
	if (stack_id == a_)
		return (stacks->a_);
	else if (stack_id == b_)
		return (stacks->b_);
	else
		return (NULL);
}