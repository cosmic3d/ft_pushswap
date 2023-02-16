/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:53:25 by jenavarr          #+#    #+#             */
/*   Updated: 2023/02/16 19:32:20 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_getnextline/get_next_line.h"
#include "../hdrs/checker.h"
#include <unistd.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	if (!check_input(argv, argc))
		return (ft_error(NULL, NULL));
	if (ft_init_a(&a, argc, argv) == -1)
		return (ft_error(&a, NULL));
	ft_init_b(&b);
	do_moves(&a, &b);
}

void	do_moves(t_stack *a, t_stack *b)
{
	char	*str;
	int	moves;

	moves = 0;
	while (str != NULL)
	{
		str = get_next_line(0);
		//if (!valid_move(str))
		//exit(1);
		free(str);
		str = NULL;
	}
}
