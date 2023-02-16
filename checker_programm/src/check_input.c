/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:32:54 by jenavarr          #+#    #+#             */
/*   Updated: 2023/02/16 19:32:24 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/checker.h"

int	check_input(char **str, int argc)
{
	if (!check_digits(str) || !check_int(str) || !check_dups(str, argc))
		return (0);
	return (1);
}

int	check_digits(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i])
	{
		j = 0;
		if (!ft_strlen(str[i]))
			return (0);
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (str[i][j] == '-' || str[i][j] == '+' || str[i][j] == '\0')
			return (0);
		while (str[i][j] != '\0')
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_int(char **s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (s[++i])
	{
		if (s[i][0] == '-' || s[i][0] == '+')
			sign = 1;
		if (ft_strlen(s[i]) - sign > 10)
			return (0);
		if (ft_strlen(s[i]) - sign == 10)
			if (!check_limits_when_10(s[i], sign))
				return (0);
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

int	check_dups(char	**s, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc - 1)
	{
		j = 0;
		while (++j < argc)
		{
			if (i == j)
				j++;
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (0);
		}
	}
	return (1);
}
