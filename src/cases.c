/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:28:22 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/27 19:45:48 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	few_swap(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		s1;
	int		s2;

	s1 = smaller_1(a, -1);
	s2 = smaller_1(a, s1);
	if (a->len == 2)
	{
		if (a->first->val > a->first->next->val)
			swap_s(a, b);
		return (1);
	}
	if (s2 != a->first->index || s1 != a->first->next->index)
		return (0);
	if (a->first->next->next && a->first->val > a->first->next->next->val)
		return (0);
	tmp = a->first->next->next;
	while (tmp->index != a->last->index)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	swap_s(a, b);
	return (1);
}

int	few_rotate(t_stack *a, t_stack *b, t_node *smaller)
{
	t_node	*tmp;

	tmp = smaller;
	if (smaller->index == 0 || smaller->back->index != bigger_1(a, -1))
		return (0);
	while (tmp->index != bigger_1(a, -1))
	{
		if (tmp->index == a->last->index)
		{
			if (tmp->val > a->first->val)
				return (0);
			tmp = a->first;
		}
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
		if (tmp->index == a->last->index)
		{
			if (tmp->val > a->first->val)
				return (0);
			tmp = a->first;
		}
	}
	return (do_rotate(a, b, smaller->index));
}

int	do_rotate(t_stack *a, t_stack *b, int index)
{
	if (index <= a->len / 2)
	{
		while (index != a->first->index)
			rotate_s(a, b);
		return (1);
	}
	while (index != a->first->index)
		reverse_rotate_s(a, b);
	return (1);
}
