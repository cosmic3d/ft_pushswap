/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:55:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/30 15:14:48 by jenavarr         ###   ########.fr       */
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
	//TO DO
	// if (a.len <= 3)
	// 	return (0);
}
