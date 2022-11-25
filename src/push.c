/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:00:06 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/23 23:10:04 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	push(t_stack *dest, t_stack *ori)
{
	t_node	*tmp_dest;
	t_node	*tmp_ori;
	
	if (ori->len <= 0)
		return ;
	tmp_ori = ori->first;
	ori->first = ori->first->next;
	if (ori->first)
		ori->first->back = NULL;
	//write(1, "Aqui llega\n", 11);
	if (!ori->first)
		void_stack(ori);
	tmp_dest = dest->first;
	dest->first = tmp_ori;
	//write(1, "Aqui llega\n", 11);
	dest->first->next = tmp_dest;
	if (dest->first->next)
		dest->first->next->back = dest->first;
	dest->len++;
	ori->len--;
	if (dest->len == 1)
		first_last(dest->first, dest);
}
