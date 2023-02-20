/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:32:32 by jenavarr          #+#    #+#             */
/*   Updated: 2023/02/20 16:28:13 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/checker.h"

void	reverse_rotate(t_stack *stack)
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

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return ;
}
