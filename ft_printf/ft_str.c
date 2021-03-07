/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:04:03 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:04:16 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(char *list, t_flags flag)
{
	int	len;

	if (!list)
		list = "(null)";
	flag.len_list = ft_strlen(list);
	if (flag.precision && flag.precision > flag.len_list)
		flag.precision = flag.len_list;
	if (flag.dot && flag.precision < flag.len_list)
		len = flag.width - flag.precision;
	else
		len = flag.width - flag.len_list;
	if (!flag.minus && !flag.zero && flag.width > 0)
		flag.num += wr_char_len(' ', len);
	if (!flag.minus && flag.zero)
		flag.num += wr_char_len('0', len);
	if (flag.dot && !flag.sign_w)
		flag.num += print_str(list, flag.precision);
	else
		flag.num += print_str(list, flag.len_list);
	if (flag.minus || flag.sign_w)
		flag.num += wr_char_len(' ', flag.sign_w
		? (flag.width * -1) - flag.len_list : len);
	return (flag.num);
}
