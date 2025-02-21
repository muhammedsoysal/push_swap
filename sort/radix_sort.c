/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:29:23 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 16:18:24 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_node **a)
{
	t_node	*head;
	int		max_bits;
	int		max;

	head = *a;
	max_bits = 0;
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **a, t_node **b, int size)
{
	int		max_bits;
	int		bit_pos;
	int		stack_size;
	t_node	*tmp;
	int		i;

	bit_pos = 0;
	stack_size = size;
	max_bits = get_max_bits(a);
	while (bit_pos < max_bits)
	{
		i = 0;
		while (i < stack_size)
		{
			tmp = *a;
			if (((tmp->index >> bit_pos) & 1) == 0)
				push(a, b, "pb");
			else
				ra(a);
			i++;
		}
		while (*b)
			push(b, a, "pa");
		bit_pos++;
	}
}
