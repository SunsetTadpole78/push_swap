/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:30:19 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/13 10:02:22 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

# define P_SWAP 0
# define CHECKER 1
# define UNIT_TESTS 2

typedef struct s_game
{
	struct s_list	*a;
	struct s_list	*b;
}	t_game;

//push_swap
void	print_game(t_game *game, char *id);
void	free_game(t_game *game);

//pile_parser.c
t_list	*parse(char **argv);
void	*get_value(int v);
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

//utils.c
t_list	*ft_lstpreviouslast(t_list *lst);
int		val(t_list *stack);

//solver.c
void	sort(t_game *game);
int		get_index(t_list *stack, int v);
int		find_insert_position(t_list *stack, int v);

//calculator.c
int		calc_cost(t_game *game, int v);

//stack_utils.c
int		is_sorted(t_list *stack);
int		get_index(t_list *stack, int v);
int		find_insert_position(t_list *stack, int v);

//stack_operations.c
int		find_cheapest(t_game *game);
void	rotate_stacks(t_game *game, int *times_a, int *times_b, int direction);
void	rotate_a(t_game *game, int times, int direction);
void	rotate_b(t_game *game, int times, int direction);
void	move_to_min(t_game *game, int min);
void	move_to_insert_position(t_game *game, int v);

//type.c
void	set_type(int type);
int		get_type(void);

#endif
