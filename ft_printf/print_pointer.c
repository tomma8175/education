/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:07:30 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:07:41 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(char *list, t_flags flags)
{
	flags.len_list = ft_strlen(list);
	if (flags.precision == 0 && flags.dot && list[2] == '0')
		flags.len_list--;
	if (flags.precision > flags.width && flags.dot)
		flags.len_list -= 2;
	if (flags.width && !flags.minus && !flags.zero && !flags.dot)
		flags.num += wr_char_len(' ', flags.width - flags.len_list);
	else if (flags.width && (flags.dot || !flags.zero) && !flags.minus)
		flags.num += wr_char_len(' ', flags.precision > flags.len_list
		? flags.width - flags.precision : flags.width - flags.len_list);
	if (flags.zero && !flags.minus && !flags.dot && flags.width)
		flags.num += check_sym(&list) +
			wr_char_len('0', flags.width - flags.len_list);
	if (flags.dot && flags.precision > flags.len_list)
		flags.num += check_sym(&list) +
			wr_char_len('0', flags.precision - flags.len_list);
	flags.num += print_str(list, flags.len_list);
	if (flags.minus)
		flags.num += wr_char_len(' ', flags.precision >= flags.len_list
		? flags.width - flags.precision : flags.width - flags.len_list);
	return (flags.num);
}
