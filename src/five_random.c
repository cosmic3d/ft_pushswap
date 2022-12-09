/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:21:05 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/09 23:13:00 by jenavarr         ###   ########.fr       */
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

void	five_random(t_stack *a, t_stack *b)
{
	if (a->len == 5)
		push_b(a, b);
	push_b(a, b);
	three_random(a, b);
	
}

//Crear función para obtener el índice de los dos números más pequeños
//Crear función para encontrar la ruta con menos movimientos según su índice para pushearlos
