/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:15:44 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/25 10:15:03 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*pile;
	t_list	*aff;
	if (argc == 1)
	{
		ft_putstr_fd("invalid", 2);//TODO
		return (1);
	}
	pile = parse(argv + 1);
	aff = pile;
	while (aff)
	{
		printf("%p : %i\n", aff->content, *(int *)(aff->content));
		aff = aff->next;
	}
	ft_lstclear(&pile, free_value);

	return (0);
}
