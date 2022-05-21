/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:32:09 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/21 10:33:25 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

pid_t	my_fork(void)
{
	pid_t	i;

	i = fork();
	if (i < 0)
	{
		perror("error");
		exit(1);
	}
	return (i);
}

int	creat_outfile(char *outfile, char *here_doc)
{
	int	fd;

	if (here_doc && !strncmp("here_doc", here_doc, 8))
		fd = open(outfile, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

static char	**parse_env_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*tmp;

	i = 0;
	paths = NULL;
	while (envp[i] && ft_strncmp("PATH", envp[i], 4))
	{
		i++;
	}
	if (envp[i])
		paths = ft_split(&envp[i][5], ':');
	i = 0;
	while (paths && paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		if (!paths[i])
			error("strjoin failed", NULL, 2);
		free(tmp);
		i++;
	}
	return (paths);
}

static void	check_paths(char **cmd, char **paths)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (paths && paths[i])
	{	
		tmp = ft_strjoin(paths[i], cmd[0]);
		if (!access(tmp, X_OK))
		{
			free(cmd[0]);
			cmd[0] = tmp;
			return ;
		}
		free(tmp);
		i++;
	}
}

char	**parsing(char *cmd, char **envp)
{
	char	**cmd_args;
	char	**paths;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		exit(1);
	paths = parse_env_paths(envp);
	check_paths(cmd_args, paths);
	while (paths && paths[i])
		free(paths[i++]);
	free(paths);
	return (cmd_args);
}
