/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:12:53 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/06 22:25:09 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"
// PARSING 
pid_t	my_fork()
{
	pid_t i;
	i = fork();
	if (i < 0)
	{
		perror("fork failled");
		exit(1);	
	}
	return (i);
}

void first_cmd(char **argv, int *end, int infile, char **envp)
{
	char **cmd1;

	if (infile < 0)
		exit(1);
	cmd1 = parsing(argv[2], envp); 
	if (dup2(infile, 0) < 0)
		error("dup failed\n", 2);
	close(infile);
	if (dup2(end[1], 1) < 0)
		error("dup failed\n", 2);
	close(end[1]);
	close(end[0]);
	if (execve(cmd1[0], cmd1, envp) == -1 )
		error("command not found\n", 2);
}

int creat_outfile(char *outfile)
{
	int fd;
	
	fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

void sec_cmd(char **argv, int *end, char **envp)
{
	int		outfile;
	char	**cmd2;
	
	outfile = creat_outfile(argv[4]);
	cmd2 = parsing(argv[3], envp);
	if (dup2(outfile, 1) < 0)
		error("failled to dup\n", 2);
	close(outfile);
	if (dup2(end[0], 0) < 0)
		error("failed to dup", 2);
	close(end[0]);
	close(end[1]);
	if (execve(cmd2[0], cmd2, envp) == -1 )
		error("command not found\n", 2);
}

// PARSING 
int	main(int ac, char **argv, char **envp)
{	
	int		end[2];
	pid_t	i;
	int		stat_loc;
	int		infile;
	
	if (ac == 5)
	{
		infile = open(argv[1], O_RDONLY);
		pipe(end);
		i = my_fork();
		if(i == 0){
			stat_loc = 0;
			first_cmd(argv, end, infile,  envp);
		}
		i = my_fork();
		if (i == 0){
			stat_loc = 0;
			sec_cmd(argv, end, envp);
		}
		close(end[0]);
		close(end[1]);
		while (wait(&stat_loc) != -1)
			;
	}
	return (0); 
}
