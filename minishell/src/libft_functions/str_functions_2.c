/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:26:04 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/01 14:59:58 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Print str(param1) to fd(param2)
 * 
 * @param str 
 * @param fd 
 */
void	ft_putstr_fd(char *str, int fd)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	write(fd, str, str_len);
}

/* ************************************************************************** */

/**
 * @brief If s1 and s2 are identical strings('\0' terminating), it will return 0
 * . If not, it will return non 0 value. 
 * 
 * @param s1 
 * @param s2 
 * @return size_t 
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1_str_len;
	size_t	s2_str_len;
	size_t	idx;

	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL || s2 == NULL)
		return (1);
	else
	{
		s1_str_len = ft_strlen(s1);
		s2_str_len = ft_strlen(s2);
		if (s1_str_len != s2_str_len)
			return (1);
		idx = 0;
		while (s1[idx] != '\0')
		{
			if (s1[idx] != s2[idx])
				return (s1[idx] - s2[idx]);
			else
				idx++;
		}
	}
	return (0);	// TODO : test this!!
}


/* ************************************************************************** */