/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:29:28 by whan              #+#    #+#             */
/*   Updated: 2022/01/29 23:57:29 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_underground(t_game *game, char *path)
{
	void	*image;
	int		x;
	int		y;
	int		height;
	int		width;

	y = 0;
	height = 64;
	width = 64;
	image = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (image == NULL)
		error("image error");
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x] != EOS)
		{
			mlx_put_image_to_window(game->mlx, game->window, image, x * width, \
			y * height);
			x += 1;
		}
		y += 1;
	}
}

void		display_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	put_underground(game, GROUND);
	while (++y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x] != EOS)
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->images.stone, x * IMG_HEIGHT, y * IMG_WIDTH);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->images.pokeball, x * IMG_HEIGHT, y * IMG_WIDTH);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->images.collectible, x * IMG_HEIGHT, y * IMG_WIDTH);
			x += 1;
		}
	}
	mlx_put_image_to_window(game->mlx, game->window, \
	game->images.charmander[0], game->player.pos_x * IMG_HEIGHT, \
	game->player.pos_y * IMG_WIDTH);
}
