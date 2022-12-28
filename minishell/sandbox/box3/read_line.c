/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:47:13 by seoyoo            #+#    #+#             */
/*   Updated: 2022/12/20 20:32:36 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	execute_child_process(void)
{
	printf("\n In child process. Counting start\n");
	for (int i = 0; i < 10; i++)
	{
		printf("C %d\n", i);
		usleep(100000);
	}
	printf("\n");
	return (2);
}

int execute_parent_process(void)
{
	printf("\n In parent process. Counting start\n");
	for (int i = 0; i < 10; i++)
	{
		printf("P %d\n", i);
		usleep(100000);
	}
	printf("\n");
	return (0);
}

int main(void)
{
	int pid = fork();
	int return_val = 0;

	if (pid != 0)  // parent process
	{
		wait(&return_val);
		execute_parent_process();
		printf("child process return val : [%d]\n", return_val);
		return 0;
	}
	else  // child process
		return (execute_child_process());
}

