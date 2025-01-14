/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:23:55 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/09 10:34:31 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstpreviouslast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	free_game(t_game *game)
{
	ft_lstclear(&(game->a), free_value);
	ft_lstclear(&(game->b), free_value);
	free(game);
}

void	free_value(void *v)
{
	free(v);
}

int	val(t_list *stack)
{
	return (*(int *)(stack->content));
}
