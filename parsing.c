/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rema <rema@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:29:11 by rema              #+#    #+#             */
/*   Updated: 2023/07/27 21:17:47 by rema             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	clearing(t_game *game)
{
	game->walk_cont++;
	ft_printf("%s %d%s\n", GREEN"Congrats !You have"
		C_OFF, game->walk_cont, BLUE" steps"C_OFF);
	exit(0);
}

int	exit_game(t_game *game)
{
	game_exit(game, "");
	return (1);
}

void	map_check_wall(t_game *game)
{
	int		i;

	i = 0;
	while (i < ft_strleni(game->str_line))
	{
		if (i < game->width)
		{
			if (game->str_line[i] != '1')
				exit (ft_printf(RED"Map must be surrounded by walls\n"C_OFF));
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->str_line[i] != '1')
				exit (ft_printf(RED"Map must be surrounded by walls\n"C_OFF));
		}
		else if (i > ft_strleni(game->str_line) - game->width)
		{
			if (game->str_line[i] != '1')
				exit (ft_printf(RED"Map must be surrounded by walls\n"C_OFF));
		}
		i++;
	}
}

void	map_check(t_game *game)
{
	if (game->heigh * game->width != ft_strleni(game->str_line))
		exit(ft_printf(RED"Map must be rectangular.\n"));
	map_check_wall(game);
	check_character(game);
	map_check_params(game);
	}

int	ber_check(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (av[i - 4] == '.' && av[i - 3] == 'b'
		&&av[i - 2] == 'e' && av[i - 1] == 'r')
		return (0);
	ft_printf("Not a valid .ber file\n");
	exit(1);
}
