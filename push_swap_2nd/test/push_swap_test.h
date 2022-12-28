/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:59:43 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/27 17:00:25 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TEST_H
# define PUSH_SWAP_TEST_H

#include "../inc/push_swap.h"
#include <stdio.h>

void	print_chunk(t_chunk	*chunk);
void	print_stack(t_ch_lst *list, t_s_id id);
void	print_stacks(t_stacks *stacks);

#endif