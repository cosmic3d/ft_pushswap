/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:03:26 by jenavarr          #+#    #+#             */
/*   Updated: 2023/02/20 16:28:33 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/checker.h"

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
	stack->last->next = stack->first;
	stack->first = stack->first->next;
	stack->first->back = NULL;
	stack->last = tmp_first;
	stack->last->next = NULL;
	stack->last->back = tmp_last;
	tmp_last->next = stack->last;
	return ;
}

void	rotaterotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	return ;
}
