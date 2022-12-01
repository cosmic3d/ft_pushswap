/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:00:06 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/01 14:40:54 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	push(t_stack *dest, t_stack *ori)
{
	t_node	*tmp_dest;
	t_node	*tmp_ori;

	if (!ori->len)
		return (0);
	tmp_ori = ori->first;
	ori->first = ori->first->next;
	if (ori->first)
		ori->first->back = NULL;
	tmp_dest = dest->first;
	dest->first = tmp_ori;
	dest->first->next = tmp_dest;
	if (dest->first->next)
		dest->first->next->back = dest->first;
	dest->len++;
	ori->len--;
	if (dest->len == 1)
		first_last(dest->first, dest);
	return (1);
}