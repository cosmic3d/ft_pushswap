/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:33:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/26 18:21:46 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	v(t_stack *s, int index)
{
	t_node	*tmp;

	tmp = get_node(s, index);
	if (tmp == NULL)
		return (0);
	return (tmp->val);
}
