/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalnaqb <alalnaqb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:26:21 by rema              #+#    #+#             */
/*   Updated: 2023/03/09 18:54:49 by alalnaqb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_line(int fd, char *buf, char *backup)
{
	int		sbyte;
	char	*tmp;

	sbyte = 1;
	while (sbyte != '\0')
	{
		sbyte = read(fd, buf, BUFFER_SIZE);
		if (sbyte == -1)
			return (0);
		else if (sbyte == 0)
			break ;
		buf[sbyte] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		tmp = NULL;
		if (!backup)
			return (NULL);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*ft_extract(char *line)
{
	size_t	i;
	char	*remains;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	remains = ft_substr(line, i, ft_strlen(line) - i);
	if (*remains == '\0')
	{
		free(remains);
		remains = NULL;
	}
	line[i] = '\0';
	return (remains);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = ft_extract(line);
	return (line);
}
