/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:43:26 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 09:43:27 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	type(int v)
{
	static int	t = P_SWAP;

	if (v != -1)
		t = v;
	return (t);
}

void	set_type(int t)
{
	if (t < P_SWAP || t > UNIT_TESTS)
	{
		ft_putstr_fd("Error: Invalid type id\n", 2);
		exit(EXIT_FAILURE);
	}
	type(t);
}

int	get_type(void)
{
	return (type(-1));
}
