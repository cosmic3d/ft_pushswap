/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:15:39 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/23 18:50:54 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

t_node	*get_node(t_stack *s, int index)
{
	t_node	*tmp;

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
