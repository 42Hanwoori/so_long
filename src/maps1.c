/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:25:57 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 01:31:54 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	open_map(char *map)
{
	int	filedescriptor;

	filedescriptor = open(map, O_RDONLY, 644);
	if (filedescriptor == -1)
		error("File does not exist");
	return (filedescriptor);
}

void		read_map(t_game *game)
{
	char	*buffer;
	int		buffer_length;
	int		index;
	int		filedescriptor;

	filedescriptor = open_map(game->map.path);
	buffer = get_next_line(filedescriptor);
	if (buffer == NULL)
		error("Invalid map or empty map");
	index = 0;
	while (buffer != NULL)
	{
		buffer_length = ft_strlen(buffer);
		if (buffer[buffer_length - 1] == '\n')
		{
			game->map.map[index] = ft_strdup(buffer);
			game->map.map[index][buffer_length - 1] = EOS;
		}
		else
			game->map.map[index] = ft_strdup(buffer);
		index += 1;
		free(buffer);
		buffer = get_next_line(filedescriptor);
	}
	close(filedescriptor);
}

int			read_for_height(char *path_map)
{
	int		index;
	int		filedescriptor;
	char	*buffer;

	index = 0;
	filedescriptor = open_map(path_map);
	buffer = get_next_line(filedescriptor);
	while (buffer != NULL)
	{
		index += 1;
		free(buffer);
		buffer = get_next_line(filedescriptor);
	}
	close(filedescriptor);
	return (index);
}
