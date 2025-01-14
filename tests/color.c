/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:49:21 by lroussel          #+#    #+#             */
/*   Updated: 2025/01/10 13:49:22 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	green(int fd)
{
	ft_putstr_fd("\033[0;32m", fd);
}

void	red(int fd)
{
	ft_putstr_fd("\033[0;31m", fd);
}

void	light_blue(int fd)
{
	ft_putstr_fd("\033[1;34m", fd);
}

void	reset(int fd)
{
	ft_putstr_fd("\033[0m", fd);
}
