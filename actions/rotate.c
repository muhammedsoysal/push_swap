/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:35:55 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 17:00:23 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_node **stack, char *operation)
{
	t_node	*first;
	t_node	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		*stack = (*stack)->next;
		last->next = first;
		first->next = NULL;
		ft_putendl_fd(operation, 1);
	}
}

void	ra(t_node **a)
{
	rotate(a, "ra");
}
