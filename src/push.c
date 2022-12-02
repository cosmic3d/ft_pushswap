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

void	push(t_stack *dest, t_stack *ori)
{
	t_node	*tmp_dest;
	t_node	*tmp_ori;

	if (!ori->len)
		return ;
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
	return ;
}

void	push_a(t_stack *a, t_stack *b)
{
	push(a, b);
	if (ft_printf("%s", PA) == -1)
		return (ft_error(a, b));
	return ;
}

void    push_b(t_stack *b, t_stack *a)                        {                                                                     push(b, a);                                                   if (ft_printf("%s", PB) == -1)                                        return (ft_error(a, b));                              return ;
}
