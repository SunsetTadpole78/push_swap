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

/* _______________________________ Constantes _______________________________ */

# define P_SWAP 0
# define CHECKER 1
# define UNIT_TESTS 2

/* _______________________________ Structure ________________________________ */

typedef struct s_game
{
	struct s_list	*a;
	struct s_list	*b;
}	t_game;

/* ___________________________ actions/push_ops.c ___________________________ */

void	pa(t_game *game);
void	pb(t_game *game);

/* ______________________ actions/reverse_rotate_ops.c ______________________ */

void	rra(t_game *game);
void	rrb(t_game *game);
void	rrr(t_game *game);

/* __________________________ actions/rotate_ops.c __________________________ */

void	ra(t_game *game);
void	rb(t_game *game);
void	rr(t_game *game);

/* ___________________________ actions/swap_ops.c ___________________________ */

void	sa(t_game *game);
void	sb(t_game *game);
void	ss(t_game *game);

/* ______________________________ algorithnm.c ______________________________ */

void	sort(t_game *game);

/* ______________________________ calculator.c ______________________________ */

int		find_cheapest(t_game *game);
int		calc_cost(t_game *game, int v);

/* _____________________________ pile_parser.c ______________________________ */

void	*get_value(int v);
t_list	*parse(char **argv);

/* ___________________________ stack_operations.c ___________________________ */

void	rotate_stacks(t_game *game, int *times_a, int *times_b, int direction);
void	rotate_a(t_game *game, int times, int direction);
void	rotate_b(t_game *game, int times, int direction);
void	move_to_min(t_game *game, int min);
void	move_to_insert_position(t_game *game, int v);

/* _____________________________ stack_utils.c ______________________________ */

int		is_sorted(t_list *stack);
int		get_index(t_list *stack, int v);
int		find_insert_position(t_list *stack, int v);

/* _________________________________ type.c _________________________________ */

void	set_type(int type);
int		get_type(void);

/* ________________________________ utils.c _________________________________ */

t_list	*ft_lstpreviouslast(t_list *lst);
void	free_game(t_game *game);
void	free_value(void *v);
int		val(t_list *stack);

#endif
