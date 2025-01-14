/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lroussel <lroussel@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/13 10:07:09 by lroussel		  #+#	#+#			 */
/*   Updated: 2025/01/14 12:57:56 by lroussel         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "checker.h"

int	on_command(t_game *game, char *command)
{
	if (ft_strncmp(command, "pa\n", 3) == 0)
		pa(game);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		pb(game);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ra(game);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		rb(game);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		rr(game);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		rra(game);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		rrb(game);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		rrr(game);
	else if (ft_strncmp(command, "sa\n", 3) == 0)
		sa(game);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		sb(game);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ss(game);
	else
		return (0);
	return (1);
}

int	check_command(t_game *game, char **buffer, int *total)
{
	if (*buffer && (*buffer)[*total - 1] == '\n')
	{
		if (!on_command(game, *buffer))
		{
			free(*buffer);
			return (0);
		}
		free(*buffer);
		*buffer = NULL;
		*total = 0;
	}
	return (1);
}

int	listen(t_game *game)
{
	char	*buffer;
	int		byte_read;
	int		total;

	buffer = malloc(1);
	if (!buffer)
		return (0);
	byte_read = 0;
	total = 0;
	while (byte_read != -1)
	{
		buffer = ft_realloc(buffer, total, total + 2);
		if (!buffer)
			return (0);
		byte_read = read(0, buffer + total, 1);
		if (byte_read > 0)
			total += byte_read;
		if (byte_read == 0 || (total > 0 && buffer[total - 1] == '\0'))
			break ;
		if (!check_command(game, &buffer, &total))
			return (0);
	}
	free(buffer);
	return (1);
}

int	check(t_game *game)
{
	if (!listen(game))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (is_sorted(game->a) && !(game->b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		res;

	if (argc == 1)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (2);
	game->a = parse(argv + 1);
	if (!game->a)
	{
		ft_putstr_fd("Error\n", 2);
		free(game);
		return (3);
	}
	game->b = NULL;
	set_type(CHECKER);
	res = check(game);
	free_game(game);
	if (!res)
		return (4);
	return (0);
}
