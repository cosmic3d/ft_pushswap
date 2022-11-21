/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:43:06 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/21 14:37:01 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->first;
	if (stack->len == 2)
		stack->last = tmp;
	stack->first = tmp->next;
	stack->first->back = NULL;
	tmp->next = stack->first->next;
	stack->first->next = tmp;
	tmp->back = stack->first;
	return ;
}

void	swapswap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return ;
}