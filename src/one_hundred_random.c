/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_hundred_random.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:08:03 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/28 20:24:31 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	one_hundred_random(t_stack *a, t_stack *b, int chunk_size)
{
	if (few_swap(a, b) || few_rotate(a, b, get_node(a, smaller_1(a, -1))))
		return ;
	while (a->len > 0)
		send_to_b(a, b, v(a, get_num_in_pos(a, chunk_size - 1)));
	while (b->len > 2)
	{
		reindex(b);
		back_to_a(a, b, bigger_1(b, -1), bigger_1(b, bigger_1(b, -1)));
	}
	push_s(a, b);
	push_s(a, b);
	if (!ft_is_ordered(a))
		return (swap_s(a, b));
}

void	send_to_b(t_stack *a, t_stack *b, int t)
{
	while (a->len > 0 && v(a, smaller_1(a, -1)) <= t)
	{
		if (a->first->val <= t)
		{
			push_s(b, a);
			reindex(a);
			continue ;
		}
		rotate_s(a, b);
		reindex(a);
	}
}

void	back_to_a(t_stack *a, t_stack *b, int b1, int b2)
{
	t_node	*t;
	t_node	*t2;
	t_node	*t3;
	int		tmp;

	t2 = closer_1(b1, b2, b, 0);
	t3 = closer_1(b1, b2, b, 1);
	t = closer_1(t2->index, prev_1(b, b2), b, 0);
	t2 = closer_1(t2->index, prev_1(b, b2), b, 1);
	tmp = t2->index;
	t2 = closer_1(t2->index, t3->index, b, 0);
	t3 = closer_1(tmp, t3->index, b, 1);
	how_push(a, b, t->index, -1);
	how_push(a, b, t2->index, -1);
	how_push(a, b, t3->index, -1);
	sort_top(a, b, smaller_1(a, -1));
	return ;
}

void	sort_top(t_stack *a, t_stack *b, int s1)
{
	t_node	*s2;

	if (ft_is_ordered(a))
		return ;
	s2 = get_node(a, next_1(a, s1));
	if (s1 == 0)
	{
		rotate_s(a, b);
		swap_s(a, b);
		return (reverse_rotate_s(a, b));
	}
	if (s1 == 2 && s2->index == 0)
	{
		push_s(b, a);
		swap_s(a, b);
		rotate_s(a, b);
		push_s(a, b);
		return (reverse_rotate_s(a, b));
	}
	else if (s1 == 1 && s2->index == 0)
		return (swap_s(a, b));
	return (sort_top_2(a, b, s1));
}

void	sort_top_2(t_stack *a, t_stack *b, int s1)
{
	if (s1 == 1)
	{
		swap_s(a, b);
		rotate_s(a, b);
		swap_s(a, b);
		return (reverse_rotate_s(a, b));
	}
	rotate_s(a, b);
	rotate_s(a, b);
	push_s(b, a);
	reverse_rotate_s(a, b);
	reverse_rotate_s(a, b);
	swap_s(a, b);
	return (push_s(a, b));
}
