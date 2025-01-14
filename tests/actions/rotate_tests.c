/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:46:29 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 13:08:45 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

int	test_rotate(t_game *before, t_game *after, void *action)
{
	if (action == ra)
	{
		return ((before->a == NULL && after->a == NULL)
			|| (val(before->a) == val(after->a)
				&& before->a->next == NULL && after->a->next == NULL)
			|| (val(before->a) == val(ft_lstlast(after->a))
				&& (val(before->a->next) == val(after->a))));
	}
	else
	{
		return ((before->b == NULL && after->b == NULL)
			|| (val(before->b) == val(after->b)
				&& before->b->next == NULL && after->b->next == NULL)
			|| (val(before->b) == val(ft_lstlast(after->b))
				&& (val(before->b->next) == val(after->b))));
	}
}

int	ra_tests(t_game *game)
{
	int	success;

	center("ROTATE A (ra)", '=');
	while (game->a)
		pb(game);
	success = 1;
	test_name("null stack a:\n");
	success &= action_tests(game, ra, test_rotate, 1);
	test_name("one element in a:\n");
	pa(game);
	success &= action_tests(game, ra, test_rotate, 1);
	test_name("two element in a:\n");
	pa(game);
	success &= action_tests(game, ra, test_rotate, 1);
	test_name("three element in a:\n");
	pa(game);
	success &= action_tests(game, ra, test_rotate, 3);
	test_name("four element in a:\n");
	pa(game);
	success &= action_tests(game, ra, test_rotate, 3);
	return (success);
}

int	rb_tests(t_game *game)
{
	int	success;

	center("ROTATE B (rb)", '=');
	while (game->b)
		pa(game);
	success = 1;
	test_name("null stack b:\n");
	success &= action_tests(game, rb, test_rotate, 1);
	test_name("one element in b:\n");
	pb(game);
	success &= action_tests(game, rb, test_rotate, 1);
	test_name("two element in b:\n");
	pb(game);
	success &= action_tests(game, rb, test_rotate, 1);
	test_name("three element in b:\n");
	pb(game);
	success &= action_tests(game, rb, test_rotate, 3);
	test_name("four element in b:\n");
	pb(game);
	success &= action_tests(game, rb, test_rotate, 3);
	return (success);
}
