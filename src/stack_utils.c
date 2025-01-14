/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:31:04 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/10 11:31:25 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*cur;
	int		last;

	if (!stack)
		return (1);
	cur = stack;
	last = val(cur);
	cur = cur->next;
	while (cur)
	{
		if (val(cur) < last)
			return (0);
		last = val(cur);
		cur = cur->next;
	}
	return (1);
}

int	get_index(t_list *stack, int v)
{
	t_list	*cur;
	int		i;

	cur = stack;
	i = 0;
	while (cur && val(cur) != v)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

static int	max_before(t_list *stack, int v)
{
	int		max;
	t_list	*cur;

	cur = stack;
	max = MIN_INT;
	while (cur)
	{
		if (val(cur) < v && val(cur) > max)
			max = val(cur);
		cur = cur->next;
	}
	return (max);
}

int	find_insert_position(t_list *stack, int v)
{
	t_list	*cur;
	int		index;
	int		finded;
	int		mb;

	cur = stack;
	index = 0;
	finded = 0;
	if (!stack)
		return (0);
	mb = max_before(stack, v);
	while (cur->next)
	{
		if (v < ft_lstmin(stack))
		{
			if (val(cur) == ft_lstmin(stack))
				finded = index + 1;
		}
		else if (val(cur->next) == mb)
			finded = index + 1;
		cur = cur->next;
		index++;
	}
	return (finded);
}
