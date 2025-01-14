/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:44:51 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/08 13:10:17 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	success(int number, char *details)
{
	green(1);
	ft_putnbr_fd(number, 1);
	ft_putstr_fd(". [OK] ", 1);
	ft_putstr_fd(details, 1);
	ft_putchar_fd('\n', 1);
	reset(1);
	return (1);
}

int	fail(int number, char *details)
{
	red(2);
	ft_putnbr_fd(number, 2);
	ft_putstr_fd(". [KO] ", 2);
	ft_putstr_fd(details, 2);
	ft_putchar_fd('\n', 1);
	reset(2);
	return (0);
}

void	center(char *title, char c)
{
	int	characters;
	int	i;

	characters = 40 - (2 * (title[0] != '\0')) - ft_strlen(title);
	i = characters / 2 + characters % 2;
	while (i--)
		ft_putchar_fd(c, 1);
	if (title[0])
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(title, 1);
	if (title[0])
		ft_putchar_fd(' ', 1);
	i = characters / 2;
	while (i--)
		ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	test_name(char *name)
{
	light_blue(1);
	ft_putstr_fd("> ", 1);
	ft_putstr_fd(name, 1);
	reset(1);
}

void	malloc_fail(t_game *game)
{
	red(2);
	ft_putstr_fd("Malloc Fail !\n", 2);
	reset(2);
	free_game(game);
	exit(EXIT_FAILURE);
}
