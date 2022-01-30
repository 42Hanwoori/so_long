/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:57:33 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 02:43:35 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_is_rectangular(t_game *game)
{
	int	index;

	game->map.width = ft_strlen(game->map.map[0]);
	index = 1;
	while (index < game->map.height)
	{
		if (game->map.width != (int)ft_strlen(game->map.map[index]))
			error("map must be rectangular");
		index += 1;
	}
}

static void	check_map_is_surrounded_by_walls(t_game *game)
{
	int	index;
	int	index2;

	index = 0;
	while (index < game->map.height)
	{
		if (index == 0 OR index == game->map.height - 1)
		{
			index2 = 0;
			while (game->map.map[index][index2] != EOS)
			{
				if (game->map.map[index][index2] != '1')
					error("maps must be surrounded by walls");
				index2 += 1;
			}
		}
		if (game->map.map[index][0] != '1' \
		OR game->map.map[index][game->map.width - 1] != '1')
			error("maps must be surrounded by walls");
		index += 1;
	}
}

static void	check_elements_in_map(t_game *game)
{
	int	index;
	int	index2;

	index = 0;
	while (index < game->map.height)
	{
		index2 = 0;
		while (game->map.map[index][index2] != EOS)
		{
			if (!ft_strchr("01CEP", game->map.map[index][index2]))
				error("map is invalid");
			if (game->map.map[index][index2] == 'C')
				game->map.number_of_collectibles += 1;
			else if (game->map.map[index][index2] == 'E')
				game->map.number_of_exits += 1;
			else if (game->map.map[index][index2] == 'P')
				game->map.number_of_players += 1;
			index2 += 1;
		}
		index += 1;
	}
}

static void	replace_too_many_player(t_game *game)
{
	int	index;
	int	index2;

	index = 0;
	while (index < game->map.height)
	{
		index2 = 0;
		while (game->map.map[index][index2] != EOS)
		{
			if (game->map.map[index][index2] == 'P')
			{
				if (game->map.number_of_players > 1)
				{
					game->map.map[index][index2] = '0';
					game->map.number_of_players -= 1;
				}
				game->player.pos_x = index2;
				game->player.pos_y = index;
			}
			index2 += 1;
		}
		index += 1;
	}
}

void	parse_map(t_game *game)
{
	check_map_is_rectangular(game);
	check_map_is_surrounded_by_walls(game);
	check_elements_in_map(game);
	if (game->map.number_of_players < 1)
		error("map must contain at least one starting position");
	if (game->map.number_of_exits < 1)
		error("map must contain at least one exit position");
	if (game->map.number_of_collectibles < 1)
		error("map must contain at least one collectible");
	replace_too_many_player(game);
}
