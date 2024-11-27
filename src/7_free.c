/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:07:41 by snakajim          #+#    #+#             */
/*   Updated: 2024/11/24 22:00:43 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	free_program(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	while (i < pipex->size && pipex->cmds[i].args)
	{
		free_array(pipex->cmds[i].args);
		if (pipex->cmds[i].found)
			free(pipex->cmds[i].path);
		i++;
	}
	free(pipex->cmds);
	if (pipex->paths)
		free_array(pipex->paths);
	if (pipex->file_fd.infile_fd != -1)
		close(pipex->file_fd.infile_fd);
	if (pipex->file_fd.outfile_fd != -1)
		close(pipex->file_fd.outfile_fd);
	if (pipex->child_pids)
		free(pipex->child_pids);
	if (pipex->heredoc)
		unlink(".here_doc"); // TODOこの部分の内容解明
	return (true);
}

bool	free_array(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (false);
	while (array[i])
		free(array[i++]);
	free(array);
	return (true);
}

bool	close_all_fds(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	if (!pipex->pipes)
		return (false);
	while (i < pipex->size && pipex->pipes[i])
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		if (pipex->pipes[i])
			free(pipex->pipes[i]);
		i++;
	}
	free(pipex->pipes);
	if (pipex->file_fd.infile_fd != -1)
		close(pipex->file_fd.infile_fd);
	if (pipex->file_fd.outfile_fd != -1)
		close(pipex->file_fd.outfile_fd);
	return (true);
}
