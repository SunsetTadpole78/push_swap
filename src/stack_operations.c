/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:31:41 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 09:33:38 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stacks(t_game *game, int *times_a, int *times_b, int direction)
{
	while (*times_a > 0 && *times_b > 0)
	{
		if (direction == 1)
			rrr(game);
		else
			rr(game);
		(*times_a)--;
		(*times_b)--;
	}
}

void	rotate_a(t_game *game, int times, int direction)
{
	while (times > 0)
	{
		if (direction == 1)
			rra(game);
		else
			ra(game);
		times--;
	}
}

void	rotate_b(t_game *game, int times, int direction)
{
	while (times > 0)
	{
		if (direction == 1)
			rrb(game);
		else
			rb(game);
		times--;
	}
}

void	move_to_min(t_game *game, int min)
{
	int	index;

	index = get_index(game->a, min);
	while (val(game->a) != min)
	{
		if (index <= (ft_lstsize(game->a) / 2))
			ra(game);
		else
			rra(game);
	}
}

void	move_to_insert_position(t_game *game, int v)
{
	int	index;

	index = find_insert_position(game->a, v);
	while (!(val(ft_lstlast(game->a)) < v && v < val(game->a)))
	{
		if (index <= (ft_lstsize(game->a) / 2))
			ra(game);
		else
			rra(game);
	}
}
