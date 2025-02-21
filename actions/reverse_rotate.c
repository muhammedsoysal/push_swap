/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 00:15:18 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 17:00:12 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate(t_node **stack, char *operation)
{
	t_node	*last;
	t_node	*second_last;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		second_last = *stack;
		while (last->next)
		{
			second_last = last;
			last = last->next;
		}
		second_last->next = NULL;
		last->next = *stack;
		*stack = last;
		ft_putendl_fd(operation, 1);
	}
}

void	rra(t_node **a)
{
	reverse_rotate(a, "rra");
}
