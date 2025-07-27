/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:33:39 by kagdas            #+#    #+#             */
/*   Updated: 2025/07/27 16:12:46 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_buff(char *buff)
{
	char	*new_buff;
	int		i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	i++;
	new_buff = ft_substr(buff, i, ft_strlen(buff) - i);
	free(buff);
	return (new_buff);
}

static char	*ft_extract_line(char *buff)
{
	int		i;
	char	*line;

	if (!buff[0] && !buff)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	line = ft_substr(buff, 0, i);
	return (line);
}

static char	*ft_readfile(int fd, char *buff)
{
	char	*temp;
	int		cntrl;
	char	*new;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	cntrl = 1;
	while (!ft_strchr(buff, '\n') && cntrl > 0)
	{
		cntrl = read(fd, temp, BUFFER_SIZE);
		if (cntrl == -1)
			return (free(temp), free(buff), NULL);
		temp[cntrl] = '\0';
		new = ft_strjoin(buff, temp);
		if (!new)
			return (free(temp), NULL);
		free(buff);
		buff = new;
	}
	free(temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_calloc(1, 1);
	buff = ft_readfile(fd, buff);
	if (!buff || !*buff)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	line = ft_extract_line(buff);
	buff = ft_clean_buff(buff);
	return (line);
}
