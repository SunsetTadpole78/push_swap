/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:13:55 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 09:33:52 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*cur;
	t_list	*next;

	cur = *stack;
	next = (*stack)->next;
	(*stack) = next;
	cur->next = NULL;
	ft_lstadd_back(stack, cur);
}

void	ra(t_game *game)
{
	if (!game->a || !game->a->content)
		return ;
	if (get_type() == P_SWAP)
		ft_putstr_fd("ra\n", 1);
	rotate(&(game->a));
}

void	rb(t_game *game)
{
	if (!game->b || !game->b->content)
		return ;
	if (get_type() == P_SWAP)
		ft_putstr_fd("rb\n", 1);
	rotate(&(game->b));
}

void	rr(t_game *game)
{
	if (!game->a || !game->a->content)
	{
		rb(game);
		return ;
	}
	if (!game->b || !game->b->content)
	{
		ra(game);
		return ;
	}
	if (get_type() == P_SWAP)
		ft_putstr_fd("rr\n", 1);
	rotate(&(game->a));
	rotate(&(game->b));
}
