/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:21:43 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/20 16:18:32 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_solved(t_game *game, int start, int end_offset)
{
	t_list	*cur;
	int	last;
	int	size;

	if (end_offset < 0 || start < 0)
		return (0);
	if (!game->a)
		return (1);
	size = ft_lstsize(game->a) - start - end_offset - 1;
	if (size < 0)
		return (0);
	if (game->a)
	{
		cur = game->a;
		while (start != 0 && cur->next)
		{
			cur = cur->next;
			start--;
		}
		last = *((int *)cur->content);
		cur = cur->next;
		while (size && cur)
		{
			if (*((int *)cur->content) < last)
				return (0);
			last = *((int *)cur->content);
			cur = cur->next;
			size--;
		}

	}
	return (1);
}

int	lmax(t_list *list)
{
	int	max;
	t_list	*cur;

	max = *((int *)list->content);
	cur = list->next;
	while (cur)
	{
		if (*((int *)cur->content) > max)
			max = *((int *)cur->content);
		cur = cur->next;
	}
	return (max);
}

int	lmin(t_list *list)
{
	int	min;
	t_list	*cur;

	min = *((int *)list->content);
	cur = list->next;
	while (cur)
	{
		if (*((int *)cur->content) < min)
			min = *((int *)cur->content);
		cur = cur->next;
	}
	return (min);
}

int	get_index(t_game *game, int v)
{
	t_list	*cur;
	int	i;

	cur = game->a;
	i = 0;
	while (cur && *((int *)cur->content) != v)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

int	is_before_max(t_list *stack, int check, int v)
{
	int	max;
	t_list	*cur;

	cur = stack;
	max = -1;
	while (cur->next)
	{
		if (*((int *)cur->content) < v && *((int *)cur->content) > max)
			max = *((int *)cur->content);
		cur = cur->next;
	}
	return (check == max);
}

int	find_insert_position(t_list *stack, int v)
{
	t_list	*cur = stack;
	int	index = 0;
	int	finded = 0;

	if (!stack)
		return (0);

	while (cur->next)
	{
		//if (*((int *)cur->content) < v && *((int *)cur->next->content) < v && is_sorted_before(game, index) && finded == 0)
		//	finded = index + 1;
		if (v < lmin(stack))
		{
			if (*((int *)cur->content) == lmin(stack))
				finded = index + 1;
		}
		else if ((*((int *)cur->content) > v && *((int *)cur->next->content) < v) || is_before_max(stack, *((int *)cur->next->content), v))
		{
				if (finded == 0/* || (index + 1) > (ft_lstsize(stack) / 2)*/)//TODO:selon le sens de a et ses moves
					finded = index + 1;
		}
		cur = cur->next;
		index++;
	}
	//if (v == 86)
	//	printf("FIND %i ", finded);
	return (finded);
}

int	calc_cost(t_game *game, int v)
{
	int	size;
	int	min;
	int	max;
	int	moves;
	int	moves_b;
	//int	sa;
	//int	sb;
	//int	diff;

	//sa = 0;
	//sb = 0;
	size = ft_lstsize(game->b);
	min = lmin(game->b);
	max = lmax(game->b);

	if (size == 0)
		return (1);

	moves = get_index(game, v);
	if (moves >= ft_lstsize(game->a) / 2)
	{
	//	sa = 1;
		moves = ft_lstsize(game->a) - moves;
	}
	moves_b = find_insert_position(game->b, v);
	if (moves_b >= size / 2)
	{
	//	sb = 1;
		moves_b = size - moves_b;
	}
	//diff = 0;
	//if (sa == sb)
	//	diff = moves - moves_b;
	//if (diff < 0)
	//	diff = -diff;
	if (v < min || v > max)
		return (moves + (v < min) + 1 + moves_b);

	return (moves + 1 + moves_b);
}

void	sort_game(t_game *game)
{
	int	cheapest_cost;
	int	cheapest;
	int	cost;
	t_list	*cur;

	cheapest_cost = calc_cost(game, *((int *)game->a->content));
	cheapest = *((int *)game->a->content);
	cur = game->a->next;
	while (cur)
	{
		cost = calc_cost(game, *((int *)cur->content));
		if (cost < cheapest_cost)
		{
			cheapest_cost = cost;
			cheapest = *((int *)cur->content);
		}
		cur = cur->next;
	}
	int	nb = get_index(game, cheapest);
	int	s = nb > ft_lstsize(game->a) / 2;
	if (nb > (ft_lstsize(game->a) / 2))
		nb = (ft_lstsize(game->a) - nb);
	int	pos = find_insert_position(game->b, cheapest);
	int	sens = pos > ft_lstsize(game->b) / 2;
	if (pos > (ft_lstsize(game->b) / 2))
		pos = (ft_lstsize(game->b) - pos);
	
	if (s == sens)
	{
		while(nb > 0 && pos > 0)
		{
			if (s == 1)
				rrr(game);
			else
				rr(game);
			nb--;
			pos--;
		}
	}	
	while (nb > 0)
	{
		if (s == 1)	
			rra(game);
		else
			ra(game);
		nb--;
	}
	while (pos > 0)
	{
		if (sens == 1)
			rrb(game);
		else
			rb(game);
		pos--;
	}
	pb(game);
}

void	sort_a_three(t_game *game)
{
	while (!is_solved(game, 0, 0))
	{
		if (*((int *)game->a->content) > *((int *)game->a->next->next->content))
		{
			if (*((int *)game->a->content) > *((int *)game->a->next->content))
				ra(game);
			else
				rra(game);
		}
		if (*((int *)game->a->content) > *((int *)game->a->next->content))
			sa(game);
		if (*((int *)game->a->next->content) > *((int *)game->a->next->next->content))
			rra(game);
	}
}

void	repush_all(t_game *game)
{
	int	v;
	int	min;
	int	max;

	while (game->b)
	{
		v = *((int *)game->b->content);
		min = lmin(game->a);
		max = lmax(game->a);
		if (v < min || v > max)
		{
			while (*((int *)game->a->content) != min)
			{
				if (get_index(game, min) < (ft_lstsize(game->a) / 2))
					ra(game);
				else
					rra(game);
			}
		}
		else
		{
			while (!(*((int *)ft_lstlast(game->a)->content) < v && v < *((int *)game->a->content)))
			{
				if (get_index(game, v) < (ft_lstsize(game->a) / 2))
					ra(game);
				else
					rra(game);
			}
		}
		pa(game);
	}
}

void	solve(t_game *game)
{
	if (is_solved(game, 0, 0))
		return ;
	if (ft_lstsize(game->a) == 2)
	{
		ra(game);
		return ;
	}
	if (ft_lstsize(game->a) == 3)
	{
		sort_a_three(game);
		return ;
	}
	pb(game);
	while (ft_lstsize(game->a) > 3)
		sort_game(game);

	sort_a_three(game);
	repush_all(game);
	while (*((int *)game->a->content) != lmin(game->a))
	{
		if (get_index(game, lmin(game->a)) < (ft_lstsize(game->a) / 2))
			ra(game);
		else
			rra(game);
	}
}
