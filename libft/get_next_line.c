/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimarque <mimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:07:04 by mimarque          #+#    #+#             */
/*   Updated: 2022/06/20 04:47:51 by mimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief do while; read file, if file has '\n'
 * 		then return it. If not store everything 
 * 		in backup[fd] and return NULL
 * 
 * @param backup backup from get_next_line
 * @param fd file descriptor
 * @param buf buffer from get_next_line
 * @return char* 
 */
char	*cycle(char **backup, int fd, char *buf)
{
	int	size;

	size = read(fd, buf, BUFFER_SIZE);
	buf[size] = '\0';
	while (size > 0)
	{
		backup[fd] = ft_strjoinfree(backup[fd], buf);
		if (ft_strchr(backup[fd], '\n') != NULL)
			return (returner(backup, fd));
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
	}
	return (NULL);
}

/**
 * @brief Splits backup on '\n' into line wich is returned
 * 		and temp wich is stored into backup[fd] after 
 * 		it (backup[fd]) has been free'd
 * 
 * @param backup backup from get_next_line
 * @param fd file descriptor
 * @return char* 
 */
char	*returner(char **backup, int fd)
{
	int		index;
	char	*line;
	char	*temp;

	index = ft_strchr(backup[fd], '\n') - backup[fd] + 1;
	line = ft_strldup(backup[fd], 0, index);
	temp = ft_strldup(backup[fd], index, ft_strlen(backup[fd]));
	free(backup[fd]);
	backup[fd] = temp;
	return (line);
}

/**
 * @brief If backup doesn't have a '\n' from a previous call
 * 		cycle through the do while untill you get a '\n' or a null.
 * 		if it does have a '\n': split backup on '\n' 
 * 		into line wich is returned (and temp wich is stored 
 * 		back into backup[fd] after it has been free'd)
 * 		If it is a null and backup[fd] is not '\0' return what you
 * 		have else return NULL 
 * 
 * @param fd file descriptor
 * @return char* 
 */
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[NUM_OF_FD];
	char		*line;

	if (fd < 0 || fd > NUM_OF_FD)
		return (NULL);
	line = NULL;
	if (ft_strchr(backup[fd], '\n') == NULL)
	{
		line = cycle(backup, fd, buf);
		if (line != NULL)
			return (line);
	}
	else
		return (returner(backup, fd));
	if (backup[fd] != NULL && *backup[fd] != '\0')
	{
		line = backup[fd];
		backup[fd] = NULL;
		return (line);
	}
	free(line);
	free(backup[fd]);
	backup[fd] = NULL;
	return (NULL);
}
