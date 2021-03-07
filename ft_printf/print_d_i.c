/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:07:10 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:07:21 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d_i(char *list, t_flags flag)
{
	int	len;

	if (list[0] == '0' && flag.dot && !flag.precision)
		list[0] = '\0';
	flag.len_list = ft_strlen(list);
	if (!flag.width && flag.precision && flag.precision > flag.len_list)
		len = flag.precision - flag.len_list;
	else if (flag.precision && flag.precision > flag.len_list && flag.width)
		len = flag.width - flag.precision;
	else
		len = flag.width - flag.len_list;
	if (list[0] == '-' && flag.precision >= flag.len_list)
		len--;
	if (flag.width && !flag.minus && (!flag.zero || flag.dot))
		flag.num += wr_char_len(' ', len);
	if (flag.zero && !flag.minus && !flag.dot)
		flag.num += check_sym(&list) + wr_char_len('0', len);
	if (flag.dot && flag.precision >= flag.len_list)
		flag.num += check_sym(&list) + wr_char_len('0',
					flag.precision - ft_strlen(list));
	flag.num += print_str(list, ft_strlen(list));
	if (flag.minus && flag.width)
		flag.num += wr_char_len(' ', len);
	return (flag.num);
}
