/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:05:24 by mizusato          #+#    #+#             */
/*   Updated: 2025/01/10 18:48:14 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

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
	pid_t				pid;
	struct sigaction	sa;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("PID:%d\n", pid);
		sa.sa_handler = sig_handler;
		sigemptyset(&sa.sa_mask);
		sigaddset(&sa.sa_mask, SIGUSR1);
		sigaddset(&sa.sa_mask, SIGUSR2);
		sa.sa_flags = 0;
		if (sigaction(SIGUSR1, &sa, NULL) < 0)
			error_exit();
		if (sigaction(SIGUSR2, &sa, NULL) < 0)
			error_exit();
		while (1)
			pause();
	}
	return (0);
}
