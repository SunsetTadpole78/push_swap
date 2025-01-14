/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:22:19 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/10 12:02:09 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static t_game	*dup_game(t_game *game)
{
	t_game	*dup;
	t_list	*cur;

	dup = malloc(sizeof(t_game));
	if (!dup)
		return (NULL);
	dup->a = NULL;
	dup->b = NULL;
	cur = game->a;
	while (cur)
	{
		ft_lstadd_back(&(dup->a), ft_lstnew(get_value(*((int *)cur->content))));
		cur = cur->next;
	}
	cur = game->b;
	while (cur)
	{
		ft_lstadd_back(&(dup->b), ft_lstnew(get_value(*((int *)cur->content))));
		cur = cur->next;
	}
	return (dup);
}

int	action_tests(t_game *game, void (*act)(t_game *),
		int (test)(t_game *, t_game *, void *), int n)
{
	int		i;
	int		s;
	t_game	*dup;

	i = 0;
	s = 1;
	while (i < n)
	{
		i++;
		dup = dup_game(game);
		if (!dup)
			malloc_fail(game);
		act(game);
		if (test(dup, game, act))
			s &= success(i, "");
		else
			s &= fail(i, "function don't work");
		free_game(dup);
	}
	return (s);
}

static int	init_test(t_game *game)
{
	center("INIT TESTS", '=');
	if (stack_equals(game->a, 4, 5, 3, -4, 1)
		&& stack_equals(game->b, 3, 6, 2, 10))
		return (success(1, "Game initialized"));
	fail(1, "Game uninitialized, code is broken");
	exit(EXIT_FAILURE);
}

static int	tests(t_game *game)
{
	int	success;

	success = init_test(game);
	success &= pa_tests(game);
	success &= pb_tests(game);
	success &= sa_tests(game);
	success &= sb_tests(game);
	success &= ra_tests(game);
	success &= rb_tests(game);
	success &= rra_tests(game);
	success &= rrb_tests(game);
	return (success);
}

int	main(void)
{
	t_game	*game;
	int		success;

	set_type(UNIT_TESTS);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init_stack(&(game->a), 4, 1, -4, 3, 5);
	init_stack(&(game->b), 3, 10, 2, 6);
	success = tests(game);
	center("", '=');
	if (success)
	{
		green(1);
		center("All tests passed !\n", ' ');
	}
	else
	{
		red(1);
		center("Some tests fails !\n", ' ');
	}
	reset(1);
	return (0);
}
