/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:26:04 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/30 13:28:12 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* ************************************************************************** */

/**
 * @brief Returns the length of the string. 
 * 
 * @param str 
 * @return size_t 
 */
size_t	ft_strlen(const char *str)
{
	size_t idx;

	idx = 0;
	while (str[idx] != '\0')
		idx++;
	return (idx);
}

/* ************************************************************************** */

/**
 * @brief Copies cpy_len bytes from src to dst.
 * WARNING! This function copies even if cpy_len is bigger than str_len of src. 
 * 
 * @param dst 
 * @param src 
 * @return char* 
 */
char	*ft_strncpy(char *dst, const char *src, size_t cpy_len)
{
	size_t	i;

	i = 0;
	while (i < cpy_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* ************************************************************************** */

/**
 * @brief Copies string from src to dst. 
 * 
 * @param dst 
 * @param src 
 * @return char* 
 */
char	*ft_strcpy(char *dst, const char *src)
{
	return (ft_strncpy(dst, src, ft_strlen(src)));
}

/* ************************************************************************** */

/**
 * @brief Duplicates string
 * 
 * @param str 
 * @return char* 
 */
char	*ft_strdup(const char *str)
{
	char	*dup_str;

	dup_str = calloc_safe(ft_strlen(str) + 1, sizeof(char));
	return (ft_strcpy(dup_str, str));
}

/* ************************************************************************** */

/**
 * @brief Compare str1 and str2 for cmp_len bytes. Returns 0 when 
 * 
 * @param str1 
 * @param str2 
 * @param cmp_len 
 * @return int 
 */
int	ft_strncmp(const char *str1, const char *str2, size_t cmp_len)
{
	size_t	i;

	i = 0;
	while (i < cmp_len)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */