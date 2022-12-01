/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:03:26 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/01 14:23:14 by jenavarr         ###   ########.fr       */
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

void	rotate_a(t_stack *a, t_stack *b)
{
	rotate(a);
	if (ft_printf("%s", RA) == -1)
		return (ft_error(a, b));
}

void	rotate_b(t_stack *b, t_stack *a)
{
	rotate(b);
	if (ft_printf("%s", RB) == -1)
		return (ft_error(a, b));
}

void	rotaterotate(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	rotate_b(b, a);
	return ;
}