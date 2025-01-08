/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:05:24 by mizusato          #+#    #+#             */
/*   Updated: 2025/01/08 20:20:42 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum)
{
	static char	byte = 0;
	static int	power = 0;

	if (signum == SIGUSR2)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_printf("%c", byte);
		byte = 0;
		power = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("PID:%d\n", pid);
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		while (1)
			pause();
	}
	return (0);
}
