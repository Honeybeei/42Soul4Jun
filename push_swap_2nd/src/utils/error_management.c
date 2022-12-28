/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:52:56 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/27 13:59:33 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_error_and_exit(void)
{
	ft_putstr_fd(ERR_MSG_, STDERR_FILENO);
	exit(STDERR_FILENO);
}
