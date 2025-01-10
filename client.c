/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:47:39 by mizusato          #+#    #+#             */
/*   Updated: 2025/01/10 18:48:47 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr > (LONG_MAX - (str[i] - '0')) / 10) && sign == 1)
			return ((int)LONG_MAX);
		else if ((nbr * (-1) < (LONG_MIN + (str[i] - '0')) / 10) && sign == -1)
			return ((int)LONG_MIN);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

static void	send_msg(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR2) < 0)
				error_exit();
		}
		else
		{
			if (kill(pid, SIGUSR1) < 0)
				error_exit();
		}
		usleep(500);
		i--;
	}
	usleep(100);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		error_exit();
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_msg(argv[2][i], pid);
		i++;
	}
	return (0);
}
