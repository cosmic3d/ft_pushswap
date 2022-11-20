/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:43:06 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/20 18:55:11 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->first;
	if (stack->len == 2)
		stack->last = tmp; //El primero pasa a ser el último/segundo si solo hay dos nodos
	stack->first = tmp->next; //El segundo pasa a la posición del primero
	stack->first->back = NULL; //Como el segundo pasa a la posición del primero, su antecesor es NULL
	tmp->next = stack->first->next; //Antes de cambiar el next del segundo que ahora es primero, se lo asignamos al next del primero que ahora es segundo
	stack->first->next = tmp; //El segundo que ahora es primero tiene de sucesor al anterior primero
	tmp->back = stack->first; //El primero que ahora es segundo tiene de antecesor al segundo que ahora es primero
	return ;
}

void	swapswap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return ;
}