/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:52:56 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/28 17:16:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_error_and_exit(void)
{
	ft_putstr_fd(ERR_MSG_, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	operation_fail_protocol(t_stacks *stacks, t_op_num op_num)
{
	char	*err_msg;

	if (op_num == swap_)
		err_msg = "Swap fail......";
	else if (op_num == push_)
		err_msg = "Push fail......";
	else if (op_num == rotate_)
		err_msg = "Rotate fail......";
	else if (op_num == rrotate_)
		err_msg = "Rev Rotate fail......";
	ft_putstr_fd(err_msg, STDERR_FILENO);
	push_swap_termination(stacks);
	exit(EXIT_FAILURE);
}
