/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:04:44 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/26 17:29:01 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(char *lim)
{
	int		end[2];
	char	*line;
	char	*tmp;

	pipe(end);
	line = get_next_line(0);
	lim = ft_strjoin(lim,"\n");
	if (ft_strncmp(lim, line, ft_strlen(line)))	
		write(end[1], line, ft_strlen(line));
	while (ft_strncmp(lim, line, ft_strlen(line)))
	{	
		tmp = line;
		line = get_next_line(0);
		free(tmp);
		if (!ft_strncmp(lim, line, ft_strlen(line)))
			break ;
		write(end[1], line, ft_strlen(line));
	}
	free(lim);
	free(line);
	dup2(end[0], 0);
	close(end[0]);
	close(end[1]);
}

int	main(int ac, char **argv, char **envp)
{
	int		i;
	int		infile;

	i = 2;
	if (ac < 5)
		error("invalid arguments", NULL, 2);
	if (!strncmp("here_doc", argv[1], 8) && i++)
		here_doc(argv[2]);
	else
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
		{	
			perror("Error");
			i++;
		}
		dup2(infile, 0);
		close(infile);
	}
	while (i < ac - 1)
		ft_process(i++, ac, argv, envp);
	while (wait(NULL) != -1)
		;
	return (0);
}
