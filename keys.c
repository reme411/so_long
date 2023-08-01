/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalnaqb <alalnaqb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:22:12 by rema              #+#    #+#             */
/*   Updated: 2023/07/21 18:56:55 by alalnaqb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strleni(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - g->width] == 'C')
		g->col_cont++;
	if (g->str_line[i - g->width] == 'E' && g->all_col == g->col_cont)
		clearing(g);
	else if (g->str_line[i - g->width] != '1' 
		&& g->str_line[i - g->width] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->width] = 'P';
		g->walk_cont++;
		ft_printf("%d\n", g->walk_cont);
		set_img(g);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strleni(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - 1] == 'C')
		g->col_cont++;
	if (g->str_line[i - 1] == 'E' && g->all_col == g->col_cont)
		clearing(g);
	else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_cont++;
		ft_printf("%d\n", g->walk_cont);
		set_img(g);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strleni(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + g->width] == 'C')
		g->col_cont++;
	if (g->str_line[i + g->width] == 'E' && g->all_col == g->col_cont)
		clearing(g);
	else if (g->str_line[i + g->width] != '1' 
		&& g->str_line[i + g->width] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->width] = 'P';
		g->walk_cont++;
		ft_printf("%d\n", g->walk_cont);
		set_img(g);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strleni(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + 1] == 'C')
		g->col_cont++;
	if (g->str_line[i + 1] == 'E' && g->all_col == g->col_cont)
		clearing(g);
	else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_cont++;
		ft_printf("%d\n", g->walk_cont);
		set_img(g);
	}
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W || key_code == UP)
		move_w(game);
	if (key_code == KEY_A || key_code == LEFT)
		move_a(game);
	if (key_code == KEY_S || key_code == DOWN)
		move_s(game);
	if (key_code == KEY_D || key_code == RIGHT)
		move_d(game);
	return (0);
}

