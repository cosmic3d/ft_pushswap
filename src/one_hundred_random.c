/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_hundred_random.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:08:03 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/26 18:55:06 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	one_hundred_random(t_stack *a, t_stack *b, int chunk_size)
{
	int	tmp;

	while (a->len > 0)
	{
		tmp = v(a, get_num_in_pos(a, chunk_size - 1));
		while (a->len > 0 && v(a, smaller_1(a, -1)) <= tmp)
		{
			if (a->first->val <= tmp)
			{
				push_b(a, b);
				reindex(a);
				continue ;
			}
			rotate_a(a, b);
			reindex(a);
		}
	}
	while (b->len > 0)
	{
		reindex(b);
		how_push(a, b, bigger_1(b), -1);
	}
}

int	get_num_in_pos(t_stack *s, int pos)
{
	int	i;
	int	index;

	i = 0;
	index = smaller_1(s, -1);
	while (i++ < pos && index != bigger_1(s))
		index = next_1(s, index);
	return (index);
}
