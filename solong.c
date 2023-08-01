/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rema <rema@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:27:20 by rema              #+#    #+#             */
/*   Updated: 2023/08/01 14:29:39 by rema             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	clear_game(t_game *game)
{
	game->walk_cont++;
	ft_printf(RED"%s %d%s\n","Congrats! You have"C_OFF, game->walk_cont, BLUE" steps !!" C_OFF);
	exit(0);
}


void game_exit(t_game *game, const char *msg)
{
	if (game->img.grass)
		mlx_destroy_image(game->mlx, game->img.grass);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.cloud)
		mlx_destroy_image(game->mlx, game->img.cloud);
	if (game->img.coin)
		mlx_destroy_image(game->mlx, game->img.coin);
	if (game->img.portal)
		mlx_destroy_image(game->mlx, game->img.portal);
	if (game->img.portal2)
		mlx_destroy_image(game->mlx, game->img.portal2);
	// mlx_destroy_window(game->mlx, game->win);
	free(game);
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	game_init(t_game *g, char *map)
{
	g->mlx = mlx_init();
	g->img = load_img(g->mlx);
	
	read_map(map, g);
	map_check(g);
	g->win = mlx_new_window(g->mlx, g->width * 64, g->heigh * 64, "REX!");
	set_img(g);
}

int	main(int ac, char **av)
{
	t_game	*game = NULL;

	if (ac != 2)
	{
		exit(ft_printf( RED"HELL NO !!! Map is missing bro.\n"C_OFF));
	}
	game = malloc(sizeof(t_game));
	
	ber_check(av[1]);
	game_init(game, av[1]);
	if (!game->mlx)
		return (ft_printf(RED"\n  ERROR INITIALIZING MLX  \n"C_OFF ), 1);
	
	check_player(game);
	
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
