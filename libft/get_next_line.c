/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:38:47 by mignavar          #+#    #+#             */
/*   Updated: 2024/01/30 13:03:41 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*appendix_read(char *buff, char *buff_read)
{
	char	*temp;

	temp = ft_strjoin(buff, buff_read);
	free(buff);
	return (temp);
}

static char	*read_file(char *buff, int fd)
{
	int		rd;
	char	*buff_read;

	buff_read = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff_read)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff_read, BUFFER_SIZE);
		if (rd < 1)
		{
			free(buff_read);
			if (buff[0] != '\0' && rd == 0)
				return (buff);
			free(buff);
			return (NULL);
		}
		buff_read[rd] = '\0';
		buff = appendix_read(buff, buff_read);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff_read);
	return (buff);
}

static char	*extract_line(char *buff)
{
	char	*line;
	int		l;

	l = 0;
	while (buff[l] != '\n' && buff[l] != '\0')
		l++;
	if (buff[l] == '\n')
		l++;
	line = ft_calloc(l + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (l--)
		line[l] = buff[l];
	return (line);
}

static char	*rest_buff(char *buff)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\n')
		i++;
	temp = ft_calloc((ft_strlen(buff) - i) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	j = 0;
	while (buff[i] != '\0')
		temp[j++] = buff[i++];
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
	{
		buff = ft_calloc(1, sizeof(char));
		if (!buff)
			return (NULL);
	}
	if (!ft_strchr(buff, '\n'))
		buff = read_file(buff, fd);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	line = extract_line(buff);
	buff = rest_buff(buff);
	return (line);
}
