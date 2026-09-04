/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 23:56:32 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/04 09:34:40 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*line;
	char		*exact_line;
	char		*tmp;
	char		*nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	line = ft_read_buffer(fd, line);
	if (!line || line[0] == '\0')
		return (ft_free_line(&line));
	nl = ft_strchr(line, '\n');
	if (nl)
	{
		exact_line = ft_substr(line, 0, nl - line + 1);
		tmp = line;
		line = ft_strdup(nl + 1);
		free(tmp);
		return (exact_line);
	}
	exact_line = ft_strdup(line);
	ft_free_line(&line);
	return (exact_line);
}
