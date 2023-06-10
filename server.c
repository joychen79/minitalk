/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:27:16 by jingchen          #+#    #+#             */
/*   Updated: 2023/06/10 15:41:07 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	sig_handler(int signum)
{
	/*static int	c;
	static int	bit;

	c = 0;
	bit = 0;
	while (bit < 7)
	{
		if (signum == SIGUSR1)
				c |= (1 << bit);
		bit++;
	}
	ft_putchar_fd(c, 1);*/
	static int	len = 0;
	static int	character = 0;

	if (signum == SIGUSR1)
		character |= (1 << len);
	len++;
	if (len == 8)
	{
		ft_putchar_fd(character, 1);
		character = 0;
		len = 0;
	}
}

int main(void)
{
	pid_t	pid;
	
	pid = getpid();
	ft_printf("current server is %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
	return (0);
}