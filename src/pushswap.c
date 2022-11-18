/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:55:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/18 21:42:41 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

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
	while (a.first)
	{
		ft_printf("Value of %d is: %d\n", a.first->index, a.first->val);
		a.first = a.first->next;
	}
	ft_printf("Len of stack a is: %i", a.len);
}