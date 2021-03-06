/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:12:53 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/21 10:48:30 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_cmd(char **argv, int *end, int infile, char **envp)
{
	char	**cmd1;

	if (infile < 0)
		exit(1);
	cmd1 = parsing(argv[2], envp);
	dup2(infile, 0);
	close(infile);
	if (dup2(end[1], 1) < 0)
		error("dup failed end\n test", NULL, 2);
	close(end[1]);
	close(end[0]);
	if (execve(cmd1[0], cmd1, envp) == -1)
		error("command not found: ", cmd1[0], 2);
}

void	sec_cmd(char **argv, int *end, char **envp)
{
	int		outfile;
	char	**cmd2;

	outfile = creat_outfile(argv[4], NULL);
	cmd2 = parsing(argv[3], envp);
	if (dup2(outfile, 1) < 0)
		error("failled to dup outfile ok\n", NULL, 2);
	close(outfile);
	if (dup2(end[0], 0) < 0)
		error("failled to dup end ok0\n", NULL, 2);
	close(end[0]);
	close(end[1]);
	if (execve(cmd2[0], cmd2, envp) == -1)
		error("command not found: ", cmd2[0], 2);
}

// PARSING
int	main(int ac, char **argv, char **envp)
{
	int		end[2];
	pid_t	i;
	int		infile;

	if (ac == 5)
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			perror("error");
		pipe(end);
		i = my_fork();
		if (i == 0)
			first_cmd(argv, end, infile, envp);
		i = my_fork();
		if (i == 0)
			sec_cmd(argv, end, envp);
		close(end[1]);
		close(end[0]);
		while (wait(NULL) != -1)
			;
	}
	return (0);
}
///