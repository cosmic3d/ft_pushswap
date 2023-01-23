/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:00:06 by jenavarr          #+#    #+#             */
/*   Updated: 2023/01/23 22:19:27 by jenavarr         ###   ########.fr       */
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
	first_last(dest->first, dest, ori->first, ori);
	return ;
}

void	push_s(t_stack *dest, t_stack *ori)
{
	push(dest, ori);
	if (dest->id == 'a')
	{
		if (ft_printf("%s", PA) == -1)
			ft_error(dest, ori);
		return ;
	}
	if (ft_printf("%s", PB) == -1)
		ft_error(dest, ori);
	return ;
}

void	how_push(t_stack *dest, t_stack *ori, int node, int brother)
{
	// debug_stack(dest);
	// debug_stack(ori);
	// ft_printf("\nI've received the number %d to push it\n", node);
	if (debug_error(ori, node))
	{
		return ;
		// ft_printf("An error ocurred\nThere isnt any node with %d as index\n", node);
		// debug_stack(dest);
		// debug_stack(ori);
		// exit(1);
	}
	// t_stack *a;

	// if (dest->id == 'a')
	// 	a = dest;
	// else
	// 	a = ori;
	// if (ft_is_ordered(a))
	// 	return ;
	//write(1, "llego\n", 6);
	if (node == 1 && ori->len - 1 == brother)
	{
		swap_s(ori, dest);
		return (push_s(dest, ori));
	}
	if (node <= ori->len / 2)
	{
		while (ori->first->index != node)
			rotate_s(ori, dest);
		push_s(dest, ori);
		reindex(dest);
		return (reindex(ori));
	}
	while (ori->first->index != node)
		reverse_rotate_s(ori, dest);
	push_s(dest, ori);
	reindex(dest);
	return (reindex(ori));
}
