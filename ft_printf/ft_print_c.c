/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:00:10 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:00:20 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c, t_flags flag)
{
	if (flag.width && !flag.zero && !flag.minus)
		flag.num += wr_char_len(' ', flag.width - 1);
	else if (flag.zero && !flag.minus)
		flag.num += wr_char_len('0', flag.width - 1);
	flag.num += print_char(c);
	if (flag.minus)
		flag.num += wr_char_len(' ', flag.width - 1);
	return (flag.num);
}
