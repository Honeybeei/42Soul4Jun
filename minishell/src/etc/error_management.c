/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:21:48 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/02 13:52:55 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Print error message according to errno(param1)
 * 
 * @param errno 
 */
void	print_error_msg(t_errno errno)
{
	char	*err_msg;

	if (errno == err_malloc_fail_)
		err_msg = "FATAL ERROR : Malloc fail! Terminating process.\n";
	else
		err_msg = "Undefined error occurred......";
	ft_putstr_fd(err_msg, STDERR_FILENO);
}

/* ************************************************************************** */

void	manage_error_cases(void)
{
	// TODO
}

/* ************************************************************************** */