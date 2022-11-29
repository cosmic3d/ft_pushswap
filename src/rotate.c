/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:03:26 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/29 14:31:45 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp_first;
	t_node	*tmp_last;

	if (stack->len < 2)
		return ;
	if (stack->len == 2)
		return (swap(stack));
	tmp_first = stack->first;
	tmp_last = stack->last;
	stack->last = stack->last->back;
	stack->last->next = NULL;
	stack->first = tmp_last;
	stack->first->back = NULL;
	stack->first->next = tmp_first;
	stack->first->next->back = stack->first;
	return ;
}

void	rotaterotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	return ;
}