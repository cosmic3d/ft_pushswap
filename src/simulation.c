/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:49:58 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/18 19:03:37 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

// int	val(t_stack *s, int ind)
// {
// 	t_node	*tmp;

// 	if (!s)
// 		return (-1);
// 	tmp = s->first;
// 	while (tmp)
// 	{
// 		if (tmp->index == ind)
// 			return (tmp->val);
// 		tmp = tmp->next;
// 	}
// 	return (-1);
// }

//Evaluamos si el stack se encuentra a varios ra o rra de ordenarse. En tal caso, se devuelve un -1 para rra y un 1 para ra (0 en caso de no haber orden)
// int	few_rotate(t_stack *a, int smaller)
// {

// }

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

// void	which_pair(t_stack *a)
// {
// 	int	smaller1;
// 	int	smaller2;
// 	int	bigger1;
// 	int	moves;

// 	smaller1 = check_smaller(a, -1);
// 	smaller2 = check_smaller(a, check_smaller(a, -1));
// 	bigger1 = check_bigger(a, -1);
// 	moves = 1;
// }

int	closer_1(int one, int two, int len, int inverted)
{
	int	tmp_one;
	int	tmp_two;

	tmp_one = ft_abs(how_many_moves(one, len));
	tmp_two = ft_abs(how_many_moves(two, len));
	if (inverted)
	{
		if (closer_1(one, two, len, 0) == one)
			return (two);
		return (one);
	}
	if (tmp_one == tmp_two)
	{
		if (one <= len / 2)
			return (one);
		return (two);
	}
	if (tmp_one < tmp_two)
		return (one);
	return (two);
}
