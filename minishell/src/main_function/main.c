/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:28:55 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/13 16:00:06 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


int	main(void)
{
	t_input	*user_input;

	enter_shell();
	while (true)
	{
		user_input = get_input_from_user();
		// test
		if (user_input != NULL)
			printf("user input is not null\n");
		else
			printf("user input is null\n");
		// test

		// TODO : Tokenize user_input(t_input) and terminate user_input. 

		// TODO : Execute Tokenized command. 
	}
	return (0);
}