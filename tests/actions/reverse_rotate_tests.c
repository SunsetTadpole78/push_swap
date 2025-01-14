/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:46:29 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 14:16:37 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

static int	test_rrotate(t_game *before, t_game *after, void *action)
{
	if (action == rra)
	{
		return ((before->a == NULL && after->a == NULL)
			|| ((val(before->a) == val(after->a)
					&& before->a->next == NULL && after->a->next == NULL))
			|| ((val(after->a) == val(ft_lstlast(before->a)))
				&& (val(after->a->next) == val(before->a))));
	}
	else
	{
		return ((before->b == NULL && after->b == NULL)
			|| ((val(before->b) == val(after->b)
					&& before->b->next == NULL && after->b->next == NULL))
			|| ((val(after->b) == val(ft_lstlast(before->b)))
				&& (val(after->b->next) == val(before->b))));
	}
}

int	rra_tests(t_game *game)
{
	int			success;

	center("REVERSE ROTATE A (rra)", '=');
	while (game->a)
		pb(game);
	success = 1;
	test_name("null stack a:\n");
	success &= action_tests(game, rra, test_rrotate, 1);
	test_name("one element in a:\n");
	pa(game);
	success &= action_tests(game, rra, test_rrotate, 1);
	test_name("two element in a:\n");
	pa(game);
	success &= action_tests(game, rra, test_rrotate, 1);
	test_name("three element in a:\n");
	pa(game);
	success &= action_tests(game, rra, test_rrotate, 3);
	test_name("four element in a:\n");
	pa(game);
	success &= action_tests(game, rra, test_rrotate, 3);
	return (success);
}

int	rrb_tests(t_game *game)
{
	int			success;

	center("REVERSE ROTATE B (rrb)", '=');
	while (game->b)
		pa(game);
	success = 1;
	test_name("null stack b:\n");
	success &= action_tests(game, rrb, test_rrotate, 1);
	test_name("one element in b:\n");
	pb(game);
	success &= action_tests(game, rrb, test_rrotate, 1);
	test_name("two element in b:\n");
	pb(game);
	success &= action_tests(game, rrb, test_rrotate, 1);
	test_name("three element in b:\n");
	pb(game);
	success &= action_tests(game, rrb, test_rrotate, 3);
	test_name("four element in b:\n");
	pb(game);
	success &= action_tests(game, rrb, test_rrotate, 3);
	return (success);
}
