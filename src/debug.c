/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:41 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/18 20:51:03 by jenavarr         ###   ########.fr       */
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

void	debug_simulation(t_stack *a)
{
	int	smaller1;
	int	smaller2;
	int	bigger1;

	smaller1 = check_smaller(a, -1);
	smaller2 = check_smaller(a, smaller1);
	bigger1 = check_bigger(a);
	ft_printf("smaller1 is: %d\n", smaller1);
	ft_printf("smaller2 is: %d\n", smaller2);
	ft_printf("bigger1 is: %d\n", bigger1);
	ft_printf("1 and 2 is: %d\n", both_moves(closer_1(smaller1, smaller2, a->len, 0), closer_1(smaller1, smaller2, a->len, 1), a->len));
	ft_printf("1 and 5 is: %d\n", both_moves(closer_1(smaller1, bigger1, a->len, 0), closer_1(smaller1, bigger1, a->len, 1), a->len));
}
