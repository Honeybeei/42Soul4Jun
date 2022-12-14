/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:49:57 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/14 14:56:38 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_input	*get_input_from_user(void)
{
	t_input	*user_input;
	char	*readline_result;

	readline_result = readline(PROMPT_STR);
	if (readline_result == NULL)
		return (NULL);
	if (readline_result != NULL && readline_result[0] != '\0') 
		add_history(readline_result);
	
	// JUST FOR TEST : start
	printf("User typed -> [%s]\n", readline_result);
	user_input = init_t_input();
	// JUST FOR TEST : end
	// TODO : split string into command and return splitted string and number of strings. (should I have to make it to return t_input datatype?)
	
	free(readline_result);
	return (user_input);
}

// TOKENIZE -> parse TOKENS maybe?
t_input	*split_readline_result(char *readline_result, char *dividers)
{
	/**
	 * Cases
	 * 1. normal string
	 * 2. div at the front
	 * 3. only divs -> t_input.str_cnt_ = 0, str_arr = NULL;
	 * 4. single char
	 * 5. no char
	 * 6. 
	 *  TODO : need to read 
	 */
	char	*char_ptr;

	char_ptr = readline_result;
	while (true)
	{
		
	}
	

}