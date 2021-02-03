/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:42:30 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/02/02 16:18:08 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int number;

	number = n;
	if (number == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number *= -1;
	}
	if (number > 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd('0' + (number % 10), fd);
}
