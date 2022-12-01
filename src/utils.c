/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:26:47 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/01 14:13:27 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	empty_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->first)
	{
		tmp = stack->first->next;
		free(stack->first);
		stack->first = tmp;
	}
	stack = NULL;
	return ;
}

void	first_last(t_node *node, t_stack *stack)
{
	stack->first = node;
	stack->last = node;
	node->back = NULL;
	node->next = NULL;
	return ;
}

void	ft_error(t_stack *a, t_stack *b)
{
	empty_stack(a);
	empty_stack(b);
	write(1, "Error\n", 6);
	exit(0);
}
