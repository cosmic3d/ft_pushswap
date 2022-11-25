/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:26:47 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/21 14:36:59 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	void_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	return ;
}

void	reset_node(t_node *node)
{
	node->next = NULL;
	node->back = NULL;
	return ;
}

void	first_last(t_node *node, t_stack *stack)
{
	stack->first = node;
	stack->last = node;
	node->back = NULL;
	node->next = NULL;
	return ;
}
