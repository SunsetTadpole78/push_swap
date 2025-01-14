/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:46:29 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 14:17:52 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

static int	test_swap(t_game *before, t_game *after, void *action)
{
	if (action == sa)
	{
		return ((before->a == NULL && after->a == NULL)
			|| ((val(before->a) == val(after->a)
					&& before->a->next == NULL && after->a->next == NULL))
			|| ((val(before->a) == val(after->a->next))
				&& (val(before->a->next) == val(after->a))));
	}
	return ((before->b == NULL && after->b == NULL)
		|| ((val(before->b) == val(after->b)
				&& before->b->next == NULL && after->b->next == NULL))
		|| ((val(before->b) == val(after->b->next))
			&& (val(before->b->next) == val(after->b))));
}

int	sa_tests(t_game *game)
{
	int	success;

	center("SWAP A (sa)", '=');
	while (game->a)
		pb(game);
	success = 1;
	test_name("null stack a:\n");
	success &= action_tests(game, sa, test_swap, 1);
	test_name("one element in a:\n");
	pa(game);
	success &= action_tests(game, sa, test_swap, 1);
	test_name("two element in a:\n");
	pa(game);
	success &= action_tests(game, sa, test_swap, 1);
	test_name("three element in a:\n");
	pa(game);
	success &= action_tests(game, sa, test_swap, 3);
	return (success);
}

int	sb_tests(t_game *game)
{
	int	success;

	center("SWAP B (sb)", '=');
	while (game->b)
		pa(game);
	success = 1;
	test_name("null stack b:\n");
	success &= action_tests(game, sb, test_swap, 1);
	test_name("one element in b:\n");
	pb(game);
	success &= action_tests(game, sb, test_swap, 1);
	test_name("two element in b:\n");
	pb(game);
	success &= action_tests(game, sb, test_swap, 1);
	test_name("three element in b:\n");
	pb(game);
	success &= action_tests(game, sb, test_swap, 3);
	return (success);
}
