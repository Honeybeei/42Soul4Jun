/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:28:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 15:17:57 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("No arguments allowed for minishell...", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	start_shell(envp);	// print_banner, init signals, init ptrs
	while (true)
	{
		// g_ptrs.user_input_ = get_user_input();
		// tokenize_input()
		// parse_tokens()
		// if valid -> execute commands
		//	else -> error management
	}
	return (0);
}

/* ************************************************************************** */