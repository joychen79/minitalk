/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:27:16 by jingchen          #+#    #+#             */
/*   Updated: 2023/06/13 19:43:38 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	sig_handler(int signum, siginfo_t *newaction, void *oldaction)
{
	static int	c = 0;
	static int	bit = 0;

	(void)oldaction;
	if (signum == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill ((newaction->si_pid), SIGUSR2);
		else
			kill ((newaction->si_pid), SIGUSR1);
		ft_putchar_fd(c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act1;
	struct sigaction	act2;

	pid = getpid();
	ft_printf("server pid es %d\n", pid);
	act1.sa_flags = SA_SIGINFO;
	act1.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &act1, NULL);
	act2.sa_flags = SA_SIGINFO;
	act2.sa_sigaction = sig_handler;
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
