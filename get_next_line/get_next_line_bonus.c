/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:44:01 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/02/16 16:44:26 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	ssize_t	i;

	new = ft_strnew(ft_strlen(s1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !(ptr = (char *)malloc(ft_strlen(s1)
		+ ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFFER_SIZE + (r = 1)];
	static char	*fd_list[FD_SIZE];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	fd_list[fd] == NULL ? fd_list[fd] = ft_strnew(0) : NULL;
	while (!ft_strchr(fd_list[fd], '\n') && (r = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[r] = '\0';
		tmp = ft_strjoin(fd_list[fd], bf);
		ft_memdel((void **)&fd_list[fd]);
		fd_list[fd] = tmp;
	}
	if (r == 0)
		*line = ft_strdup(fd_list[fd]);
	else if (r > 0)
		*line = ft_substr(fd_list[fd], 0, (ft_strchr(fd_list[fd], '\n') - fd_list[fd]));
	else
		return (-1);
	tmp = ft_strdup(fd_list[fd] + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));
	ft_memdel((void **)&fd_list[fd]);
	fd_list[fd] = tmp;
	return (r == 0 ? 0 * ft_memdel((void **)&fd_list[fd]) : 1);
}
