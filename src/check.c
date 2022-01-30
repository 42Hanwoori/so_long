/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:23:20 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 02:42:24 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void
	check_on_position(t_game *game, int x, int y)
{
	if (game->map.map[game->player.pos_y][game->player.pos_x] == 'C')
	{
		game->map.map[game->player.pos_y][game->player.pos_x] = '0';
		game->map.number_of_collectibles -= 1;
	}
	if (game->map.map[game->player.pos_y][game->player.pos_x] == 'E' AND
		game->map.number_of_collectibles == 0)
	{
		game->map.map[game->player.pos_y][game->player.pos_x] = '0';
		mlx_put_image_to_window(game->mlx, game->window, game->images.ground,
			x, y);
		mlx_put_image_to_window(game->mlx, game->window,
			game->images.charizard, game->player.pos_x * IMG_HEIGHT,
			game->player.pos_y * IMG_WIDTH);
		write(1, "You won!\n", 9);
		game->end = 1;
	}
}

void
	print_score(t_game *game, int number_of_movements)
{
	char	*string;

	string = ft_itoa(number_of_movements);
	mlx_put_image_to_window(game->mlx, game->window, game->images.ground, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->images.stone, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->images.ground, \
	64, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->images.stone, 64, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->images.ground, \
	128, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->images.stone, \
	128, 0);
	mlx_string_put(game->mlx, game->window, 0, 32, 0xFFF, \
	"Number of movements: ");
	mlx_string_put(game->mlx, game->window, 150, 32, 0xFFF, string);
	free(string);
}
