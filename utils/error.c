/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:36:05 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/16 07:00:40 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

short	check_slash(char *cmnd)
{
	char	*tmp;
	int		count;

	tmp = cmnd;
	count = 0;
	while (*tmp)
	{
		if (*tmp == '/')
			count++;
		else
			count = 0;
		if (count >= 2)
			return (1);
		tmp++;
	}
	return (0);
}

int	error(char *msg, char *cmd, int fd)
{	
	if (cmd)
	{	
		if (ft_strchr(cmd, '/'))
		{
			msg = "no such file or directory: ";
			write(fd, msg, ft_strlen(msg));
			write(fd, cmd, ft_strlen(cmd));
			write(fd, "\n", 1);
			exit(1);
		}
		write(fd, msg, ft_strlen(msg));
		write(fd, cmd, ft_strlen(cmd));
		write(fd, "\n", 1);
		exit(1);
	}
	else
	{
		write(fd, "Error: ", 7);
		write(fd, msg, ft_strlen(msg));
		exit(1);
	}
	return (0);
}
