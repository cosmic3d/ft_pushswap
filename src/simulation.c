/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:49:58 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/23 19:54:59 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	how_many_moves(int index, int len)
{
	if (!index)
		return (index);
	if (index <= len / 2)
		return (index * -1);
	return (len - index);
}
//Closer 1 y Closer2 son los 2 que nos interesan más cercanos al índice 0. El 1 es el primero más cercano y el 2 el segundo

int	both_moves(int closer1, int closer2, int len)
{
	int	moves;
	int	direction;

	direction = how_many_moves(closer1, len);
	moves = ft_abs(direction);
	if (!direction)
	{
		direction = -1;
		len--;
	}
	if (closer2 == len - 1)
		direction = 0;
	moves += ft_abs(how_many_moves((closer2 + direction), len));
	return (moves + 2);
}

void	reindex(t_stack *s)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = s->first;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	return ;
}
