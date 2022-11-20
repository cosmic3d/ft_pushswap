/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:55:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/20 18:07:10 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	debug_stack(t_stack *stack)
{
	t_node	*tmp;
	
	tmp = stack->first;
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
	ft_init_b(&b);
	debug_stack(&a);
	swap(&a);
	debug_stack(&a);
	return (0);
}