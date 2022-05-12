/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 01:33:01 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/12 11:23:17 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"
pid_t	my_fork()
{
	pid_t i;
	i = fork();
	if (i < 0)
	{
		perror("error");
		exit(1);	
	}
	return (i);
}

void	child_process(int *end, char *cmd, char **envp)
{
	char	**cmds_with_args;
	
	cmds_with_args = parsing(cmd, envp);
	if (dup2(end[1], 1) < 0)
		error("dup failed end\n",  NULL, 2);
	close(end[1]);
	close(end[0]);
	if (execve(cmds_with_args[0], cmds_with_args, envp) == -1 )
		error("command not found: ", cmds_with_args[0], 2);
}

void	last_proces(int	*end, char *file, char *cmd, char **envp)
{
	int		outfile;
	char	**cmds_with_args;

	outfile = creat_outfile(file);
	cmds_with_args = parsing(cmd, envp);
	if (dup2(outfile, 1) < 0)
		error("failled to dup outfile\n", NULL, 2);
	close(outfile);
	if (execve(cmds_with_args[0],cmds_with_args, envp) == -1 )
		error("command not found1: ",cmds_with_args[0], 2);
}

void	ft_process(int i, int ac, char **argv, char **envp)
{
	int		end[2];
	pid_t	id;
	
	pipe(end);
	id = my_fork();
	if (id == 0 && i == ac - 2)
		last_proces(end, argv[i + 1], argv[i], envp);
	if (id == 0)
		child_process(end,argv[i],envp);
	dup2(end[0], 0);
	close(end[0]);
	close(end[1]);
}