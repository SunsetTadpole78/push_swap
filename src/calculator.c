/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:09:35 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 15:48:10 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest(t_game *game)
{
	t_list	*cur;
	int		cost;
	int		cheapest_cost;
	int		cheapest;

	cheapest_cost = calc_cost(game, val(game->a));
	cheapest = val(game->a);
	cur = game->a->next;
	while (cur)
	{
		cost = calc_cost(game, val(cur));
		if (cost < cheapest_cost)
		{
			cheapest_cost = cost;
			cheapest = val(cur);
		}
		cur = cur->next;
	}
	return (cheapest);
}

static int	calc_moves_a(t_game *game, int v, int *sa)
{
	int	size_a;
	int	moves_a;

	size_a = ft_lstsize(game->a);
	moves_a = get_index(game->a, v);
	*sa = (moves_a >= size_a / 2);
	if (*sa)
		moves_a = size_a - moves_a;
	return (moves_a);
}

static int	calc_moves_b(t_game *game, int v, int *sb)
{
	int	size_b;
	int	moves_b;

	size_b = ft_lstsize(game->b);
	moves_b = find_insert_position(game->b, v);
	*sb = (moves_b >= size_b / 2);
	if (*sb)
		moves_b = size_b - moves_b;
	return (moves_b);
}

static int	adjust_moves(int moves_a, int moves_b, int sa, int sb)
{
	if (sa == sb)
	{
		if (moves_a > moves_b)
			moves_a -= moves_b;
		else
			moves_b -= moves_a;
	}
	return (moves_a + moves_b);
}

int	calc_cost(t_game *game, int v)
{
	int	moves_a;
	int	moves_b;
	int	sa;
	int	sb;
	int	moves;

	if (ft_lstsize(game->b) == 0)
		return (1);
	moves_a = calc_moves_a(game, v, &sa);
	moves_b = calc_moves_b(game, v, &sb);
	moves = adjust_moves(moves_a, moves_b, sa, sb);
	if (v < ft_lstmin(game->b) || v > ft_lstmax(game->b))
	{
		return (moves + (v < ft_lstmin(game->b) && ft_lstsize(game->a) > 4)
			+ 1);
	}
	return (moves + 1);
}
