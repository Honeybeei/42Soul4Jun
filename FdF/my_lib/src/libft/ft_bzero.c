/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:30:16 by seoyoo            #+#    #+#             */
/*   Updated: 2022/08/03 21:38:42 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// Discription
// Writes n(2nd Parameter) zeroed bytes to the string s(1st Parameter). If n is 
// zero, bzero() does nothing.

// 1st Parameter :	address of the first character of the string 
// 2nd Parameter :	number of bytes to be zeroed
// Return values :	Nothing to return.

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
