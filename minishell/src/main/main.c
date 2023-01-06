/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:28:55 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 14:56:15 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		ft_putstr_fd("No arguments allowed for minishell...", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	(void)argv;
	
	// start_shell();	// print_banner, init signals, init ptrs
}

/* ************************************************************************** */