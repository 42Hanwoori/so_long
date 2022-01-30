/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:39:35 by whan              #+#    #+#             */
/*   Updated: 2022/01/30 22:46:21 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	check_arguments(ac, av);//확장자.ber가 맞는지, 한개만 들어온거 맞는지 확인
	init_struct(&game, av);//맵 구조체 등의 정보를 읽기전에 초기화해둔다
	read_map(&game);//game구조체 안 **map 에 채워둠
	parse_map(&game);//맵 유효성 검사 및 플레이어 정보 초기화
	init_game(&game);//게임창열고, xpm파일들을 받아온다
	if (game.player.number_of_movements == 0)
		display_map(&game);//바닥 먼저 깔고, game 구조체 map 읽으면서 벽, 수집품, 출구 깔고난 후 플레이어
	mlx_hook(game.window, 17, 0, clean_struct, &game);
	mlx_key_hook(game.window, controller, &game);
	mlx_loop(game.mlx);//한쪽에선 스크린에 픽셀 보내고(display_map), 한쪽에선 키보드 이벤트를 받아온다(hook).
	//clean_struct(&game);
	return (0);
}
