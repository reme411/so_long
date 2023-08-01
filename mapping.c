/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rema <rema@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:28:21 by rema              #+#    #+#             */
/*   Updated: 2023/08/01 14:07:44 by rema             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		exit(ft_printf("FILE FAILED TO OPEEEEN SENURAAA.\n"));
	line = get_next_line(fd);
	if(!line)
	{
		close(fd);
		exit(ft_printf(" there is nothing here !!!"));
	}
	game->heigh = 0;
	game->walk_cont = 0;
	game->width = ft_strleni(line) - 1;
	game->str_line = ft_strdupi(line);
	free(line);
	while (line)
	{
		game->heigh++;
		line = get_next_line(fd);
		if (line)
			game->str_line = ft_strjoinn(game->str_line, line);
	}
	close(fd);
}

void dfs(t_game *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->width || y >= game->heigh || game->visited[y][x])
        return;

    game->visited[y][x] = true;

    int index = y * game->width + x;
	if (game->str_line[index] == '1' || game->str_line[index] == 'E')
		return ;
    if (game->str_line[index] == 'C')
        game->col_cont++;
	dfs(game, x, y - 1);
	dfs(game, x + 1, y);
	dfs(game, x, y + 1);
	dfs(game, x - 1, y);
}

bool dfs_end(t_game *game, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->width || y >= game->heigh || game->visited[y][x])
        return false;

    game->visited[y][x] = true;

    int index = y * game->width + x;
	if (game->str_line[index] == 'E')
		return true;
	if (game->str_line[index] == '1')
		return false;
	return (dfs_end(game, x, y - 1) || dfs_end(game, x + 1, y) || dfs_end(game, x, y + 1) || dfs_end(game, x - 1, y)); 
}

void	map_check_params(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	game->all_col = 0;
	game->col_cont = 0;
	while (i++ < ft_strleni(game->str_line))
	{
		if (game->str_line[i] == 'E')
			num_e++;
		else if (game->str_line[i] == 'P')
			num_p++;
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	ft_memset(game->visited, false, sizeof(game->visited));
	check_player(game);
    dfs(game, game->x, game->y);
	ft_printf("coins = %d\n", game->col_cont);
    if (game->col_cont != game->all_col)
        game_exit(game, RED"Coin is not reachable by the player\n");
	if (num_e == 0)
		game_exit(game, RED"Map must have at least one exit\n"C_OFF);
	if (game->all_col == 0)
		game_exit(game, RED"Map must have at least one collectible\n"C_OFF);
	if (num_p != 1)
		game_exit(game, RED"Map must have one starting position\n"C_OFF);
	game->col_cont = 0;
	ft_memset(game->visited, false, sizeof(game->visited));
	if (!dfs_end(game, game->x, game->y))
		game_exit(game, RED" sorry there is no path bro/sis\n"C_OFF);
}