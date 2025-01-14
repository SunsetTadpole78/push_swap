/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:44:58 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 13:08:02 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"

static int	test_push(t_game *before, t_game *after, void *action)
{
	if (action == pa)
	{
		return ((before->b == NULL && after->b == NULL
				&& val(after->a) == val(before->a))
			|| ((after->b == NULL || val(after->b) == val(before->b->next))
				&& val(after->a) == val(before->b)));
	}
	return ((before->a == NULL && after->a == NULL
			&& val(after->b) == val(before->b))
		|| ((after->a == NULL || val(after->a) == val(before->a->next))
			&& val(after->b) == val(before->a)));
}

int	pa_tests(t_game *game)
{
	center("PUSH TO A (pa)", '=');
	return (action_tests(game, pa, test_push, ft_lstsize(game->b) + 1));
}

int	pb_tests(t_game *game)
{
	center("PUSH TO B (pb)", '=');
	return (action_tests(game, pb, test_push, ft_lstsize(game->a) + 1));
}
