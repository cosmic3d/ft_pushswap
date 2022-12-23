/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:03:26 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/23 19:54:35 by jenavarr         ###   ########.fr       */
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
	stack->last->next = stack->first;
	stack->first = stack->first->next;
	stack->first->back = NULL;
	stack->last = tmp_first;
	stack->last->next = NULL;
	stack->last->back = tmp_last;
	tmp_last->next = stack->last;
	return ;
}

void	rotate_a(t_stack *a, t_stack *b)
{
	rotate(a);
	if (ft_printf("%s", RA) == -1)
		ft_error(a, b);
	return ;
}

void	rotate_b(t_stack *a, t_stack *b)
{
	rotate(b);
	if (ft_printf("%s", RB) == -1)
		ft_error(a, b);
	return ;
}

void	rotaterotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	if (ft_printf("%s", RR) == -1)
		ft_error(a, b);
	return ;
}
