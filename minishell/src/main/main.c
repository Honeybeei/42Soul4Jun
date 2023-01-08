/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:28:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 21:28:34 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

#include <stdio.h>	//	for test

/* ************************************************************************** */

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("No arguments allowed for minishell...", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	start_shell(envp);
	while (true)
	{
		tokenize_input(&g_ptrs.tkn_lst_); // in progress
		// if (parse_tokens() == fail_)
		// 	error_management();
		// else
		// 	execute_commands();
		clear_loop();
	}
	return (0);
}

/* ************************************************************************** */