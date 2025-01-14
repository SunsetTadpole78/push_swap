/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:12:36 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/09 10:58:13 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **from, t_list **to)
{
	t_list	*cur;
	t_list	*next;

	cur = *from;
	next = (*from)->next;
	*from = next;
	ft_lstadd_front(to, cur);
}

void	pa(t_game *game)
{
	if (!game->b || !game->b->content)
		return ;
	if (get_type() == P_SWAP)
		ft_putstr_fd("pa\n", 1);
	push(&(game->b), &(game->a));
}

void	pb(t_game *game)
{
	if (!game->a || !game->a->content)
		return ;
	if (get_type() == P_SWAP)
		ft_putstr_fd("pb\n", 1);
	push(&(game->a), &(game->b));
}
