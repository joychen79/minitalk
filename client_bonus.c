/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:31:53 by jingchen          #+#    #+#             */
/*   Updated: 2023/06/13 20:11:37 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	message_confirm(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("messeage received\n");
		exit (0);
	}
}

static void	send_char(int pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(250);
	i++;
	}
}

/*void	send_string(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}*/

int	main(int argc, char **argv)
{
	char	*str;

	str = argv[2];
	if (argc != 3)
	{
		return (-1);
	}
	signal(SIGUSR1, message_confirm);
	signal(SIGUSR2, message_confirm);
	while (*str)
		send_char(ft_atoi(argv[1]), *str++);
	send_char(ft_atoi(argv[1]), '\0');
	sleep(10);
	ft_printf("no message received\n");
	return (0);
}
