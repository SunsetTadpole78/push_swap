/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:47:38 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/10 11:29:58 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*get_value(int v)
{
	int	*mv;

	mv = malloc(sizeof(int));
	if (!mv)
		return (NULL);
	*mv = v;
	return (mv);
}

static int	exist(t_list *head, int v)
{
	t_list	*cur;

	cur = head;
	while (cur)
	{
		if (val(cur) == v)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static int	check_im(char *v)
{
	long int	nb;
	int			i;
	int			sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (v[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (v[i] && i <= 11)
	{
		nb = nb * 10 + (v[i] - '0');
		i++;
	}
	nb *= sign;
	return (nb < MIN_INT || nb > MAX_INT);
}

static t_list	*create_stack(char **argv)
{
	int		i;
	t_list	*pile;
	int		v;

	pile = NULL;
	i = 0;
	while (argv[i])
	{
		v = ft_atoi(argv[i]);
		if (!ft_isdigit_str(argv[i]) || exist(pile, v) || check_im(argv[i]))
		{
			ft_lstclear(&pile, free_value);
			free(pile);
			return (NULL);
		}
		ft_lstadd_back(&pile, ft_lstnew(get_value(v)));
		i++;
	}
	return (pile);
}

t_list	*parse(char **argv)
{
	char	**splited;
	t_list	*stack;
	int		i;

	if (!argv || !argv[0] || !argv[0][0])
		return (NULL);
	if (ft_strchr(argv[0], ' ') && !argv[1])
	{
		splited = ft_split(argv[0], ' ');
		stack = create_stack(splited);
		i = 0;
		while (splited[i])
			free(splited[i++]);
		free(splited);
		return (stack);
	}
	return (create_stack(argv));
}
