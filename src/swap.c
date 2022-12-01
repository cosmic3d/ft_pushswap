/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:43:06 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/01 14:17:36 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
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

void	swap_a(t_stack *a, t_stack *b)
{
	swap(a);
	if (ft_printf("%s", SA) == -1)
		return (ft_error(a, b));
}

void	swap_b(t_stack *b, t_stack *a)
{
	swap(b);
	if (ft_printf("%s", SB) == -1)
		return (ft_error(a, b));
}

void	swapswap(t_stack *a, t_stack *b)
{
	swap_a(a, b);
	swap_b(b, a);
	return ;
}
