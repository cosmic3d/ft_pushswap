/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_hundred_random.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:08:03 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/23 19:01:52 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	one_hundred_random(t_stack *a, t_stack *b)
{
	while (a->len > 0)
	{
		reindex(a);
		how_push(a, b, smaller_1(a, -1), -1);
	}
	while (b->len > 0)
		push_a(a, b);
}
