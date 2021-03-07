/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:05:30 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:05:41 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(const char **line, va_list ptr, t_flags *flag)
{
	int	width;

	width = 0;
	if (**line == '*')
	{
		width = va_arg(ptr, int);
		if (width < 0)
		{
			flag->minus = 1;
			width = -width;
		}
	}
	else if (ft_isdigit(**line))
	{
		width = ft_atoi(*line);
		while (ft_isdigit(*(*line + 1)))
			(*line)++;
	}
	return (width);
}
