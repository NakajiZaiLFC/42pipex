/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:49:52 by snakajim          #+#    #+#             */
/*   Updated: 2024/11/24 19:37:25 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	parse_input(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	find_path(pipex);
	if (pipex->heredoc)
		open_heredoc(pipex);
	else
		open_file(pipex);
	while (i < pipex->size)
	{
		pipex->cmds[i].found = false;
		pipex->cmds[i].args = ft_split(pipex->argv[i + 2 + pipex->heredoc],
				' ');
		if (!pipex->cmds[i].args)
			return (false);
		if (!(i == 0 && pipex->file_fd.infile_fd == -1) && !(i == pipex->size
				- 1 && pipex->file_fd.outfile_fd == -1))
			find_command(pipex, i);
		i++;
	}
	return (true);
}

void	find_path(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	if (!pipex->envp)
		return ;
	while (pipex->envp[i] && ft_strncmp(pipex->envp[i], "PATH", 4) != 0)
		i++;
	if (pipex->envp[i] && ft_strncmp(pipex->envp[i], "PATH", 4) == 0)
		pipex->paths = ft_split(pipex->envp[i] + 5, ':');
}

void	open_file(t_pipex *pipex)
{
	pipex->file_fd.infile_fd = open(pipex->argv[1], O_RDONLY);
	if (pipex->file_fd.infile_fd == -1)
	{
		if (errno == ENONET)
			err_msg(pipex->argv[1]);
		else if (errno == EACCES)
			err_msg(pipex->argv[1]);
		else
			ft_putstr_fd(ERR_IN, 2);
		exit(EXIT_FAILURE);
	}
	pipex->file_fd.outfile_fd = open(pipex->argv[pipex->size + 2],
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->file_fd.outfile_fd == -1)
	{
		if (errno == EACCES)
			err_msg(pipex->argv[1]);
		else
			ft_putstr_fd(ERR_IN, 2);
		close(pipex->file_fd.infile_fd);
		exit(EXIT_FAILURE);
	}
}

void	find_command(t_pipex *pipex, size_t i)
{
	char	*command;
	size_t	j;

	j = 0;
	if (pipex->cmds[i].args[0] && is_command(pipex,
			ft_strdup(pipex->cmds[i].args[0]), i))
		return ;
	if (!pipex->paths)
		return (cmd_not_found(pipex, i));
	while (pipex->paths[j])
	{
		command = ft_strjoin(pipex->paths[j], "/", pipex->cmds[i].args[0]);
		if (is_command(pipex, command, i))
			break ;
		if (!pipex->paths[++j])
			cmd_not_found(pipex, i);
	}
}

bool	is_command(t_pipex *pipex, char *command, size_t i)
{
	int	fd;

	fd = 0;
	if (!command)
		return (false);
	if (ft_strncmp(command, "/", 1) == 0)
	{
		fd = open(command, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			pipex->cmds[i].path = ft_strdup(command);
			if (!pipex->cmds[i].path)
			{
				free(command);
				return (false);
			}
			free(command);
			pipex->cmds[i].found = true;
			return (true);
		}
	}
	free(command);
	return (false);
}
