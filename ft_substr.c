/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:12:15 by aamoussa          #+#    #+#             */
/*   Updated: 2022/05/06 22:42:07 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_strcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
	{
		ptr = (char *)malloc(sizeof (char) * 1);
		*ptr = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
	}
	ptr = (char *)malloc(len + 1);
	if (!ptr || !len)
		return (NULL);
	ft_strcpy(ptr, s + start, len + 1);
	return (ptr);
}
