/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:36:05 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 09:36:06 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	init_stack(t_list **stack, int scale, ...)
{
	va_list	args;
	int		el;

	va_start(args, scale);
	el = va_arg(args, int);
	while (scale--)
	{
		ft_lstadd_front(stack, ft_lstnew(get_value(el)));
		el = va_arg(args, int);
	}
	va_end(args);
}

int	stack_equals(t_list *stack, int scale, ...)
{
	va_list	args;
	int		el;
	t_list	*cur;

	va_start(args, scale);
	cur = stack;
	el = va_arg(args, int);
	while (cur && scale--)
	{
		if (*((int *)cur->content) != el)
			return (0);
		el = va_arg(args, int);
		cur = cur->next;
	}
	va_end(args);
	return (!cur);
}
