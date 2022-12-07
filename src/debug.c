/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:41 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/07 21:47:03 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

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
