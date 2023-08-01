/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rema <rema@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:27:20 by alalnaqb          #+#    #+#             */
/*   Updated: 2023/07/27 20:58:10 by rema             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
# define C_OFF "\033[0m"

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

# include "mlx.h"
# include "./printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void	*cloud;
	void	*coin;
	void	*grass;
	void	*portal;
	void	*portal2;
	void	*wall;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		heigh;
	char	*str_line;
	int		all_col;
	int		col_cont;
	int		walk_cont;
	int		x;
	int		y;
	bool	visited[256][256];
}				t_game;

/*   image.c  */
t_img	load_img(void *mlx);
void	put_img(t_game *g, int wd, int ht);
void	set_img(t_game *game);
void check_player(t_game *game);


/*   mapping.c   */
void	read_map(char *filename, t_game *game);
void	dfs(t_game *game, int x, int y);

/*   parsing.c   */
int		clearing(t_game *game);
int		exit_game(t_game *game);
void	map_check(t_game *game);
void	map_check_wall(t_game *game);
void	map_check_params(t_game *game);
int		ber_check(char *av);
void	check_character(t_game *game);

/*  keys.c      */
void	move_w(t_game *g);
void	move_a(t_game *g);
void	move_s(t_game *g);
void	move_d(t_game *g);
int		press_key(int key_code, t_game *game);

/*   so_long.c  */
int		clearing(t_game *game);
void	game_init(t_game *g, char *map);
void	game_exit(t_game *game, const char *msg);

/*   so_long_utils.c  */
char	*ft_strdupi(char *s);
int		ft_strlcpy(char *dst, char *src, int len);
char	*ft_strjoinn(char *s1, char *s2);
int		ft_strleni(char *str);
int		ft_strncmpp(const char *s1, const char *s2, size_t n);
char	*ft_strrchrr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *s, int c, size_t len);

#endif