/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:04:44 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/12 11:09:23 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

// char **ft_cmnds(char **ac, char **argv)
// {
// 	// int		i;
// 	// char	**cmnds;
// 	// while (argv[i])
// 	// {
// 	// 	if (i != 0 && i != 1 && i != ac - 1)
// 	// 	{
// 	// 		cmnds = 	
// 	// 	}	
// 	// }	
// }
int creat_outfile(char *outfile)
{
	int fd;
	
	fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	main(int ac, char **argv, char **envp)
{
	int	i;
	int	infile;

	i = 2;
	if (ac < 5)
	{
		error("invalid arguments", NULL, 2);
	}
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{	
		perror("error");
		exit(1);
	}
	if (dup2(infile, 0) < 0)
		error("dup failed infile \n", NULL ,2);
	close(infile);
	while (i < ac - 1)
		ft_process(i++, ac , argv, envp);

}