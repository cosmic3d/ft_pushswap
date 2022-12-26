/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:55:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/26 17:55:37 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	algorithm(t_stack *a, t_stack *b)
{
	if (a->len <= 3)
		return (three_random(a, b));
	else if (a->len <= 5)
		return (five_random(a, b));
	else if (a->len <= 100)
		return (one_hundred_random(a, b, 20));
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 3)
		return (ft_error(NULL, NULL));
	if (!check_input(argv, argc))
		return (ft_error(NULL, NULL));
	if (ft_init_a(&a, argc, argv) == -1)
		return (ft_error(&a, NULL));
	ft_init_b(&b);
	if (ft_is_ordered(&a))
		exit(1);
	algorithm(&a, &b);
	exit(1);
}
