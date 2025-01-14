/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:14:02 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/09 10:58:47 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack)
{
	void	*temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	sa(t_game *game)
{
	if (game->a == NULL || game->a->content == NULL || game->a->next == NULL)
		return ;
	if (get_type() == P_SWAP)
		ft_putstr_fd("sa\n", 1);
	swap(game->a);
}

void	sb(t_game *game)
{
	if (game->b == NULL || game->b->content == NULL || game->b->next == NULL)
		return ;
	if (get_type() == P_SWAP)
		ft_putstr_fd("sb\n", 1);
	swap(game->b);
}

void	ss(t_game *game)
{
	if (game->a->content == NULL || game->a->next == NULL)
	{
		sb(game);
		return ;
	}
	if (game->b->content == NULL || game->b->next == NULL)
	{
		sa(game);
		return ;
	}
	if (get_type() == P_SWAP)
		ft_putstr_fd("ss\n", 1);
	swap(game->a);
	swap(game->b);
}
