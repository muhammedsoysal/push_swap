/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:55:23 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/20 18:13:54 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_index_position(t_node **stack, int index)
{
	t_node	*node;
	int		position;

	position = 0;
	node = *stack;
	while (node)
	{
		if (node->index == index)
			break ;
		position++;
		node = node->next;
	}
	return (position);
}

int	get_min_index(t_node **stack, int value)
{
	t_node	*current;
	int		min;

	current = *stack;
	min = current->index;
	while (current->next != NULL)
	{
		current = current->next;
		if ((current->index < min) && current->index != value)
			min = current->index;
	}
	return (min);
}

void	charfree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		exit(0);
	while (str[i])
	{
		free(str[i++]);
	}
	free(str);
}

void	cleanup(t_node **a, t_node **b, char **args, int args_allocated)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	if (args_allocated)
		charfree(args);
}

int	is_sorted(t_node **stack)
{
	t_node	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
