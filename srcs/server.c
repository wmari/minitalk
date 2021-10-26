/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:00:53 by wmari             #+#    #+#             */
/*   Updated: 2021/10/26 13:47:03 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	write_pid(pid_t pid)
{
	char	c;

	if (pid / 10 != 0)
		write_pid(pid / 10);
	c = (pid % 10) + 48;
	write(1, &c, 1);
}

void	write_char(int sig)
{
	static char	c = 0;
	static int	i = 0;

	if (c != 0)
		c <<= 1;
	if (sig == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	write(1, "PID : ", 6);
	write_pid(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, write_char);
		signal(SIGUSR2, write_char);
	}
	return (0);
}
