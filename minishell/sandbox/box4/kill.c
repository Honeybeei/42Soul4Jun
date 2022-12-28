#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define ONE_SEC 1000 * 1000

// timer using parent process and child process. 
int main(void)
{
	int pid;
	int	time;

	pid = fork();
	if (pid < 0)
		return EXIT_FAILURE;
	else if (pid == 0)  // child process
	{
		for (int i = 0; true; i++)
		{
			printf("Child process counting : %d\n", i);
			usleep(ONE_SEC / 10);
		}
	}
	else  // parent process
	{
		kill(pid, SIGSTOP);
		printf("Type : ");
		scanf("%d", &time);
		kill(pid, SIGCONT);
		usleep(ONE_SEC * time);
		kill(pid, SIGKILL);
	}
	return EXIT_SUCCESS;
}