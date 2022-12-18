/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:21:05 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/18 22:45:16 by jenavarr         ###   ########.fr       */
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

	s2 = check_smaller(a, s1);
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
	how_push(a, b, closer_1(s1, b1, a->len, 0), closer_1(s1, b1, a->len, 1));
	return (how_push(a, b, closer_1(s1, b1, a->len, 1), -1));
}

void	three_random(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		if (a->first->val > a->last->val)
			return (choose_swap(a, b));
	if (a->last->val > a->first->val && a->last->val > a->first->next->val)
		return (choose_swap(a, b));
	if (a->last->back->val < a->last->val && a->last->val < a->first->val)
		return (reverse_rotate_a(a, b));
	if (a->first->val > a->last->back->val && a->last->back->val > a->last->val)
	{
		choose_swap(a, b);
		return (rotate_a(a, b));
	}
	if (a->last->back->val > a->last->val && a->last->back->val > a->first->val)
	{
		if (a->first->val < a->last->val)
		{
			choose_swap(a, b);
			return (reverse_rotate_a(a, b));
		}
	}
	if (a->last->val < a->first->val && a->first->val < a->last->back->val)
		return (rotate_a(a, b));
}
//1- Comprobamos si el stack se halla semiordenado o a varias iteraciones de un movimiento de ordenarse
//2- Buscamos la manera más rápida de ordenar el stack, que es pusheando los dos más pequeños o el más pequeño y el más grande.
//3- Realizamos las aciones indicadas por otra función que dictará qué elementos pushear
//4- Una vez pusheados, llamamos a la función three_random para ordenar esa pareja y consecuentemente traemos a los dos de stack b

void	five_random(t_stack *a, t_stack *b)
{
	int	closer_4;

	closer_4 = closer_1(check_smaller(a, -1), check_bigger(a), a->len, 0);
	if (a->len == 5)
	{
		choose_pushes(a, b, check_smaller(a, -1), check_bigger(a));
		three_random(a, b);
		push_a(a, b);
		if (check_bigger(a) == a->first->index)
			reverse_rotate_a(a, b);
		push_a(a, b);
		if (check_bigger(a) == a->first->index)
			reverse_rotate_a(a, b);
		return ;
	}
	how_push(a, b, closer_4, -1);
	three_random(a, b);
	push_a(a, b);
	if (!ft_is_ordered(a))
		reverse_rotate_a(a, b);
}

void	how_push(t_stack *a, t_stack *b, int node, int brother)
{
	int	smaller;

	smaller = check_smaller(a, -1);
	if (!node)
		return (push_b(a, b));
	if (node == 1 && a->len - 1 == brother)
	{
		swap_a(a, b);
		return (push_b(a, b));
	}
	if (node <= a->len / 2)
	{
		while (a->first->index != node)
			reverse_rotate_a(a, b);
		return (push_b(a, b));
	}
	while (a->first->index != node)
		rotate_a(a, b);
	return (push_b(a, b));
}
