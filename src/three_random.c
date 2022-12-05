/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:21:05 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/05 11:25:46 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	three_random(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		return (two(a, b));
	if (a->last->val > a->first->val && a->last->val > a->first->next->val)
		return (swap_a(a, b));
	if (a->last->back->val < a->last->val && a->last->val < a->first->val)
		return (rotate_a(a, b));
	if (a->first->val > a->last->back->val && a->last->back->val > a->last->val)
	{
		swap_a(a, b);
		return (reverse_rotate_a(a, b));
	}
}

void	two(t_stack *a, t_stack *b)
{
	if (a->first->val > a->last->val)
		return (swap_a(a, b));
	return ;
}
