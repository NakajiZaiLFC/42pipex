/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:40:03 by snakajim          #+#    #+#             */
/*   Updated: 2024/11/24 10:35:01 by snakajim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERR_NUM_ARG "Error: Wrong number of arguments\n"
# define ERR_INCOMP_ARG "Error: Not enough arguments\n"
# define ERR_IN "Error: infile undefined\n"
# define ERR_OUT "Error: outfile undefined\n"

# include "get_next_line.h"
# include <errno.h>
# include <error.h>
# include <stdbool.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char		**args;
	char		*path;
	bool		found;
}				t_cmd;

typedef struct s_file_fd
{
	int			infile_fd;
	int			outfile_fd;
}				t_file_fd;

typedef struct s_pipex
{
	t_cmd		*cmds;
	t_file_fd	file_fd;
	int			size;
	int			**pipes;
	char		**paths;
	char		**argv;
	char		**envp;
	int			*child_pids;
	bool		heredoc;
	int			exitcode;
}				t_pipex;

#endif