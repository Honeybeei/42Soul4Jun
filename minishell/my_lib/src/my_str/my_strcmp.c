/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:39:23 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 16:52:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/my_str.h"

/* ************************************************************************** */

int	my_strcmp(const char *str1, const char *str2)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 == len2)
		return (ft_strncmp(str1, str2, len1));
	else
		return ((int)(len1 - len2));
}

/* ************************************************************************** */