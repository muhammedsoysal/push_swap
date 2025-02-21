/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:02:15 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/17 18:01:48 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_node **src, t_node **dst, char *operation)
{
	t_node	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp -> next = *dst;
	*dst = tmp;
	ft_putendl_fd(operation, 1);
}
