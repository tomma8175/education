/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:06:42 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:06:56 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, int len)
{
	if (len == 0)
		return (0);
	return (write(1, s, len));
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}
