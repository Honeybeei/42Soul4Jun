/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:14 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 14:44:37 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Set t_errno(Customized errno for current project).
 * 
 * @param error_number 
 */
void	set_t_errno(t_errno error_number)
{
	g_ptrs.errno_ = error_number;
}

/* ************************************************************************** */

/**
 * @brief Print error in STDERR according to errno. Reset errno if reset
 * (param 2) is true. 
 * 
 * @param errno 
 * @param reset_errno 
 */
void	print_error(t_errno error_number)
{
	char	*error_message;

	if (error_number == errno_tokenize_no_matching_operator_)
		error_message = "ERROR : tokenize : No matching operator.\n";
	else
		error_message = "There are no errors......\n";
	ft_putstr_fd(error_message, STDERR_FILENO);
}

/* ************************************************************************** */

/**
 * @brief When error occurs, this function will be immediately called. If 
 * reset_errno is true, it g_ptrs->t_errno will be set to errno_no_errors_.
 * 
 * @param error_number 
 * @param reset_errno 
 */
void	error_handler(t_errno error_number, bool reset_errno)
{
	set_t_errno(error_number);
	print_error(error_number);
	if (reset_errno == true)
		set_t_errno(errno_no_errors_);
}

/* ************************************************************************** */