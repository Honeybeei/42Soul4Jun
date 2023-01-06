/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:44:32 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/06 16:11:10 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

static void	malloc_fail_protocol(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */

/**
 * @brief Safe version malloc. If malloc fails, malloc_fail_protocol will be 
 * executed. 
 * 
 * @param size 
 * @return void* 
 */
void	*malloc_safe(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		malloc_fail_protocol();
	return (ret);
}

/* ************************************************************************** */

/**
 * @brief Safe version calloc. If calloc fails, malloc_fail_protocol will be 
 * executed. 
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*calloc_safe(size_t count, size_t size)
{
	void	*ret;

	ret = malloc_safe(count * size);
	ft_memset(ret, 0, count * size);
	return (ret);
}

/* ************************************************************************** */