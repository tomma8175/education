/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:06:20 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:06:32 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	parse_flags(const char **line, va_list ptr)
{
	t_flags	flag;

	flag = ft_flags();
	(*line)++;
	while (**line && spec(**line))
	{
		if (**line == '-')
			flag.minus = 1;
		else if (**line == '0' && !flag.minus)
			flag.zero = 1;
		else if (**line == '.' && !flag.dot)
			flag.precision = ft_precision(&(*line), ptr, &flag);
		else if (ft_isdigit(**line) || **line == '*')
			flag.width = ft_width(&(*line), ptr, &flag);
		else
			break ;
		(*line)++;
	}
	return (flag);
}
