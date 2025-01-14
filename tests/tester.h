/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:30:19 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/10 12:03:24 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "push_swap.h"
# include <stdarg.h>

/* __________________________ actions/push_tests.c __________________________ */

int		pa_tests(t_game *game);
int		pb_tests(t_game *game);

/* _____________________ actions/reverse_rotate_tests.c _____________________ */

int		rra_tests(t_game *game);
int		rrb_tests(t_game *game);
int		rrr_tests(t_game *game);

/* _________________________ actions/rotate_tests.c _________________________ */

int		ra_tests(t_game *game);
int		rb_tests(t_game *game);
int		rr_tests(t_game *game);

/* __________________________ actions/swap_tests.c __________________________ */

int		sa_tests(t_game *game);
int		sb_tests(t_game *game);

/* ________________________________ colors.c ________________________________ */

void	green(int fd);
void	red(int fd);
void	light_blue(int fd);
void	reset(int fd);

/* __________________________ stack_initializer.c ___________________________ */

void	init_stack(t_list **stack, int scale, ...);
int		stack_equals(t_list *stack, int scale, ...);

/* ________________________________ tester.c ________________________________ */

int		action_tests(t_game *game, void (*act)(t_game *),
			int (test)(t_game *, t_game *, void *), int n);

/* ________________________________ utils.c _________________________________ */

int		success(int number, char *details);
int		fail(int number, char *details);
void	center(char *title, char c);
void	test_name(char *name);
void	malloc_fail(t_game *game);

#endif
