/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:50:06 by wmari             #+#    #+#             */
/*   Updated: 2021/10/26 14:37:17 by wmari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	ret;

	ret = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		ret = (ret * 10) + (*str - 48);
		str++;
	}
	return (ret * sign);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	int	j;

	if (argc != 3)
		return (1);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != 0)
	{
		j = 7;
		while (j >= 0)
		{
			if ((argv[2][i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
	return (0);
}
