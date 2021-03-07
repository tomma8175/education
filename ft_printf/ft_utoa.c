/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:05:06 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:05:21 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int number, int base, int flag)
{
	int		count;
	char	*list;

	count = num_base(number, base);
	list = (char *)malloc((count + 1) * sizeof(char));
	if (!list)
		return (NULL);
	list[count--] = '\0';
	if (number == 0)
		list[count] = '0';
	while (number != 0)
	{
		list[count] = "0123456789abcdef"[number % base];
		number = number / base;
		count--;
	}
	if (flag)
		while (list[++count] != '\0')
			list[count] = ft_toupper(list[count]);
	return (list);
}
