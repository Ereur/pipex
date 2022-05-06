/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:12:53 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/06 19:07:19 by aamoussa         ###   ########.fr       */
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

// void first_cmd(char **argv, int *end, )
// {
	
// }

// void sec_cmd()
// {

// }

// PARSING 
int	main(int ac, char **argv, char **envp)
{	
	int		end[2];
	pid_t	i;
	int		stat_loc;
	int		infile;
	char	**cmd;
	char	**tmp;
	// stat_loc = 0;
	if (ac == 5)
	{
		cmd = parsing(argv[2], envp);
		tmp = cmd;
		int j = 0;
		while (tmp[j])
			printf("%s\n",tmp[j++]);
		// system("leaks pipex");
		// exit(1);
		// free(tmp);
		// infile = open(argv[1], O_RDONLY);
		// pipe(end);
		// i = my_fork();
		// if(i == 0)
		// 	first_cmnd(argv, end, infile,  envp);
		// i = my_fork();
		// if (i == 0)
		// 	sec_cmnd(argv, end, envp);
		// if (wait(NULL) == -1)
		// {	
		// 	perror("wait failled");
		// 	exit(1);
		// }
	}
	return (0); 
}
