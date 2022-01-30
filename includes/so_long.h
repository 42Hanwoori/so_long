/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <whan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:34:32 by whan              #+#    #+#             */
/*   Updated: 2022/01/30 01:04:05 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/mlx/mlx.h"
# include "../library/libft/get_next_line.h"
# include <fcntl.h>

# define IMG_WIDTH 64
# define IMG_HEIGHT 64

# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define CHARMANDER_TOP "./assets/img/charmander_top.xpm"
# define CHARMANDER_BOTTOM "./assets/img/charmander_bottom.xpm"
# define CHARMANDER_RIGHT "./assets/img/charmander_right.xpm"
# define CHARMANDER_LEFT "./assets/img/charmander_left.xpm"
# define CHARIZARD "./assets/img/charizard.xpm"
# define STONE "./assets/img/stones.xpm"
# define POKEBALL "./assets/img/pokeball.xpm"
# define GROUND "./assets/img/ground.xpm"
# define COLLECTIBLE "./assets/img/collectible.xpm"

typedef struct s_map	t_map;
typedef struct s_player	t_player;
typedef struct s_images	t_images;
typedef struct s_game	t_game;

struct s_map
{
	char	**map;
	char	*path;
	int		number_of_collectibles;
	int		number_of_players;
	int		number_of_exits;
	int		width;
	int		height;
};

struct s_player
{
	int	pos_x;
	int	pos_y;
	int	number_of_movements;
};

struct s_images
{
	void	*stone;
	void	*charmander[4];
	void	*collectible;
	void	*pokeball;
	void	*charizard;
	void	*ground;
};

struct s_game
{
	t_map		map;
	t_player	player;
	t_images	images;
	int			end;
	char		*title;
	void		*mlx;
	void		*window;
};

void	check_arguments(int number_of_arguments, char **arguments);

void	parse_map(t_game *game);

void	check_on_position(t_game *game, int x, int y);

void	print_score(t_game *game, int number_of_movements);

void	error(char *message);

void	display_map(t_game *game);

void	put_image(t_game *game, char *path, int x, int y);

void	read_map(t_game *game);

int		read_for_height(char *path_map);

int		controller(int key, t_game *game);

int		clean_struct(t_game *game);

void	init_struct(t_game *game, char **arguments);

void	init_game(t_game *game);

void	*ft_free_array(void **pointer, int size);

void	*ft_free(void *pointer);

#endif
