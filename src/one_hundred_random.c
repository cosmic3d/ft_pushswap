/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_hundred_random.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:08:03 by jenavarr          #+#    #+#             */
/*   Updated: 2023/01/25 22:15:59 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	one_hundred_random(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;

	i = 1;
	if (few_swap(a, b) || few_rotate(a, b, get_node(a, smaller_1(a, -1))))
		return ;
	while (a->len > 0)
	{
		send_to_b(a, b, get_num_in_pos(a, (chunk_size * i) - 1));
		i++;
	}
	// debug_stack(b);
	// debug_stack(a);
	// exit(1);
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

void	send_to_b(t_stack *a, t_stack *b, t_node *t)
{
	while (a->len > 0 && v(a, smaller_1(a, -1)) <= t->val)
	{
		if (a->first->val <= t->val)
		{
			push_s(b, a);
			if (b->first->final_index < t->final_index / 2 && b->len > 2)
				rotate_s(b, a);
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

	// t = closers_1(b, b1);
	// t2 = closer_1(bigger_1(b, -1), bigger_1(b, bigger_1(b, -1)), b, 0);
	// t3 = closer_1(bigger_1(b, -1), bigger_1(b, bigger_1(b, -1)), b, 1);
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

// void	back_to_a(t_stack *a, t_stack *b, t_node *b1)
// {
// 	t_node	*t;
// 	t_node	*t2;
// 	t_node	*t3;

// 	t = closers_1(b, b1);
// 	how_push(a, b, t->index, -1);
// 	t2 = closer_1(bigger_1(b, -1), bigger_1(b, bigger_1(b, -1)), b, 0);
// 	t3 = closer_1(bigger_1(b, -1), bigger_1(b, bigger_1(b, -1)), b, 1);
// 	if (t->final_index < t2->final_index && t->final_index < t3->final_index)
// 		return (smallest_first(a, b, t2, t3));
// 	smallest2_first(a, b, t2, t3);
// 	if (t->final_index < t2->final_index && t->final_index < t3->final_index)
// 	{
// 		how_push(a, b, t2->index, -1);
// 		how_push(a, b, t3->index, -1);
// 	}
// 	if (!ft_is_ordered(a))
// 		swap_s(a, b);
// 	return ;
// }

// void	smallest2_first(t_stack *a, t_stack *b, t_node *t2, t_node *t3)
// {
// 	int	n;

// 	n = a->first->final_index;
// 	if (n > t2->final_index && n > t3->final_index)
// 		return ;
// 	how_push(a, b, t2->index, -1);
// 	if (t2->final_index < t2->next->final_index)
// 	{
// 		rotate_s(a, b);
// 		how_push(a, b, t3->index, -1);
// 		swap_s(a, b);
// 		return (reverse_rotate_s(a, b));
// 	}
// 	swap_s(a, b);
// 	return (how_push(a, b, t3->index, -1));
// }

// void	smallest_first(t_stack *a, t_stack *b, t_node *t2, t_node *t3)
// {
// 	rotate_s(a, b);
// 	how_push(a, b, t2->index, -1);
// 	how_push(a, b, t3->index, -1);
// 	if (t2->final_index < t3->final_index)
// 		swap_s(a, b);
// 	reverse_rotate_s(a, b);
// }

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
