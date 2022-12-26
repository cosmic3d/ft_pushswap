/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:15:39 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/26 18:24:34 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

t_node	*get_node(t_stack *s, int index)
{
	t_node	*tmp;

	if (index >= s->len)
		return (get_node(s, bigger_1(s)));
	tmp = s->first;
	while (tmp)
	{
		if (tmp->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	smaller_1(t_stack *stack, int exclude)
{
	t_node	*smaller;
	t_node	*tmp;

	if (!stack->first)
		return (-1);
	tmp = stack->first;
	smaller = stack->first;
	if (smaller->index == exclude)
	{
		tmp = stack->first->next;
		smaller = stack->first->next;
	}
	while (tmp->next)
	{
		if (tmp->next->val < smaller->val && tmp->next->index != exclude)
			smaller = tmp->next;
		tmp = tmp->next;
	}
	return (smaller->index);
}

int	bigger_1(t_stack *stack)
{
	t_node	*bigger;
	t_node	*tmp;

	if (!stack->first)
		return (-1);
	tmp = stack->first;
	bigger = stack->first;
	while (tmp->next)
	{
		if (tmp->next->val > bigger->val)
			bigger = tmp->next;
		tmp = tmp->next;
	}
	return (bigger->index);
}

int	closer_1(int one, int two, int len, int inverted)
{
	int	tmp_one;
	int	tmp_two;

	tmp_one = ft_abs(how_many_moves(one, len));
	tmp_two = ft_abs(how_many_moves(two, len));
	if (inverted)
	{
		if (closer_1(one, two, len, 0) == one)
			return (two);
		return (one);
	}
	if (tmp_one == tmp_two)
	{
		if (one <= len / 2)
			return (one);
		return (two);
	}
	if (tmp_one < tmp_two)
		return (one);
	return (two);
}

int	next_1(t_stack *s, int index)
{
	int		val;
	int		next;
	t_node	*tmp;

	if (get_node(s, index))
		val = get_node(s, index)->val;
	if (index >= s->len || val == get_node(s, bigger_1(s))->val)
		return (bigger_1(s));
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
