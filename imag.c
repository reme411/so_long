/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rema <rema@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:18:31 by rema              #+#    #+#             */
/*   Updated: 2023/07/27 21:01:53 by rema             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_img	load_img(void *mlx)
{
	t_img	thing;
	int		w;
	int		h;

	thing.grass = mlx_xpm_file_to_image(mlx, "./img/gras.xpm", &w, &h);
	thing.wall = mlx_xpm_file_to_image(mlx, "./img/waly.xpm", &w, &h);
	thing.cloud = mlx_xpm_file_to_image(mlx, "./img/cloudd.xpm", &w, &h);
	thing.coin = mlx_xpm_file_to_image(mlx, "./img/coinns.xpm", &w, &h);
	thing.portal = mlx_xpm_file_to_image(mlx, "./img/fds1.xpm", &w, &h);
	thing.portal2 = mlx_xpm_file_to_image(mlx, "./img/fds2.xpm", &w, &h);
	if (!thing.grass || !thing.wall || !thing.cloud || !thing.coin
		|| !thing.portal || !thing.portal2)
	{
		if (thing.grass)
			mlx_destroy_image(mlx, thing.grass);
		if (thing.wall)
			mlx_destroy_image(mlx, thing.wall);
		if (thing.cloud)
			mlx_destroy_image(mlx, thing.cloud);
		if (thing.coin)
			mlx_destroy_image(mlx, thing.coin);
		if (thing.portal)
			mlx_destroy_image(mlx, thing.portal);
		if (thing.portal2)
			mlx_destroy_image(mlx, thing.portal2);
		exit(EXIT_FAILURE);
	}
	return (thing);
}

void	put_img(t_game *g, int wd, int ht)
{
	if (g->str_line[ht * g->width + wd] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, wd * 64, ht * 64);
	}
	else if (g->str_line[ht * g->width + wd] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.coin, wd * 64, ht * 64);
	}
	else if (g->str_line[ht * g->width + wd] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.cloud, wd * 64, ht * 64);
	}
	else if (g->str_line[ht * g->width + wd] == 'E'
		&& g->all_col == g->col_cont)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.portal2, wd * 64, ht
			* 64);
	}
	else if (g->str_line[ht * g->width + wd] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.portal, wd * 64, ht
			* 64);
	}
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.grass, wd * 64, ht * 64);
}

void	set_img(t_game *game)
{
	int y; //hight
	int x; //width
	y = 0;
	while (y < game->heigh)
	{
		x = 0;
		while (x < game->width)
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}

void	check_character(t_game *game)
{
	int	i;

	i = 0;
	while (game->str_line[i])
	{
		if (game->str_line[i] != '1' && game->str_line[i] != 'C'
			&& game->str_line[i] != 'E' && game->str_line[i] != '0'
			&& game->str_line[i] != 'P' && game->str_line[i] != '\n')
		{
			game_exit(game, RED"wrong Character found in the map"C_OFF);
		}
		i++;
	}
}
void check_player(t_game *game)
{
	int x = 0;
	int y = 0;
	int playerCount = 0;

	while (y < game->heigh)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->str_line[y * game->width + x] == 'P')
			{
				game->x = x;
				game->y = y;
				playerCount++;
			}
			x++;
		}
		y++;
	}

}
