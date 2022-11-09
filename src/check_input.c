/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:32:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/09 19:04:19 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	check_input(char **str)
{
	if (!check_digits(str))
	{
		ft_printf("Your input contains some symbols which are not digits.\n");
		return (0);
	}
	if (!check_int(str))
	{
		ft_printf("Nums lower than %d or bigger than %d.\n", INT_MIN, INT_MAX);
		return (0);
	}
	return (1);
}

int	check_digits(char **str)
{
	int	i;
	int	j;

	j = 1;
	while (str[j])
	{
		i = 0;
		if (!ft_strlen(str[j]))
			return (0);
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		if (str[j][i] == '-' || str[j][i] == '+' || str[j][i] == '\0')
			return (0);
		while (str[j][i] != '\0')
		{
			if (str[j][i] < '0' || str[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_int(char **str)
{
	int	i;
	int	sign;

	i = 1;
	sign = 0;
	while (str[i])
	{
		if (str[i][0] == '+' || str[i][0] == '-')
			sign = 1;
		if (ft_strlen(str[i]) - sign > 10)
			return (0);
		if (ft_strlen(str[i]) - sign == 10)
		{

		}
		i++;
	}
	return (1);
}
