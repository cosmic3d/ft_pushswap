/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:15:39 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/29 16:32:03 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

t_node	*get_node(t_stack *s, int index)
{
	t_node	*tmp;

	if (index >= s->len)
		return (get_node(s, bigger_1(s, -1)));
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

int	bigger_1(t_stack *stack, int exclude)
{
	t_node	*bigger;
	t_node	*tmp;

	if (!stack->first)
		return (-1);
	tmp = stack->first;
	bigger = stack->first;
	if (bigger->index == exclude)
	{
		tmp = stack->first->next;
		bigger = stack->first->next;
	}
	while (tmp->next)
	{
		if (tmp->next->val > bigger->val && tmp->next->index != exclude)
			bigger = tmp->next;
		tmp = tmp->next;
	}
	return (bigger->index);
}

t_node	*closer_1(int one, int two, t_stack *s, int inverted)
{
	int	tmp_one;
	int	tmp_two;

	tmp_one = ft_abs(how_many_moves(one, s->len));
	tmp_two = ft_abs(how_many_moves(two, s->len));
	if (inverted)
	{
		if (closer_1(one, two, s, 0)->index == one)
			return (get_node(s, two));
		return (get_node(s, one));
	}
	if (tmp_one == tmp_two)
	{
		if (one <= s->len / 2)
			return (get_node(s, one));
		return (get_node(s, two));
	}
	if (tmp_one < tmp_two)
		return (get_node(s, one));
	return (get_node(s, two));
}

t_node	*get_num_in_pos(t_stack *s, int pos)
{
	int	i;
	int	index;

	i = 0;
	index = smaller_1(s, -1);
	while (i++ < pos && index != bigger_1(s, -1))
		index = next_1(s, index);
	return (get_node(s, index));
}
