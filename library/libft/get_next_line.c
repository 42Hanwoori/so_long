/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:26:17 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 01:36:56 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_string	gnl_line(t_string buffer)
{
	t_i32		index;
	t_string	string;

	if (!buffer[0])
		return ((void *) 0);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index += 1;
	if (buffer[index] == '\n')
		index += 1;
	string = ft_calloc((index + 1), sizeof(t_c8));
	if (!string)
		return ((void *) 0);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		string[index] = buffer[index];
		index += 1;
	}
	if (buffer[index] == '\n')
		string[index++] = '\n';
	string[index] = '\0';
	return (string);
}

static t_string	gnl_save(t_string buffer)
{
	t_i32		index;
	t_i32		index2;
	t_string	string;

	if (!buffer)
		return ((void *) 0);
	index = 0;
	index2 = 0;
	while (buffer[index] && buffer[index] != '\n')
		index += 1;
	if (buffer[index] == '\0')
		return (ft_free(buffer));
	string = ft_calloc(((ft_strlen(buffer) - index) + 1), sizeof(t_c8));
	if (!string)
		return ((void *) 0);
	index += 1;
	while (buffer[index])
		string[index2++] = buffer[index++];
	string[index2] = '\0';
	ft_free(buffer);
	return (string);
}

t_string	get_next_line(t_i32 filedescriptor)
{
	t_string		buffer;
	t_i64			bytes_read;
	t_string		line;
	static t_string	tmp = (void *) 0;

	bytes_read = 1;
	if (!tmp)
		tmp = ft_calloc(1, sizeof(t_c8));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(t_c8));
	if (filedescriptor < 0 || BUFFER_SIZE < 1 || !buffer || bytes_read < 0)
		return (ft_free(buffer), ft_free(tmp));
	while (bytes_read != 0 && !ft_strchr(tmp, '\n'))
	{
		bytes_read = read(filedescriptor, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(buffer));
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	ft_free(buffer);
	line = gnl_line(tmp);
	tmp = gnl_save(tmp);
	return (line);
}
