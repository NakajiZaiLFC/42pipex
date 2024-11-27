/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:34:37 by snakajim          #+#    #+#             */
/*   Updated: 2024/11/24 20:42:40 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_putstr_fd(ERR_NUM_ARG, 2), EXIT_FAILURE);
	if (!pipex_init(&pipex, argc, argv, envp))
		return (free_program(&pipex), err_msg(NULL), EXIT_FAILURE);
	if (!parse_input(&pipex))
		/* TODO　なぜここだけerr_msg関数を通らないのか? */
		return ((free_program(&pipex), EXIT_FAILURE));
	if (!create_pipe(&pipex))
		return (free_program(&pipex), err_msg(NULL), EXIT_FAILURE);
	if (!execute(&pipex)) // TODO
		return (free_prigram(&pipex), err_msg(NULL), pipex.exitcode);
	free_pipex(&pipex);
	return (pipex.exitcode);
}

bool	pipex_init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->cmds = NULL;
	pipex->file_fd = (t_file_fd){-1, -1};
	pipex->size = argc - 3;
	pipex->pipes = NULL;
	pipex->paths = NULL;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->child_pids = NULL;
	pipex->heredoc = false;
	pipex->exitcode = EXIT_SUCCESS;
	if (!cmds_init(pipex))
		return (false);
	return (true);
}

bool	cmds_init(t_pipex *pipex)
{
	size_t	i;

	i = 0;
	pipex->cmds = malloc(pipex->size * sizeof(t_cmd));
	if (!pipex->cmds)
		return (false);
	while (i < pipex->size)
		pipex->cmds[i++] = (t_cmd){NULL, NULL, false};
	return (true);
}
