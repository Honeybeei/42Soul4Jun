/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:35:42 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/04 13:38:41 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/* ************************************************************************** */

int	ft_putstrnl_fd(const char *str, int fd)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		write(fd, &str[idx], 1);
		idx++;
	}
	write(1, "\n", fd);
	return (idx + 1);
}

/* ************************************************************************** */