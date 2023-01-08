/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strarrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:10:25 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 19:57:20 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

/* ************************************************************************** */

/**
 * @brief Join array of strings in to a single string. If str_cnt(param2) is 
 * greater than the number of strings in str_arr, it will join all strings in 
 * str_arr and returns it. 
 * 
 * @param str_arr 
 * @param str_cnt 
 * @return char* 
 */
char	*my_strarrjoin(char **str_arr, size_t str_cnt)
{
	size_t	result_str_len;
	size_t	i;
	size_t	j;
	char	*result;
	char	*char_ptr;

	result_str_len = 0;
	i = 0;
	while (str_arr[i] != NULL && i < str_cnt)
		result_str_len += ft_strlen(str_arr[i++]);
	if (i < str_cnt)
		str_cnt = i;
	result = my_calloc(result_str_len + 1, sizeof(char));
	i = 0;
	j = 0;
	while (i < str_cnt)
	{
		char_ptr = str_arr[i];
		while (*char_ptr != '\0')
			result[j++] = *char_ptr++;
		i++;
	}
	return (result);
}
/* ************************************************************************** */