/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:56:09 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 14:56:10 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flags(void)
{
	t_flags	flag;

	flag.minus = 0;
	flag.dot = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.precision = 0;
	flag.len_list = 0;
	flag.num = 0;
	flag.sign_w = 0;
	return (flag);
}
