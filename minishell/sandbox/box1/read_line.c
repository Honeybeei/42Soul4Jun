/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:47:13 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/13 14:18:24 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 *  Just checking how does External functions work. In this file, we will check
 *  readline(), rl_clear_history(), rl_on_new_line(), rl_replace_line(),
 *  rl_redisplay(), add_history()
 */
int main(void)
{
	char    *read_line_result;
	
	while (true)
	{
		read_line_result = readline("Type : ");
		if (read_line_result == NULL)
			break ;
		printf("User typed -> [%s]\n", read_line_result);
		// from here : this code prevents to save empty line in history. 
		if (read_line_result != NULL && read_line_result[0] != '\0') 
			add_history(read_line_result);
		// end :

		rl_on_new_line();
		free(read_line_result); // must free this malloced string from readline()
	}
	
	return 0; 
}