/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:25:15 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/23 21:15:28 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_test.h"

int main(void)
{
    t_stack *stack;

    printf("TESTING....\n");
    stack = init_t_stack();
    for (int i = 0; i < 20; i = i + 2)
    {
        push_t_nd(stack, init_t_nd(i), top_);
    }
    print_stack(stack);
    terminate_t_nd(pick_t_nd(stack, btm_));
    print_stack(stack);
    terminate_t_nd(pick_t_nd(stack, top_));
    print_stack(stack);
    push_t_nd(stack, pick_t_nd(stack, btm_), top_);
    print_stack(stack);
    terminate_t_stack(stack);
}