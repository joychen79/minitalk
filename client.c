/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:31:53 by jingchen          #+#    #+#             */
/*   Updated: 2023/06/10 15:07:38 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	send_char(int pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c << (1 & i))
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(250);
	i++;
	}
}

void	send_string(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		return (-1);
	}
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}
