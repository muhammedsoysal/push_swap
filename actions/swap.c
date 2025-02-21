/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:19:53 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 17:00:29 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}
