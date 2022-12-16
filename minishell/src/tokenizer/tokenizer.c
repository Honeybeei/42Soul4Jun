/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:28:50 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/16 15:55:29 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tokenizer.h"

/* ************************************************************************** */

/**
 * @brief Factorize string in to tokens. Factorized tokens will be added to
 * token list which will be returned.
 * 
 * @param str 
 * @param delimiter_str 
 * @return t_tkn_lst 
 */
t_tkn_lst	token_list_generator(const char *str, const char *delimiter_str)
{
	t_tkn_lst	*token_list;
	char		**delimiter_arr;

	delimiter_arr = init_delimiter_arr(delimiter_str, META_DELIMITER);
	token_list = init_token_list();
	while (true)
	{
		

	}

}

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */