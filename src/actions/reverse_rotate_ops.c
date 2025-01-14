/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:13:52 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 09:34:31 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*new_last;

	last = ft_lstlast(*stack);
	new_last = ft_lstpreviouslast(*stack);
	new_last->next = NULL;
	last->next = *stack;
	ft_lstadd_front(stack, last);
}

void	rra(t_game *game)
{
	if (!game->a || !game->a->content || !game->a->next)
		return ;
	if (get_type() == P_SWAP)
		ft_putstr_fd("rra\n", 1);
	reverse_rotate(&(game->a));
}

void	rrb(t_game *game)
{
	if (!game->b || !game->b->content || !game->b->next)
		return ;
	if (get_type() == P_SWAP)
		ft_putstr_fd("rrb\n", 1);
	reverse_rotate(&(game->b));
}

void	rrr(t_game *game)
{
	if (!game->a || !game->a->content || !game->a->next)
	{
		rrb(game);
		return ;
	}
	if (!game->b || !game->b->content || !game->b->next)
	{
		rra(game);
		return ;
	}
	if (get_type() == P_SWAP)
		ft_putstr_fd("rrr\n", 1);
	reverse_rotate(&(game->a));
	reverse_rotate(&(game->b));
}
