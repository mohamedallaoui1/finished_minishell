/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:45:49 by aerraoui          #+#    #+#             */
/*   Updated: 2023/04/14 03:36:46 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_here(int fd, char *limiter, int exp, t_list *env)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!line || ft_cmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		if (exp)
			line = expand(env, line);
		write(fd, line, ft_strlen(line));
		free(line);
		write(1, "> ", 2);
		line = get_next_line(0);
	}
}

void	read_here_doc(t_file1 **file, t_list *env)
{
	int		fd ;
	int		exp ;
	char	*limiter;

	exp = is_expandad((*file)->limiter);
	(*file)->limiter = delete_qouats((*file)->limiter);
	limiter = ft_strdup((*file)->limiter);
	limiter = ft_strjoin(limiter, "\n");
	fd = open((*file)->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	write(1, "> ", 2);
	read_here(fd, limiter, exp, env);
	free(limiter);
}

void	handler(int signum)
{
	(void)signum;
	g_glob.exit_status = 1;
	printf("\n");
	exit(g_glob.exit_status);
}

void	open_here2(t_all1 **all, t_list *env)
{
	t_all1	*tmp;
	t_file1	*file;

		tmp = *all;
	while (tmp)
	{
		file = tmp->file;
		while (file)
		{
			if (file->type == HER)
				read_here_doc(&file, env);
			file = file->next;
		}
		tmp = tmp->next;
	}
}

void	open_here_doc(t_all1 **all, t_list *env)
{
	int		id;
	t_all1	*tmp;
	int		status;

	tmp = *all;
	id = fork();
	if (id == 0)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_DFL);
		open_here2(all, env);
		exit(0);
	}
	else
		waitpid(id, &status, 0);
	if (WEXITSTATUS(status) == 1)
	{
		g_glob.check_sig = WEXITSTATUS(status);
		g_glob.exit_status = WEXITSTATUS(status);
	}
}
