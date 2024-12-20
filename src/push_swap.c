/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:15:44 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/14 09:48:21 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_game(t_game *game, char *id)
{
/*	t_list	*a;
	t_list	*b;
	static char	*cur_id = NULL;
	static int times = 0;

	if (cur_id == NULL || ft_strncmp(cur_id, id, 3) != 0)
	{
		if (id[0] != 'i')
		{
			printf("\nExec ");
        		while (times-- > 0)
            			printf("%s ", cur_id);
		}
		printf("\n");
		a = game->a;
		b = game->b;
		while (a || b)
		{
			if (a)
			{
				printf("%i ", *((int *)a->content));
				a = a->next;
			}
			else
				printf("  ");
			if (b)
			{
				printf("%i", *((int *)b->content));
				b = b->next;
			}
			else
				printf(" ");
			printf("\n");
		}
		printf("- -\na b\n=============");
		times = 0;
	}
	cur_id = id;
	times++;*/
	int	i;
	i = 0;
	(void)game;
	while (id[i])
		i++;
	write(1, id, i);
	write(1, "\n", 1);
}

void	display(t_game *game)
{
	t_list	*a;
	t_list	*b;
		a = game->a;
		b = game->b;
		while (a || b)
		{
			if (a)
			{
				printf("%i ", *((int *)a->content));
				a = a->next;
			}
			else
				printf("  ");
			if (b)
			{
				printf("%i", *((int *)b->content));
				b = b->next;
			}
			else
				printf(" ");
			printf("\n");
		}
		printf("- -\na b\n");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 1)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (2);
	game->a = parse(argv + 1);
	game->b = NULL;
	//printf("=============\nInit a and b:");
	solve(game);
	//print_game(game, "");
	//display(game);
	ft_lstclear(&(game->a), free_value);
	ft_lstclear(&(game->b), free_value);

	return (0);
}
