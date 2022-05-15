/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:04:44 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/15 12:44:02 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
		error("dup failed infile \n", NULL, 2);
	close(infile);
	while (i < ac - 1)
		ft_process(i++, ac, argv, envp);
	return (0);
}
