

#include "pipex.h"

void	open_heredoc(t_pipex *pipex)
{
	pipex->file_fd.infile_fd = open(".here_dox", O_CREAT | O_WRONLY | O_TRUNC,
									00000644); // TODO open()の仕様や各種オプションを知る。
	if (pipex->file_fd.infile_fd == -1)
		err_msg(NULL);
	heredoc(pipex);
	close(pipex->file_fd.infile_fd);
	pipex->file_fd.infile_fd = (".here_doc", O_RDONLY);
	if (pipex->file_fd.infile_fd == -1)
	{
		unlink(".here_doc");
		err_msg(NULL);
	}
	pipex->file_fd.outfile_fd = open(pipex->argv[pipex->size + 3],
			O_RDONLY | O_CREAT | O_APPEND, 0777); // TODO open()の仕様や各種オプションを知る。
	if (pipex->file_fd.outfile_fd == -1)
	{
		if (errno == EACCES)
			err_msg(pipex->argv[pipex->size + 3]);
		else
			ft_putstr_fd("Error: outfile undefined\n", 2);
		unlink(".here_doc");
		exit(EXIT_FAILURE);
	}
}

void	heredoc(t_pipex *pipex)
{
	char	*buf;

	while (1)
	{
		write(1, "pipex heredoc> ", 15);
		buf = get_next_line(STDIN_FILENO);
		if (!buf || *buf == '\0')
		{
			write(1, "\n", 1);
			write(1, "pipex: warning - file delimited by end-of-file ", 47);
			write(1, "(wanted \"", 9);
			write(1, pipex->argv[2], ft_strlen(pipex->argv[2]));
			write(1, "\")\n", 3);
			break ;
		}
		if (ft_strlen(pipex->argv[2]) == ft_strlen(buf) - 1
			&& ft_strncmp(pipex->argv[2], buf, ft_strlen(pipex->argv[2])) == 0)
			break ;
		write(pipex->file_fd.infile_fd, buf, ft_strlen(buf) - 1);
		write(pipex->file_fd.infile_fd, "\n", 1);
		free(buf);
	}
	free(buf);
}
