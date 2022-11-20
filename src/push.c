/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:00:06 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/20 22:19:52 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	push(t_stack *dest, t_stack *ori)
{
	t_node	*tmp_dest;
	t_node	*tmp_ori;
	
	if (!ori->len)
		return ;
	dest->len++;
	ori->len--;
	
	if (!dest->len)
		first_last(tmp_ori, dest);
}

void	first_last(t_node *node, t_stack *stack)
{
	stack->first = node;
	stack->last = node;
	node->back = NULL;
	node->next = NULL;
}