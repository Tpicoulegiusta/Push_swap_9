/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:43:22 by tpicoule          #+#    #+#             */
/*   Updated: 2023/04/05 08:43:33 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > -2147483648 && ft_atol(argv[i]) < 2147483647)
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_args_2(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i <= argc - 1)
	{
		j = i + 1;
		while (j <= argc - 1)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_args_3(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (ft_isdigit(argv[i][j++]) != 1)
				return (1);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_return_check(int argc, char **argv)
{
	if (argv[1] == '\0')
		return (0);
	if (argc <= 1)
		return (write(1, "Error\n", 6));
	if (ft_check_args_3(argv) != 0)
		return (write(1, "Error2\n", 7));
	if (ft_check_args(argv) != 0)
		return (write(1, "Error3\n", 7));
	if (ft_check_args_2(argc, argv) != 0)
		return (write(1, "Error4\n", 7));
	if (argc <= 2)
		return (0);
	return (0);
}
