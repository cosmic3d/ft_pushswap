/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:58:41 by jenavarr          #+#    #+#             */
/*   Updated: 2023/01/11 21:17:35 by jenavarr         ###   ########.fr       */
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
		ft_printf("\nValue of %d | %d is: \"%d\"\n\n", tmp->index, tmp->final_index, tmp->val);
		debug_node(tmp);
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

// void	debug_simulation(t_stack *a)
// {
// 	int	smaller1;
// 	int	smaller2;
// 	int	bigger1;

// 	smaller1 = smaller_1(a, -1);
// 	smaller2 = smaller_1(a, smaller1);
// 	bigger1 = bigger_1(a, -1);
// 	ft_printf("smaller1 is: %d\n", smaller1);
// 	ft_printf("smaller2 is: %d\n", smaller2);
// 	ft_printf("bigger1 is: %d\n", bigger1);
// 	ft_printf("1 and 2 is: %d\n", both_moves(closer_1(smaller1, smaller2, a->len, 0), closer_1(smaller1, smaller2, a->len, 1), a->len));
// 	ft_printf("1 and 5 is: %d\n", both_moves(closer_1(smaller1, bigger1, a->len, 0), closer_1(smaller1, bigger1, a->len, 1), a->len));
// }

void	debug_node(t_node *n)
{
	if (n->back)
		ft_printf("\tBack is %d\n", n->back->val);
	else
		ft_printf("\tBack is NULL\n");
	if (n->next)
		ft_printf("\tNext is %d\n", n->next->val);
	else
		ft_printf("\tNext is NULL\n");
}

int	debug_error(t_stack *stack, int node)
{
	t_node	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		if (tmp->index == node)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
