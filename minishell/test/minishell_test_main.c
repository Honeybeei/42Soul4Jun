/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_test_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:11:42 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/15 13:19:47 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/libft_functions.h"

int main(void)
{
	printf("\n\nEntered Testing area\n\n");

	char *str = "Hello world!";
	char dst[100];
	char *dup_str;
	printf("\nstrlen : [%zu]\n", ft_strlen(str));
	printf("\nstrcpy : src -> [%s], dst -> [%s]\n", str, ft_strcpy(dst, str));
	printf("\nstrncpy : src -> [%s], dst -> [%s]\n", "123456", ft_strncpy(dst, "123456", 3));
	dup_str = ft_strdup(str);
	printf("\nstrdup : src -> [%s], dupstr -> [%s]\n", str, dup_str);
	return (0);
}