/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:43:06 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/18 22:34:56 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->len < 2)
		return ;
	tmp = stack->first->next;
	if (stack->len == 2)
		stack->last = stack->first;
	if (stack->first->next->next)
		stack->first->next->next->back = stack->first;
	stack->first->next = stack->first->next->next;
	stack->first->back = tmp;
	tmp->next = stack->first;
	tmp->back = NULL;
	stack->first = tmp;
	return ;
}

void	swap_a(t_stack *a, t_stack *b)
{
	swap(a);
	if (ft_printf("%s", SA) == -1)
		ft_error(a, b);
	return ;
}

void	swap_b(t_stack *a, t_stack *b)
{
	swap(b);
	if (ft_printf("%s", SB) == -1)
		ft_error(a, b);
	return ;
}

void	swapswap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (ft_printf("%s", SS) == -1)
		ft_error(a, b);
	return ;
}

void	choose_swap(t_stack *a, t_stack *b)
{
	if (b->first->val < b->first->next->val)
		return (swapswap(a, b));
	return (swap_a(a, b));
}
