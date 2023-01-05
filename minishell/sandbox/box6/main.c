#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


//	COMMAND AND COMMAND ARRAY

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

typedef struct s_command
{
	pid_t	pid_;
	char	*cmd_name_;
	char	*cmd_dir_;		// if cmd_dir_ == NULL -> it is built in command
	char	*args_;
	int		fd_r_;
	int		fd_w_;
}	t_cmd;

typedef struct s_command_array
{
	t_cmd	*arr_;
	size_t	cmd_cnt_;
	t_pipe	*pipe_arr_;
}	t_cmd_arr;

#define CMD_CNT 5
#define PIPE_CNT CMD_CNT - 1

void	set_pipes(t_pipe *pipe_arr, size_t pipe_cnt)
{
	// TODO
	// set the pipes. use pipe(). 
	size_t	i;

	pipe_arr = calloc(pipe_cnt, sizeof(t_pipe));
	i = 0;
	while (i < pipe_cnt)
	{
		pipe_arr[i].pipe_id_ = i;
		if (pipe(pipe_arr[i].fd_) != 0)
		{
			// error_management
			printf("ERROR!!!");		// TEST -> must be erased. 
			exit(EXIT_FAILURE);		// TEST -> must be erased. 
		}
		i++;
	}
}


// Testing area for file descriptors management
int main(void)
{
	t_cmd_arr cmd_arr;

	cmd_arr.arr_ = NULL;
	cmd_arr.cmd_cnt_ = CMD_CNT;
	cmd_arr.pipe_arr_ = NULL;

	set_pipes(cmd_arr.pipe_arr_, PIPE_CNT);
	
	// print fd of pipes
	for (size_t i = 0; i < PIPE_CNT; i++)
	{
		printf("PIPE %d Write end : %d\n", cmd_arr.pipe_arr_[i].pipe_id_, cmd_arr.pipe_arr_[i].fd_[P_WRITE_]);
		printf("PIPE %d Write end : %d\n", cmd_arr.pipe_arr_[i].pipe_id_, cmd_arr.pipe_arr_[i].fd_[P_READ_]);
	}
	

}