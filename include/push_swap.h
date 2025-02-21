/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:49:46 by musoysal          #+#    #+#             */
/*   Updated: 2025/02/21 17:01:39 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "../lib/Libft/libft.h"
# include "../lib/printf/ft_printf.h"

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
}	t_node;

int		has_duplicates(char **argv);
int		check_invalid_arguments(int argc, char **argv, int i);
char	**get_arguments(int argc, char **argv);
int		validate_argument(char *arg);
int		ft_lstsize(t_node *lst);
int		is_sorted(t_node **stack);
void	push(t_node **src, t_node **dst, char *operation);
void	rra(t_node **a);
void	ra(t_node **a);
void	sa(t_node **a);
int		get_min_index(t_node **stack, int value);
int		find_index_position(t_node **stack, int index);
void	ft_sort(t_node **a, t_node **b, int size);
void	radix_sort(t_node **a, t_node **b, int size);
void	handle_error(void);
void	free_stack(t_node **stack);
void	cleanup(t_node **a, t_node **b, char **args, int args_allocated);
void	charfree(char **str);
#endif
