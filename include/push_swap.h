/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:30:19 by lroussel          #+#    #+#             */
/*   Updated: 2024/12/11 11:40:24 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdio.h> //TODO

typedef struct	s_game
{
		struct s_list	*a;
		struct s_list	*b;
}		t_game;

//push_swap
void	print_game(t_game *game, char *id);

//pile_parser.c
t_list	*parse(char **argv);
void	free_value(void *v);
//move.c
void	sa(t_game *game);
void	sb(t_game *game);
void	ss(t_game *game);
void	pa(t_game *game);
void	pb(t_game *game);
void	ra(t_game *game);
void	rb(t_game *game);
void	rr(t_game *game);
void	rra(t_game *game);
void	rrb(t_game *game);
void	rrr(t_game *game);

t_list  *ft_lstpreviouslast(t_list *lst);

//solver.c
void	solve(t_game *game);

#endif
