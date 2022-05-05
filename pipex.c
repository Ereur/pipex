/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:12:53 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/05 07:46:09 by aamoussa         ###   ########.fr       */
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

// PARSING 
int	main(int ac, char **argv, char **envp)
{	
	int		fd[2];
	pid_t	i;
	int		stat_loc;
	char	**cmd;
	// stat_loc = 0;
	if (ac == 5)
	{
		cmd = parsing(argv[2], envp);
		int i = 0;
		while(cmd[i])
		{
			printf("%s\n", cmd[i++]);
		}
		// i = my_fork();
		// if(i == 0)
		// {
		// 	char *a = "Hello from child process\n";
		// 	write(1,a,strlen(a));
		// 	sleep(10);
		// 	exit(0);
		// }
		
		// if (wait(NULL) == -1)
		// {	
		// 	perror("wait failled");
		// 	exit(1);
		// }
	}
	return (0); 
}
