/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:47:38 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/25 10:20:52 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO: add libft
int	ft_isstrdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*get_value(int v)
{
	int	*mv;

	mv = malloc(sizeof(int));
	if (!mv)
		return (NULL);
	*mv = v;
	return (mv);
}

void	free_value(void *v)
{
	free(v);
}

t_list	*parse(char **argv)
{
	int	i;
	t_list	*pile;
	t_list	*element;

	if (!argv[0] || !ft_isstrdigit(argv[0]))
		return (NULL);
	pile = ft_lstnew(get_value(ft_atoi(argv[0])));
	if (!pile)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		if (!ft_isstrdigit(argv[i]))
		{
			ft_lstclear(&pile, free_value);
			return (0);
		}
		element = ft_lstnew(get_value(ft_atoi(argv[i])));
		ft_lstadd_back(&pile, element);
		i++;
	}
	return (pile);
}
