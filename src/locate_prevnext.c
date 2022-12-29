/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_prevnext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:58:55 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/28 17:06:22 by jenavarr         ###   ########.fr       */
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
