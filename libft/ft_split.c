/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroussel <lroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:59:09 by lroussel          #+#    #+#             */
/*   Updated: 2024/11/07 18:37:38 by lroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **splited, unsigned int max)
{
	unsigned int	i;

	i = 0;
	while (i < max)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

static char	*split_next_word(char const *s, char c, char ***res, unsigned int p)
{
	char	*word;

	word = ft_get_first_word(s, &c);
	if (!word)
	{
		free_all(*res, p);
		return (NULL);
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	i;
	unsigned int	j;

	res = malloc(sizeof(char *) * (ft_count_words(s, &c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		while (ft_strchr(&c, s[i]))
			i++;
		if (i < ft_strlen(s))
		{
			res[j] = split_next_word(s + i, c, &res, j);
			if (!res[j])
				return (NULL);
			i += ft_strlen(res[j]) + 1;
			j++;
		}
	}
	res[j] = 0;
	return (res);
}
