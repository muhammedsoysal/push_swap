/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:37:48 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 16:54:08 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_valid_number(char *argv)
{
	int	i;

	i = 0;
	if (!argv[i])
		return (0);
	if ((argv[i] == '-' || argv[i] == '+'))
		i++;
	if (!ft_isdigit(argv[i]))
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	i;
	long	result;

	i = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * i);
}

static int	count_arg(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	validate_argument(char *arg)
{
	return (ft_strlen(arg) < 12 && is_valid_number(arg)
		&& (ft_atol(arg) >= INT_MIN && ft_atol(arg) <= INT_MAX));
}

int	has_duplicates(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
