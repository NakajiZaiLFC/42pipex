

#include "pipex.h"

bool	create_pipe(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	pipex->pipes = malloc((pipex->size) * sizeof(int *));
	if (!pipex->pipes)
		return (false);
	while (i < pipex->size)
	{
		pipex->pipes[i] = malloc(2 * sizeof(int));
		if (!pipex->pipes[i])
			return (false);
		if (pipe(pipex->pipes[i]) == -1)
			return (false);
		i++;
	}
	return (true);
}

bool	execute(t_pipex *pipex)
{
	int		pid;
	size_t	i;

	i = 0;
	if (!allocate_pids(pipex))
		return (false);
	while (i < pipex->size)
	{
		pid = fork();
		if (pid == 0)
			children(*pipex, i);
		else if (pid > 0)
			pipex->child_pids[i] = pid;
		else
			return (close_all_fds(pipex), false);
		i++;
	}
	close_all_fds(pipex);
	wait_pids(pipex);
	return (true);
}

bool	allocate_pids(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	pipex->child_pids = malloc(pipex->size * sizeof(int));
	if (!pipex->child_pids)
		return (false);
	while (i < pipex->size)
		pipex->child_pids[i++] = -1;
	return (true);
}

bool	wait_pids(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (i < pipex->size && pipex->child_pids[i] > 0)
		waitpid(pipex->child_pids[i++], NULL, 0);
	if (pipex->file_fd.infile_fd == -1)
		pipex->exitcode = 1;
	else if (!pipex->cmds[i - 1].found)
		pipex->exitcode = 127;
	else
		pipex->exitcode = 0;
	return (true);
}
