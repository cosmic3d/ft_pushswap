/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:32:32 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/05 14:04:36 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

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
	stack->first = stack->first->next;
	stack->first->back = NULL;
	stack->last = tmp_first;
	stack->last->next = NULL;
	stack->last->back = tmp_last;
	tmp_last->next = stack->last;
	return ;
}

void	reverse_rotate_a(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	if (ft_printf("%s", RRA) == -1)
		ft_error(a, b);
	return ;
}

void	reverse_rotate_b(t_stack *a, t_stack *b)
{
	reverse_rotate(b);
	if (ft_printf("%s", RRB) == -1)
		ft_error(a, b);
	return ;
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (ft_printf("%s", RRR) == -1)
		ft_error(a, b);
	return ;
}
