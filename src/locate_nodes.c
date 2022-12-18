/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:15:39 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/18 20:54:42 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	check_smaller(t_stack *stack, int exclude)
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

int	check_bigger(t_stack *stack)
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
