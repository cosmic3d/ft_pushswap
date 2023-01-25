/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_prevnext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:58:55 by jenavarr          #+#    #+#             */
/*   Updated: 2023/01/25 21:54:51 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	next_1(t_stack *s, int index)
{
	int		val;
	int		next;
	t_node	*tmp;

	if (get_node(s, index))
		val = get_node(s, index)->val;
	if (index >= s->len || val == get_node(s, bigger_1(s, -1))->val)
		return (bigger_1(s, -1));
	next = -1;
	tmp = s->first;
	while (next == -1 && tmp)
	{
		if (tmp->val > val)
			next = tmp->index;
		tmp = tmp->next;
	}
	tmp = s->first;
	while (tmp)
	{
		if (tmp->val > val && tmp->val < get_node(s, next)->val)
			next = tmp->index;
		tmp = tmp->next;
	}
	return (next);
}

int	prev_1(t_stack *s, int index)
{
	int		val;
	int		next;
	t_node	*tmp;

	if (get_node(s, index))
		val = get_node(s, index)->val;
	if (index >= s->len || val == get_node(s, smaller_1(s, -1))->val)
		return (smaller_1(s, -1));
	next = -1;
	tmp = s->first;
	while (next == -1 && tmp)
	{
		if (tmp->val < val)
			next = tmp->index;
		tmp = tmp->next;
	}
	tmp = s->first;
	while (tmp)
	{
		if (tmp->val < val && tmp->val > get_node(s, next)->val)
			next = tmp->index;
		tmp = tmp->next;
	}
	return (next);
}

t_node	*closers_1(t_stack *s, t_node *biggest)
{
	t_node	*b2;
	t_node	*b3;
	t_node	*c1;

	c1 = biggest;
	b2 = get_num_in_pos(s, biggest->final_index - 1);
	b3 = get_num_in_pos(s, biggest->final_index - 2);
	if (how_many_moves(c1->index, s->len) > how_many_moves(b2->index, s->len))
		c1 = b2;
	if (how_many_moves(c1->index, s->len) > how_many_moves(b3->index, s->len))
		c1 = b3;
	return (c1);
}
