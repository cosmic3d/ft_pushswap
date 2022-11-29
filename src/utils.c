/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:26:47 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/29 14:31:40 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	empty_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->first)
	{
		tmp = stack->first->next;
		free(stack->first);
		stack->first = tmp;
	}
	stack = NULL;
	return ;
}

void	reset_node(t_node *node)
{
	node->next = NULL;
	node->back = NULL;
	return ;
}

void	first_last(t_node *node, t_stack *stack)
{
	stack->first = node;
	stack->last = node;
	node->back = NULL;
	node->next = NULL;
	return ;
}

void	debug_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->first;
	ft_printf("\n|----------------------------|\n");
	ft_printf("Printing stack %c:\n\n", stack->id);
	while (tmp != NULL)
	{
		ft_printf("Value of %d is: %d\n", tmp->index, tmp->val);
		tmp = tmp->next;
	}
	if (stack->len)
	{
		ft_printf("\nFirst of stack is: %i\n", stack->first->val);
		ft_printf("Last of stack is: %i\n\n", stack->last->val);
	}
	ft_printf("Len of stack is: %i\n\n", stack->len);
	return ;
}
