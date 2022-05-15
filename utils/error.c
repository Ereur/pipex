/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:36:05 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/15 10:30:26 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	error(char *msg, char *cmd, int fd)
{	
	if (cmd)
	{	
		if (ft_strchr(cmd, '/'))
		{
			msg = "no such file or directory : ";
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
		write(fd, msg, ft_strlen(msg));
		exit(1);
	}
	return (0);
}
