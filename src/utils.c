/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:26:47 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/20 22:19:56 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	reset_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->len = 0;
	return ;
}

void	reset_node(t_node *node)
{
	node->next = NULL;
	node->back = NULL;
	return ;
}