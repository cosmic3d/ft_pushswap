/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:49:58 by jenavarr          #+#    #+#             */
/*   Updated: 2023/01/17 22:08:47 by jenavarr         ###   ########.fr       */
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

void	finalindexation(t_stack *s)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = get_node(s, smaller_1(s, -1));
	while (tmp->index != bigger_1(s, -1))
	{
		tmp->final_index = count++;
		tmp = get_node(s, next_1(s, tmp->index));
	}
	tmp->final_index = count;
}
