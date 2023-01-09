/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:47:13 by seoyoo            #+#    #+#             */
/*   Updated: 2023/01/09 21:03:51 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	(void)argc;
	int i;
	i = 0;
	while (argv[i] != NULL)
	{
		printf("%d : %s\n", i, argv[i]);
		i++;
	}
	char *temp = NULL;
	free(temp);
		
	return 0; 
}