/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 23:56:32 by abezatog          #+#    #+#             */
/*   Updated: 2026/08/30 18:40:04 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_buffer(int fd, char *line)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*total_read;
	char		*exact_line;
	int			i;

	total_read = ft_read_buffer(fd, leftover);
	if (!total_read || total_read[0] == '\0')
		return (NULL);
	i = 0;
	while (total_read[i] && total_read[i] != '\n')
		i++;
	if (total_read[i] == '\n')
		i++;
	exact_line = ft_substr(total_read, 0, i);
	leftover = ft_substr(total_read, i, ft_strlen(total_read) - 1);
	return (exact_line);
}
