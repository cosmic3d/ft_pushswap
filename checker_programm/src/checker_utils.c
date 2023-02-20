/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:05:25 by jenavarr          #+#    #+#             */
/*   Updated: 2023/02/20 16:59:00 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/checker.h"

void	valid_move(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(str, SA, 3))
		return (swap(a));
	if (!ft_strncmp(str, SB, 3))
		return (swap(b));
	if (!ft_strncmp(str, SS, 3))
		return (swapswap(a, b));
	if (!ft_strncmp(str, PA, 3))
		return (push(a, b));
	if (!ft_strncmp(str, PB, 3))
		return (push(b, a));
	if (!ft_strncmp(str, RA, 3))
		return (rotate(a));
	if (!ft_strncmp(str, RB, 3))
		return (rotate(b));
	if (!ft_strncmp(str, RR, 3))
		return (rotaterotate(a, b));
	if (!ft_strncmp(str, RRA, 4))
		return (reverse_rotate(a));
	if (!ft_strncmp(str, RRB, 4))
		return (reverse_rotate(b));
	if (!ft_strncmp(str, RRR, 4))
		return (rrr(a, b));
	ft_error(a, b);
}
