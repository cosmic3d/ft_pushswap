/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:55:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/23 23:09:55 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	debug_stack(t_stack *stack)
{
	t_node	*tmp;
	
	tmp = stack->first;
	ft_printf("Printing stack %c:\n\n", stack->id);
	while (tmp != NULL)
	{
		ft_printf("Value of %d is: %d\n", tmp->index, tmp->val);
		tmp = tmp->next;
	}
	ft_printf("Len of stack a is: %i\n\n", stack->len);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
	{
		ft_printf("You need to give some input. Finishing program.\n");
		return (0);
	}
	if (!check_input(argv, argc))
		return (0);
	ft_init_a(&a, argc, argv);
	void_stack(&b);
	b.id = 'b';
	debug_stack(&a);
	debug_stack(&b);
	//swap(&a);
	push(&b, &a);
	push(&b, &a);
	debug_stack(&a);
        debug_stack(&b);
	push(&b, &a);
	debug_stack(&a);
	debug_stack(&b);
	return (0);
}
