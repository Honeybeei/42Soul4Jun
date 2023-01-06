/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:52:37 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 11:09:11 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* ************************************************************************** */

/**
 * @brief Outputs the string s(1st Parameter) to the given file descriptor.
 * 
 * @param s 
 * @param fd 
 */
void	ft_putstr_fd(char *s, int fd)
{
	size_t	str_len;

	str_len = ft_strlen(s);
	write(fd, s, str_len);
}

/* ************************************************************************** */