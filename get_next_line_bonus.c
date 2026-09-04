/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 18:13:09 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/04 10:49:37 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*ft_free_line(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

static char	*ft_read_buffer(int fd, char *line)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*lines[1024];
	char		*exact_line;
	char		*tmp;
	char		*nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!lines[fd])
		lines[fd] = ft_strdup("");
	lines[fd] = ft_read_buffer(fd, lines[fd]);
	if (!lines[fd] || lines[fd][0] == '\0')
		return (ft_free_line(&lines[fd]));
	nl = ft_strchr(lines[fd], '\n');
	if (nl)
	{
		exact_line = ft_substr(lines[fd], 0, nl - lines[fd] + 1);
		tmp = lines[fd];
		lines[fd] = ft_strdup(nl + 1);
		free(tmp);
		return (exact_line);
	}
	exact_line = ft_strdup(lines[fd]);
	ft_free_line(&lines[fd]);
	return (exact_line);
}
