
#include "pipex.h"

void	err_msg(char *file)
{
	char	*msg;

	ft_putstr_fd("pipex: ", 2);
	if (file)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
	}
	msg = ft_strdup(strerror(errno));
	if (msg)
		ft_putstr_fd(msg, 2);
	else
		ft_putstr_fd("error allocating err_msg", 2);
	ft_putstr_fd("\n", 2);
	if (msg)
		free(msg);
}

void	cmd_not_found(t_pipex *pipex, size_t i)
{
	ft_putstr_fd(pipex->cmds[i].args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	pipex->cmds[i].found = false;
}