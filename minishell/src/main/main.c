/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:28:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/09 20:50:46 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
		tokenize_input(&g_ptrs.tkn_lst_);
		print_token_list(&g_ptrs.tkn_lst_);  // TEST
		// parse_token_list(&g_ptrs.tkn_lst_, &g_ptrs.cmd_lst_);
		// if (parse_tokens() == fail_)
		// 	error_management();
		// else
		// 	execute_commands();
		clear_loop();
	}
	return (0);
}

/* ************************************************************************** */