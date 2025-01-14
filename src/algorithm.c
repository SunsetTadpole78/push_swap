/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lroussel <lroussel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/10 16:21:43 by lroussel		  #+#	#+#			 */
/*   Updated: 2025/01/10 11:40:47 by lroussel         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_game *game)
{
	while (!is_sorted(game->a))
	{
		if (val(game->a) > val(game->a->next->next))
		{
			if (val(game->a) > val(game->a->next))
				ra(game);
			else
				rra(game);
		}
		if (val(game->a) > val(game->a->next))
			sa(game);
		if (val(game->a->next) > val(game->a->next->next))
			rra(game);
	}
}

static void	sort_game(t_game *game)
{
	int		cheapest;
	int		times_a;
	int		times_b;
	int		direction_a;
	int		direction_b;

	cheapest = find_cheapest(game);
	times_a = get_index(game->a, cheapest);
	direction_a = times_a > ft_lstsize(game->a) / 2;
	if (direction_a)
		times_a = ft_lstsize(game->a) - times_a;
	times_b = find_insert_position(game->b, cheapest);
	direction_b = times_b > ft_lstsize(game->b) / 2;
	if (direction_b)
		times_b = ft_lstsize(game->b) - times_b;
	if (direction_a == direction_b)
		rotate_stacks(game, &times_a, &times_b, direction_a);
	rotate_a(game, times_a, direction_a);
	rotate_b(game, times_b, direction_b);
	pb(game);
}

static void	repush_all(t_game *game)
{
	int	v;
	int	min;

	while (game->b)
	{
		v = val(game->b);
		min = ft_lstmin(game->a);
		if (v < min || v > ft_lstmax(game->a))
			move_to_min(game, min);
		else
			move_to_insert_position(game, v);
		pa(game);
	}
}

void	sort(t_game *game)
{
	if (is_sorted(game->a))
		return ;
	if (ft_lstsize(game->a) == 2)
	{
		ra(game);
		return ;
	}
	if (ft_lstsize(game->a) == 3)
	{
		sort_three(game);
		return ;
	}
	pb(game);
	while (ft_lstsize(game->a) > 3)
		sort_game(game);
	sort_three(game);
	repush_all(game);
	while (val(game->a) != ft_lstmin(game->a))
	{
		if (get_index(game->a, ft_lstmin(game->a)) < (ft_lstsize(game->a) / 2))
			ra(game);
		else
			rra(game);
	}
}
