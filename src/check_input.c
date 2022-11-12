/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:32:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/11 20:31:14 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

int	check_input(char **str, int argc)
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
	if (!check_dups(str, argc))
	{
		ft_printf("Some numbers are duplicated.\n");
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
			if (!check_limits_when_10(str[i], sign))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_limits_when_10(char *str, int sign)
{
	if (sign)
	{
		if (str[0] == '+')
		{
			if (ft_strncmp(str, "+2147483647", 11) > 0)
				return (0);
		}
		else
		{
			if (ft_strncmp(str, "-2147483648", 11) > 0)
				return (0);
		}
	}
	if (ft_strncmp(str, "2147483647", 10) > 0)
		return (0);
	return (1);
}

int	check_dups(char	**str, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc - 1)
	{
		j = 0;
		while (++j < argc - 1)
		{
			if (i == j)
				j++;
			if (ft_strlen(str[i]) >= ft_strlen(str[j]))
			{
				if (!ft_strncmp(str[i], str[j], ft_strlen(str[i])))
					return (0);
			}
			else
			{
				if (!ft_strncmp(str[j], str[i], ft_strlen(str[j])))
					return (0);
			}
		}
	}
	return (1);
}
