

#include "pipex.h"

void	children(t_pipex pipex, size_t i)
{
	if (!pipex.cmds[i].found)
	{
		close_all_fds(&pipex);
		free_pipex(&pipex);
		exit(EXIT_FAILURE);
		;
	}
	if (i == 0)
		child(pipex, i, pipex.file_fd.infile_fd, pipex.pipes[i][1]);
	else if (i != pipex.size - 1)
		child(pipex, i, pipex.pipes[i - 1][0], pipex.pipes[i][1]);
	else
		child(pipex, i, pipex.pipes[i - 1][0], pipex.file_fd.outfile_fd);
}

void	child(t_pipex pipex, int i, int input, int output)
{
	redirect(pipex, input, output);
	close_all_fds(&pipex);
	if (execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp) == -1)
	{
		free_pipex(&pipex);
		err_msg(NULL);
	}
	exit(EXIT_FAILURE);
}

void	redirect(t_pipex pipex, int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		close_all_fds(&pipex);
		free_pipex(&pipex);
		exit(EXIT_FAILURE);
	}
	close(input);
	if (dup2(output, STDIN_FILENO) == -1)
	{
		close_all_fds(&pipex);
		free_pipex(&pipex);
		exit(EXIT_FAILURE);
	}
	close(output);
}