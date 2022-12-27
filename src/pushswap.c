/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:55:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/27 20:11:29 by jenavarr         ###   ########.fr       */
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
	return (one_hundred_random(a, b, 50));
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
	// debug_stack(&a);
	// debug_stack(&b);
	// if (ft_is_ordered(&a))
	// 	ft_printf("Stack A is ordered!\n");
	// else
	// 	ft_printf("Stack A is not ordered :(!\n");
	exit(1);
}

// python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
// python3 pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`