/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:39:35 by whan              #+#    #+#             */
/*   Updated: 2022/01/31 02:47:02 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	check_arguments(ac, av);
	init_struct(&game, av);
	read_map(&game);
	parse_map(&game);
	init_game(&game);
	if (game.player.number_of_movements == 0)
		display_map(&game);
	mlx_hook(game.window, 17, 0, clean_struct, &game);
	mlx_key_hook(game.window, controller, &game);
	mlx_loop(game.mlx);
	return (0);
}
