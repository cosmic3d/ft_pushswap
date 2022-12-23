/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:00:06 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/23 19:55:32 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	push(t_stack *dest, t_stack *ori)
{
	t_node	*tmp_dest;
	t_node	*tmp_ori;

	if (!ori->len)
		return ;
	tmp_ori = ori->first;
	ori->first = ori->first->next;
	if (ori->first)
		ori->first->back = NULL;
	tmp_dest = dest->first;
	dest->first = tmp_ori;
	dest->first->next = tmp_dest;
	if (dest->first->next)
		dest->first->next->back = dest->first;
	dest->len++;
	ori->len--;
	first_last(dest->first, dest, ori->first, ori);
	return ;
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, b);
	if (ft_printf("%s", PA) == -1)
		ft_error(a, b);
	return ;
}

void	push_b(t_stack *a, t_stack *b)
{
	push(b, a);
	if (ft_printf("%s", PB) == -1)
		ft_error(a, b);
	return ;
}

void	how_push(t_stack *a, t_stack *b, int node, int brother)
{
	if (!node)
		return (push_b(a, b));
	if (node == 1 && a->len - 1 == brother)
	{
		swap_a(a, b);
		return (push_b(a, b));
	}
	if (node <= a->len / 2)
	{
		while (a->first->index != node)
			rotate_a(a, b);
		return (push_b(a, b));
	}
	while (a->first->index != node)
		reverse_rotate_a(a, b);
	return (push_b(a, b));
}
