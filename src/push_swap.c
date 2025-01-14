/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:15:44 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 12:37:35 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 1)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (2);
	game->a = parse(argv + 1);
	if (!game->a)
	{
		ft_putstr_fd("Error\n", 2);
		free(game);
		return (3);
	}
	game->b = NULL;
	sort(game);
	free_game(game);
	return (0);
}
