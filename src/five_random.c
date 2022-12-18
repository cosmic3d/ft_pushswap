/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:21:05 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/18 20:47:06 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	three_random(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		if (a->first->val > a->last->val)
			return (swap_a(a, b));
	if (a->last->val > a->first->val && a->last->val > a->first->next->val)
		return (swap_a(a, b));
	if (a->last->back->val < a->last->val && a->last->val < a->first->val)
		return (reverse_rotate_a(a, b));
	if (a->first->val > a->last->back->val && a->last->back->val > a->last->val)
	{
		swap_a(a, b);
		return (rotate_a(a, b));
	}
	if (a->last->back->val > a->last->val && a->last->back->val > a->first->val)
	{
		if (a->first->val < a->last->val)
		{
			swap_a(a, b);
			return (reverse_rotate_a(a, b));
		}
	}
	if (a->last->val < a->first->val && a->first->val < a->last->back->val)
		return (rotate_a(a, b));
}
//1- Comprobamos si el stack se halla semiordenado o a varias iteraciones de un movimiento de ordenarse
//2- Buscamos la manera más rápida de ordenar el stack, que es pusheando los dos más pequeños o el más pequeño y el más grande.
//3- Realizamos las aciones indicadas por otra función que dictará qué elementos pushear
//4- Una vez pusheados, llamamos a la función three_random para ordenar esa pareja y consecuentemente traemos a los dos de stack b

void	five_random(t_stack *a, t_stack *b)
{
	if (a->len == 5)
	{
		
		return ;
	}
	how_push(a, b, closer_1(check_smaller(a, -1), check_bigger(a), a->len, 0));
	three_random(a, b);
	push_a(a, b);
	if (!ft_is_ordered(a))
		reverse_rotate_a(a, b);
}

void	how_push(t_stack *a, t_stack *b, int node)
{
	int	smaller;

	smaller = check_smaller(a, -1);
	if (!node)
		return (push_b(a, b));
	if (node == 1 && check_smaller(a, smaller) == a->len - 1)
	{
		swap_a(a, b);
		return (push_b(a, b));
	}
	if (node <= a->len / 2)
	{
		while (a->first->index != node)
			reverse_rotate_a(a, b);
		return (push_b(a, b));
	}
	while (a->first->index != node)
		rotate_a(a, b);
	return (push_b(a, b));
}
