/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:55:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/11 20:14:03 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	main(int argc, char **argv)
{
	// t_stack	a;
	// t_stack	b;

	if (argc < 2)
	{
		ft_printf("You need to give some input. Finishing program.\n");
		return (0);
	}
	if (!check_input(argv, argc))
		return (0);
}