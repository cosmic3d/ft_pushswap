/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:21:05 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/23 20:47:02 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	choose_pushes(t_stack *a, t_stack *b, int s1, int b1)
{
	int	s2;
	int	closer_one;
	int	closer_two;
	int	moves_one;
	int	moves_two;

	s2 = smaller_1(a, s1);
	closer_one = closer_1(s1, b1, a->len, 0);
	closer_two = closer_1(s1, b1, a->len, 1);
	moves_two = both_moves(closer_one, closer_two, a->len);
	closer_one = closer_1(s1, s2, a->len, 0);
	closer_two = closer_1(s1, s2, a->len, 1);
	moves_one = both_moves(closer_one, closer_two, a->len);
	if (moves_one <= moves_two)
	{
		how_push(a, b, closer_one, closer_two);
		return (how_push(a, b, closer_two, -1));
	}
	closer_one = closer_1(s1, b1, a->len, 1);
	how_push(a, b, closer_1(s1, b1, a->len, 0), closer_one);
	return (how_push(a, b, closer_one, -1));
}

void	three_random(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		if (a->first->val > a->last->val)
			return (choose_swap(a, b));
	if (a->last->val > a->first->val && a->last->val > a->first->next->val)
		return (choose_swap(a, b));
	if (a->last->back->val < a->last->val && a->last->val < a->first->val)
		return (rotate_a(a, b));
	if (a->first->val > a->last->back->val && a->last->back->val > a->last->val)
	{
		choose_swap(a, b);
		return (reverse_rotate_a(a, b));
	}
	if (a->last->back->val > a->last->val && a->last->back->val > a->first->val)
	{
		if (a->first->val < a->last->val)
		{
			choose_swap(a, b);
			return (rotate_a(a, b));
		}
	}
	if (a->last->val < a->first->val && a->first->val < a->last->back->val)
		return (reverse_rotate_a(a, b));
}
//1- Comprobamos si el stack se halla semiordenado o a varias iteraciones de un movimiento de ordenarse
//2- Buscamos la manera más rápida de ordenar el stack, que es pusheando los dos más pequeños o el más pequeño y el más grande.
//3- Realizamos las aciones indicadas por otra función que dictará qué elementos pushear
//4- Una vez pusheados, llamamos a la función three_random para ordenar esa pareja y consecuentemente traemos a los dos de stack b

void	five_random(t_stack *a, t_stack *b)
{
	if (few_swap(a, b) || few_rotate(a, b, get_node(a, smaller_1(a, -1))))
		return ;
	if (a->len == 5)
	{
		choose_pushes(a, b, smaller_1(a, -1), bigger_1(a));
		if (!ft_is_ordered(a))
			three_random(a, b);
		push_a(a, b);
		if (bigger_1(a) == a->first->index)
			rotate_a(a, b);
		push_a(a, b);
		if (bigger_1(a) == a->first->index)
			rotate_a(a, b);
		if (a->first->val > a->first->next->val)
			swap_a(a, b);
		return ;
	}
	how_push(a, b, closer_1(smaller_1(a, -1), bigger_1(a), a->len, 0), -1);
	if (!ft_is_ordered(a))
		three_random(a, b);
	push_a(a, b);
	if (!ft_is_ordered(a))
		rotate_a(a, b);
}
