/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:58:27 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 14:58:41 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long int number, t_flags flag)
{
	int		count;
	char	*list;

	count = 2 + num_base(number, 16);
	list = (char *)malloc((count + 1) * sizeof(char));
	if (!list)
		return (0);
	list[count--] = '\0';
	if (number == 0)
		list[count--] = '0';
	while (number != 0)
	{
		list[count] = "0123456789abcdef"[number % 16];
		number = number / 16;
		count--;
	}
	list[count--] = 'x';
	list[count] = '0';
	count = print_pointer(list, flag);
	free(list);
	return (count);
}
