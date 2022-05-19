/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:04:44 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/19 13:36:56 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(char *lim)
{
	int		end[2];
	char	*line;

	pipe(end);
	line = get_next_line(0);
	write(end[1], line, ft_strlen(line));
	while (1)
	{
		line = get_next_line(0);
		if (!ft_strncmp(lim, line, ft_strlen(lim)))
			break ;
		write(end[1], line, ft_strlen(line));
	}
	dup2(end[0], 0);
	close(end[0]);
	close(end[1]);
}

int	main(int ac, char **argv, char **envp)
{
	int		i;
	int		infile;
	int		*end;

	end = NULL;
	i = 2;
	if (ac < 5)
		error("invalid arguments", NULL, 2);
	if (!strncmp("here_doc", argv[1], 8))
	{	
		here_doc(argv[2]);
		i++;
	}
	else
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			perror("Error");
		if (dup2(infile, 0) < 0)
			error("dup failed infile \n", NULL, 2);
		close(infile);
	}
	while (i < ac - 1)
		ft_process(i++, ac, argv, envp);
	return (0);
}
