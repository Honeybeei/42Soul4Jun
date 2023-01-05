/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:08:26 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/02 13:53:45 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Same as calloc() but it will terminate current process with printing 
 * error message when malloc fail. 
 * 
 * @note This should be the only function for malloc in this project!!
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*calloc_safe(size_t count, size_t size)
{
	unsigned char	*dst;
	size_t			i;

	dst = NULL;
	dst = (void *)malloc(count * size);
	if (dst == NULL)
		termination_ptcl(&g_ptrs);
	i = 0;
	while (i < count * size)
	{
		dst[i] = (unsigned char)0;
		i++;
	}
	return (dst);
}

/* ************************************************************************** */