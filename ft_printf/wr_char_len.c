/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_char_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:08:09 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:11:35 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wr_char_len(int c, int len)
{
	int count_wr;

	count_wr = 0;
	while (len > 0)
	{
		count_wr += print_char(c);
		len--;
	}
	return (count_wr);
}
