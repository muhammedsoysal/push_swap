/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:39:24 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 16:53:48 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && !str[i])
			return (1);
		i++;
	}
	return (0);
}

char	**get_arguments(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_spaces(argv[1]) || !argv[1])
			return (NULL);
		return (ft_split(argv[1], ' '));
	}
	return (argv + 1);
}

int	check_invalid_arguments(int argc, char **argv, int i)
{
	char	**parsed_args;
	int		needs_free;

	parsed_args = get_arguments(argc, argv);
	if (!parsed_args)
		return (0);
	needs_free = (argc == 2);
	while (parsed_args[++i])
	{
		if (!validate_argument(parsed_args[i]))
		{
			if (needs_free)
				charfree(parsed_args);
			return (0);
		}
	}
	if (has_duplicates(parsed_args))
	{
		if (needs_free)
			charfree(parsed_args);
		return (0);
	}
	if (needs_free)
		charfree(parsed_args);
	return (1);
}
