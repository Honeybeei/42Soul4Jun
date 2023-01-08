/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:14 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 16:12:00 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Set t_errno(Customized errno for current project).
 * 
 * @param errno 
 */
void	set_t_errno(t_errno errno)
{
	g_ptrs.errno_ = errno;
}

/* ************************************************************************** */