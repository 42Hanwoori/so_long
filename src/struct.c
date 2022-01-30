/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:20:44 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 02:44:39 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	clean_struct(t_game *game)
{
	ft_free_array((void *) game->map.map, game->map.height);
	if (game->images.ground != NULL)
		mlx_destroy_image(game->mlx, game->images.ground);
	if (game->images.pokeball != NULL)
		mlx_destroy_image(game->mlx, game->images.pokeball);
	if (game->images.collectible != NULL)
		mlx_destroy_image(game->mlx, game->images.collectible);
	if (game->images.charizard != NULL)
		mlx_destroy_image(game->mlx, game->images.charizard);
	if (game->images.charmander[0] != NULL)
		mlx_destroy_image(game->mlx, game->images.charmander[0]);
	if (game->images.charmander[1] != NULL)
		mlx_destroy_image(game->mlx, game->images.charmander[1]);
	if (game->images.charmander[2] != NULL)
		mlx_destroy_image(game->mlx, game->images.charmander[2]);
	if (game->images.charmander[3] != NULL)
		mlx_destroy_image(game->mlx, game->images.charmander[3]);
	if (game->images.stone != NULL)
		mlx_destroy_image(game->mlx, game->images.stone);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

static void	init_struct_map(t_game *game, char *path_map)
{
	game->map.path = path_map;
	game->map.number_of_collectibles = 0;
	game->map.number_of_players = 0;
	game->map.number_of_exits = 0;
	game->map.width = 0;
	game->map.height = read_for_height(game->map.path);
	game->map.map = ft_calloc(game->map.height, sizeof(char *));
	if (game->map.map == NULL)
		error("Malloc");
}

static void	init_image(t_game *game)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	game->images.ground = mlx_xpm_file_to_image(game->mlx, GROUND, \
	&width, &height);
	game->images.charizard = mlx_xpm_file_to_image(game->mlx, CHARIZARD, \
	&width, &height);
	game->images.collectible = mlx_xpm_file_to_image(game->mlx, \
	COLLECTIBLE, &width, &height);
	game->images.stone = mlx_xpm_file_to_image(game->mlx, STONE, &width, \
	&height);
	game->images.pokeball = mlx_xpm_file_to_image(game->mlx, POKEBALL, \
	&width, &height);
	game->images.charmander[0] = mlx_xpm_file_to_image(game->mlx, \
	CHARMANDER_BOTTOM, &width, &height);
	game->images.charmander[1] = mlx_xpm_file_to_image(game->mlx, \
	CHARMANDER_TOP, &width, &height);
	game->images.charmander[2] = mlx_xpm_file_to_image(game->mlx, \
	CHARMANDER_LEFT, &width, &height);
	game->images.charmander[3] = mlx_xpm_file_to_image(game->mlx, \
	CHARMANDER_RIGHT, &width, &height);
}

void	init_struct(t_game *game, char **arguments)
{
	init_struct_map(game, arguments[1]);
	game->title = arguments[0];
	game->player.number_of_movements = 0;
	game->end = 0;
}

void	init_game(t_game *game)
{
	int		width;
	int		height;

	game->mlx = mlx_init();
	height = game->map.height * IMG_HEIGHT;
	width = game->map.width * IMG_WIDTH;
	game->window = mlx_new_window(game->mlx, width, height, game->title);
	if (game->window == NULL)
	{
		clean_struct(game);
		error("Malloc");
	}
	if (game->player.number_of_movements == 0)
		init_image(game);
}
