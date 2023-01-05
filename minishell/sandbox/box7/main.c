#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef enum e_pipe_end
{
	P_WRITE_ = 1,
	P_READ_ = 0
}	t_p_end;

typedef struct s_pipe
{
	int fd_[2];
	int	pipe_id_;
}	t_pipe;



int main(void)
{
	t_pipe	*pipe_arr;
	
	pipe_arr = malloc(sizeof(t_pipe) * 3);
	pipe_arr[0].fd_[P_WRITE_] = 1;
	pipe_arr[0].fd_[P_READ_] = 2;
	pipe_arr[1].fd_[P_WRITE_] = 3;
	pipe_arr[1].fd_[P_READ_] = 4;
	pipe_arr[2].fd_[P_WRITE_] = 5;
	pipe_arr[2].fd_[P_READ_] = 6;
	for (int i = 0; i < 3; i++)
	{
		printf("[%d], [%d]\n", pipe_arr[i].fd_[P_WRITE_], pipe_arr[i].fd_[P_READ_]);
	}
	


}