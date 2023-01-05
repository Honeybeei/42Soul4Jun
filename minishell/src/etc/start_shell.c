/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:53:14 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/30 14:34:56 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_signal(int signo)
{
	if (signo == SIGINT)
	{

	}
	else if (signo == SIGQUIT)
	{
		
	}
}

void	init_sig_handler(void)
{
	signal(SIGINT, (void *)handle_signal);
	signal(SIGQUIT, (void *)handle_signal);
}

void	start_shell(void)
{
	printf("%s", ENTRANCE_ASCII);
	init_sig_handler();
	// TODO : signal handler!!
}
