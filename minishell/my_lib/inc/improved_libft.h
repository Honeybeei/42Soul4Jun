/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_libft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:56:53 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/08 21:55:25 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPROVED_LIBFT_H
# define IMPROVED_LIBFT_H

/* ************************************************************************** */

# include "libft.h"
# include <stdio.h> //  perror()

/* ************************************************************************** */

// EXTERNAL FUNCTION SWITCH

# define CAN_USE_EXIT_F_ 1
# define CAN_USE_PERROR_F_ 1

/* ************************************************************************** */

void	*my_calloc(size_t count, size_t size);
void	*my_malloc(size_t size);
char	*my_strarrjoin(char **str_arr, size_t str_cnt);
int		my_strcmp(const char *str1, const char *str2);
char	*my_strndup(const char *src, size_t len);
char	*my_strtransplant(const char *target, size_t start, size_t end,
			const char *donor);

/* ************************************************************************** */

#endif