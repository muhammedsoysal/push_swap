/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:01:44 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 15:17:04 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static t_node	*get_next_min(t_node **stack)
{
	t_node	*current;
	t_node	*min;
	int		real_min;

	min = NULL;
	real_min = 0;
	current = *stack;
	while (current)
	{
		if ((current->index == -1)
			&& (!real_min || current->value < min->value))
		{
			min = current;
			real_min = 1;
		}
		current = current->next;
	}
	return (min);
}

static void	assign_index(t_node **stack)
{
	t_node	*current;
	int		index;

	index = 0;
	current = get_next_min(stack);
	while (current)
	{
		current->index = index++;
		current = get_next_min(stack);
	}
}

static void	fill_stack(t_node **stack, char **argv)
{
	t_node	*current;
	int		i;

	i = 0;
	if (!argv || !argv[i])
		handle_error();
	*stack = malloc(sizeof(t_node));
	if (!*stack)
		return ;
	current = *stack;
	while (argv[i])
	{
		current->value = ft_atoi(argv[i]);
		current->index = -1;
		if (argv[i + 1])
		{
			current->next = malloc(sizeof(t_node));
			if (!current->next)
				(free(stack), handle_error());
			current = current->next;
			current->next = NULL;
		}
		i++;
	}
	assign_index(stack);
}

static int	process_arguments(int argc, char *argv[], char ***args)
{
	*args = get_arguments(argc, argv);
	if (!(*args) || !(*args)[0])
		return (charfree(*args), handle_error(), 1);
	if (!check_invalid_arguments(argc, argv, -1))
	{
		if (argc == 2)
			charfree(*args);
		return (handle_error(), 1);
	}
	return (argc == 2);
}

int	main(int argc, char *argv[])
{
	t_node	**a;
	t_node	**b;
	char	**args;
	int		args_allocated;

	if (argc < 2)
		return (0);
	args_allocated = process_arguments(argc, argv, &args);
	a = (t_node **)malloc(sizeof(t_node *));
	b = (t_node **)malloc(sizeof(t_node *));
	if (!a || !b)
		return (free_stack(a), free_stack(b), 1);
	*a = NULL;
	*b = NULL;
	if (argc == 2)
		args_allocated = 1;
	fill_stack(a, args);
	if (is_sorted(a))
		return (cleanup(a, b, args, args_allocated), 0);
	ft_sort(a, b, ft_lstsize(*a));
	return (cleanup(a, b, args, args_allocated), 0);
}
