/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:26:22 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/09 13:44:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

// readline function returns NULL when EOF enters. -> should be handled at else.

/**
 * @brief Tokenize user input from readline(). This process includes splitting, 
 * variable conversion and deleting actual quotation marks. 
 * 
 * @param lst 
 */
void	tokenize_input(t_tkn_lst *lst)
{
	char	*user_input;

	user_input = readline(PROMPT_STR_);
	if (user_input != NULL)
	{
		split_input_to_tokens(user_input, lst);
		convert_variables(lst);
		convert_quoted_strings(lst);
		free(user_input);
	}
	else
	{
		printf("user input : NULL -> EOF\n");
	}
}

/* ************************************************************************** */

/**
 * @brief Split string by using meta-character as an delimeter. 
 * 
 * @param user_input 
 * @param lst 
 */
void	split_input_to_tokens(char *user_input, t_tkn_lst *lst)
{
	size_t	i;

	i = 0;
	while (user_input[i] != '\0')
	{
		if (is_white_space(user_input[i]) == true)
			i++;
		else if (is_operator(user_input[i]) == true)
			i += push_operator(lst, &user_input[i]);
		else
			i += push_word(lst, &user_input[i]);
	}
}

/* ************************************************************************** */

/**
 * @brief Returns true when c(param1) is a white space character. 
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool	is_white_space(unsigned char c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

/* ************************************************************************** */

/**
 * @brief Returns true when c(param1) is a operational character.
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool	is_operator(unsigned char c)
{
	if (ft_strchr(OPERATIONAL_CHAR_, c) == NULL)
		return (false);
	return (true);
}

/* ************************************************************************** */

/**
 * @brief Returns true when c(param1) is a meta character.
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool	is_meta_char(unsigned char c)
{
	if (is_white_space(c) == true || is_operator(c) == true
		|| ft_strchr(ETC_META_CHAR_, c) != NULL)
		return (true);
	return (false);
}

/* ************************************************************************** */