/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:21:05 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/16 20:45:14 by jenavarr         ###   ########.fr       */
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
		push_b(a, b);
	push_b(a, b);
	three_random(a, b);
}

// int	how_push(t_stack *a, t_node *node)
// {
	
// }
