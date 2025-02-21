/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 00:15:32 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 16:09:19 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two(t_node **a)
{
	sa(a);
}

static void	sort_three(t_node **a)
{
	t_node	*cur;
	int		min;
	int		second_min;

	cur = NULL;
	cur = *a;
	min = get_min_index(a, -1);
	second_min = get_min_index(a, min);
	if (cur->index == min && cur->next->index != second_min)
		(sa(a), ra(a));
	else if (cur->index == second_min)
	{
		if (cur->next->index != min)
			rra(a);
		else
			sa(a);
	}
	else
	{
		if (cur->next->index == min)
			ra(a);
		else
			(sa(a), rra(a));
	}
}

static void	sort_four(t_node **a, t_node **b)
{
	int	min_pos;

	min_pos = find_index_position(a, get_min_index(a, -1));
	if (min_pos == 1)
		ra(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra(a);
	if (!is_sorted(a))
	{
		push(a, b, "pb");
		sort_three(a);
		push(b, a, "pa");
	}
}

static void	sort_five(t_node **a, t_node **b)
{
	int	position;

	position = find_index_position(a, get_min_index(a, -1));
	if (position == 1)
		ra(a);
	else if (position == 2)
	{
		ra(a);
		ra(a);
	}
	else if (position == 3)
	{
		rra(a);
		rra(a);
	}
	else if (position == 4)
		rra(a);
	if (!is_sorted(a))
	{
		push(a, b, "pb");
		sort_four(a, b);
		push(b, a, "pa");
	}
}

void	ft_sort(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b, size);
}
