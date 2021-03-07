/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:59:39 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 14:59:59 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision(const char **line, va_list ptr, t_flags *flag)
{
	int	precision;

	precision = 0;
	flag->dot = 1;
	if (*(*line + 1) == '*')
	{
		(*line)++;
		precision = va_arg(ptr, int);
		if (precision < 0)
			flag->dot = 0;
	}
	else if (ft_isdigit(*(*line + 1)))
	{
		(*line)++;
		precision = ft_atoi(*line);
		while (ft_isdigit(*(*line + 1)))
			(*line)++;
	}
	return (precision);
}
