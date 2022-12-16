/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:26:33 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/15 20:04:19 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FUNCTIONS_H
# define LIBFT_FUNCTIONS_H

# include <stddef.h>	// size_t
# include <stdbool.h>	// true, false
# include <stdlib.h>	// malloc(), free()

size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dst, const char *src, size_t cpy_len);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *str);
int     ft_strncmp(const char *str1, const char *str2, size_t cmp_len);

#endif