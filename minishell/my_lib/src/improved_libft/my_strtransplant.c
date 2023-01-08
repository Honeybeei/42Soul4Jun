/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtransplant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:57:17 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 21:55:59 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/improved_libft.h"

/* ************************************************************************** */

/**
 * @brief Transplant string to string. From start to end (index of target) will 
 * be replaced with donor(last parameter). Target(param1) will not be freed.
 * 
 * @param target 
 * @param start 
 * @param end 
 * @param donor 
 * @return char* 
 */
char	*my_strtransplant(const char *target, size_t start, size_t end,
		const char *donor)
{
	char	*str_arr[3];
	char	*result;

	if (target == NULL)
		return (NULL);
	if (donor == NULL)
		str_arr[1] = my_strndup("", 0);
	else
		str_arr[1] = my_strndup(donor, ft_strlen(donor));
	str_arr[0] = my_strndup(target, start);
	str_arr[2] = my_strndup(target + end + 1, ft_strlen(target) - end - 1);
	result = my_strarrjoin(str_arr, 3);
	free(str_arr[0]);
	free(str_arr[1]);
	free(str_arr[2]);
	return (result);
}

/* ************************************************************************** */