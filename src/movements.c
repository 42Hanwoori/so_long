/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:19:47 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 02:46:41 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_up(t_game *game, int tmp_x, int tmp_y)
{
	if (game->map.map[game->player.pos_y - 1][game->player.pos_x] != '1')
	{
		if (game->map.map[game->player.pos_y - 1][game->player.pos_x] == 'E' \
		AND game->map.number_of_collectibles > 0)
			return ;
		game->player.pos_y -= 1;
		game->player.number_of_movements += 1;
		check_on_position(game, tmp_x, tmp_y);
		if (game->end != 0)
			return ;
		mlx_put_image_to_window(game->mlx, game->window, game->images.ground, \
		tmp_x, tmp_y);
		mlx_put_image_to_window(game->mlx, game->window, \
		game->images.charmander[1], game->player.pos_x * IMG_HEIGHT, \
		game->player.pos_y * IMG_WIDTH);
		write(1, "Player's moves: ", 16);
		write(1, ft_itoa(game->player.number_of_movements), \
		ft_strlen(ft_itoa(game->player.number_of_movements)));
		write(1, "\n", 1);
	}
}

static void	move_down(t_game *game, int tmp_x, int tmp_y)
{
	if (game->map.map[game->player.pos_y + 1][game->player.pos_x] != '1')
	{
		if (game->map.map[game->player.pos_y + 1][game->player.pos_x] == 'E' \
		AND game->map.number_of_collectibles > 0)
			return ;
		game->player.pos_y += 1;
		game->player.number_of_movements += 1;
		check_on_position(game, tmp_x, tmp_y);
		if (game->end != 0)
			return ;
		mlx_put_image_to_window(game->mlx, game->window, game->images.ground, \
		tmp_x, tmp_y);
		mlx_put_image_to_window(game->mlx, game->window, \
		game->images.charmander[0], game->player.pos_x * IMG_HEIGHT, \
		game->player.pos_y * IMG_WIDTH);
		write(1, "Player's moves: ", 16);
		write(1, ft_itoa(game->player.number_of_movements), \
		ft_strlen(ft_itoa(game->player.number_of_movements)));
		write(1, "\n", 1);
	}
}

static void	move_left(t_game *game, int tmp_x, int tmp_y)
{
	if (game->map.map[game->player.pos_y][game->player.pos_x - 1] != '1')
	{
		if (game->map.map[game->player.pos_y][game->player.pos_x - 1] == 'E' \
		AND game->map.number_of_collectibles > 0)
			return ;
		game->player.pos_x -= 1;
		game->player.number_of_movements += 1;
		check_on_position(game, tmp_x, tmp_y);
		if (game->end != 0)
			return ;
		mlx_put_image_to_window(game->mlx, game->window, game->images.ground, \
		tmp_x, tmp_y);
		mlx_put_image_to_window(game->mlx, game->window, \
		game->images.charmander[2], game->player.pos_x * IMG_HEIGHT, \
		game->player.pos_y * IMG_WIDTH);
		write(1, "Player's moves: ", 16);
		write(1, ft_itoa(game->player.number_of_movements), \
		ft_strlen(ft_itoa(game->player.number_of_movements)));
		write(1, "\n", 1);
	}
}

static void	move_right(t_game *game, int tmp_x, int tmp_y)
{
	if (game->map.map[game->player.pos_y][game->player.pos_x + 1] != '1')
	{
		if (game->map.map[game->player.pos_y][game->player.pos_x + 1] == 'E' \
		AND game->map.number_of_collectibles > 0)
			return ;
		game->player.pos_x += 1;
		game->player.number_of_movements += 1;
		check_on_position(game, tmp_x, tmp_y);
		if (game->end != 0)
			return ;
		mlx_put_image_to_window(game->mlx, game->window, game->images.ground, \
		tmp_x, tmp_y);
		mlx_put_image_to_window(game->mlx, game->window, \
		game->images.charmander[3], game->player.pos_x * IMG_HEIGHT, \
		game->player.pos_y * IMG_WIDTH);
		write(1, "Player's moves: ", 16);
		write(1, ft_itoa(game->player.number_of_movements), \
		ft_strlen(ft_itoa(game->player.number_of_movements)));
		write(1, "\n", 1);
	}
}

int	controller(int key, t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = game->player.pos_x * IMG_HEIGHT;
	tmp_y = game->player.pos_y * IMG_WIDTH;
	if (key == KEY_ESC)
	{
		if (game->end == 0)
			write(1, "You failed!\n", 12);
		clean_struct(game);
		exit(0);
	}
	else if ((key == KEY_W OR key == KEY_UP) AND game->end == 0)
		move_up(game, tmp_x, tmp_y);
	else if ((key == KEY_A OR key == KEY_LEFT) AND game->end == 0)
		move_left(game, tmp_x, tmp_y);
	else if ((key == KEY_D OR key == KEY_RIGHT) AND game->end == 0)
		move_right(game, tmp_x, tmp_y);
	else if ((key == KEY_S OR key == KEY_DOWN) AND game->end == 0)
		move_down(game, tmp_x, tmp_y);
	return (0);
}
