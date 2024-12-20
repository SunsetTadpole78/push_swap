/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:23:55 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/20 14:42:57 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_game *game)
{
	void	*temp;
	
	if (game->a->content == NULL || game->a->next == NULL)
		return ;

	print_game(game, "sa");
	temp = game->a->content;
	game->a->content = game->a->next->content;
	game->a->next->content = temp;
}

void	sb(t_game *game)
{	
	void	*temp;
	
	if (game->b->content == NULL || game->b->next == NULL)
		return ;
	
	print_game(game, "sb");
	temp = game->b->content;
	game->b->content = game->b->next->content;
	game->b->next->content = temp;
}

void	ss(t_game *game)
{
	print_game(game, "ss");
	void	*temp;
	
	if (game->a->content == NULL || game->a->next == NULL)
		return ;

	temp = game->a->content;
	game->a->content = game->a->next->content;
	game->a->next->content = temp;
	if (game->b->content == NULL || game->b->next == NULL)
		return ;
	
	temp = game->b->content;
	game->b->content = game->b->next->content;
	game->b->next->content = temp;
}

void	pa(t_game *game)
{
	t_list	*cur;
	t_list	*next;

	if (!game->b || !game->b->content)
		return ;
	print_game(game, "pa");
	cur = game->b;
	next = game->b->next;
	game->b = next;
	ft_lstadd_front(&(game->a), cur);
} 
 
void	pb(t_game *game)
{
	t_list	*cur;
	t_list	*next;

	if (!game->a || !game->a->content)
		return ;
	print_game(game, "pb");
	cur = game->a;
	next = game->a->next;
	game->a = next;
	ft_lstadd_front(&(game->b), cur);
}

void	ra(t_game *game)
{
	t_list	*cur;
	t_list	*next;

	if (!game->a || !game->a->content)
		return ;
	print_game(game, "ra");
	cur = game->a;
	next = game->a->next;
	game->a = next;
	cur->next = NULL;
	ft_lstadd_back(&(game->a), cur);
}

void	rb(t_game *game)
{
	t_list	*cur;
	t_list	*next;

	if (!game->b || !game->b->content)
		return ;
	print_game(game, "rb");
	cur = game->b;
	next = game->b->next;
	game->b = next;
	cur->next = NULL;
	ft_lstadd_back(&(game->b), cur);
}

void	rr(t_game *game)
{
	print_game(game, "rr");
	t_list	*cur;
	t_list	*next;

	if (!game->a || !game->a->content)
		return ;
	cur = game->a;
	next = game->a->next;
	game->a = next;
	cur->next = NULL;
	ft_lstadd_back(&(game->a), cur);

	if (!game->b || !game->b->content)
		return ;
	cur = game->b;
	next = game->b->next;
	game->b = next;
	cur->next = NULL;
	ft_lstadd_back(&(game->b), cur);
}

t_list	*ft_lstpreviouslast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	rra(t_game *game)
{
	t_list	*last;
	t_list	*new_last;

	if (!game->a || !game->a->content || !game->a->next)
		return ;
	print_game(game, "rra");
	last = ft_lstlast(game->a);
	new_last = ft_lstpreviouslast(game->a);
	new_last->next = NULL;
	last->next = game->a;
	ft_lstadd_front(&(game->a), last);
}

void	rrb(t_game *game)
{
	t_list	*last;
	t_list	*new_last;

	if (!game->b || !game->b->content || !game->b->next)
		return ;
	print_game(game, "rrb");
	last = ft_lstlast(game->b);
	new_last = ft_lstpreviouslast(game->b);
	new_last->next = NULL;
	last->next = game->b;
	ft_lstadd_front(&(game->b), last);
}

void	rrr(t_game *game)
{
	print_game(game, "rrr");
	t_list	*last;
	t_list	*new_last;

	if (!game->a || !game->a->content || !game->a->next)
		return ;
	last = ft_lstlast(game->a);
	new_last = ft_lstpreviouslast(game->a);
	new_last->next = NULL;
	last->next = game->a;
	ft_lstadd_front(&(game->a), last);

	if (!game->b || !game->b->content || !game->b->next)
		return ;
	last = ft_lstlast(game->b);
	new_last = ft_lstpreviouslast(game->b);
	new_last->next = NULL;
	last->next = game->b;
	ft_lstadd_front(&(game->b), last);
}
