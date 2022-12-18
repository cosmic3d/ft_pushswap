/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:55:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/18 20:53:12 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	algorithm(t_stack *a, t_stack *b)
{
	if (a->len <= 3)
		return (three_random(a, b));
	else if (a->len <= 5)
		return (five_random(a, b));
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	
	if (argc < 3)
	{
		ft_printf("You need to give some numbers. Finishing program.\n");
		return (ft_error(NULL, NULL));
	}
	if (!check_input(argv, argc))
		return (ft_error(NULL, NULL));
	if (ft_init_a(&a, argc, argv) == -1)
		return (ft_error(&a, NULL));
	ft_init_b(&b);
	if (ft_is_ordered(&a))
		return (empty_stacks(&a, &b));
	algorithm(&a, &b);
	if (ft_is_ordered(&a))
	{
		ft_printf("Stack is ordered!\n");
		return (0);
	}
	ft_printf("Stack is not ordered :(!\n");
	// debug_stack(&a);
	// debug_stack(&b);
	// how_push(&a, &b, check_smaller(&a, -1), a.len);
	// debug_stack(&a);
	// debug_stack(&b);
}
