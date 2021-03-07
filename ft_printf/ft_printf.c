/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:00:43 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:01:18 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	func_if(va_list ptr, const char **line)
{
	t_flags	flag;

	flag = parse_flags(&(*line), ptr);
	if (**line == 'c')
		return (ft_print_c(va_arg(ptr, int), flag));
	else if (**line == 's')
		return (ft_str(va_arg(ptr, char*), flag));
	else if (**line == 'd' || **line == 'i')
		return (ft_itoa(va_arg(ptr, int), flag));
	else if (**line == '%')
		return (ft_print_c('%', flag));
	else if (**line == 'p')
		return (ft_pointer(va_arg(ptr, unsigned long int), flag));
	else if (**line == 'u')
		return (ft_hex(ptr, 10, 0, flag));
	else if (**line == 'x')
		return (ft_hex(ptr, 16, 0, flag));
	else if (**line == 'X')
		return (ft_hex(ptr, 16, 1, flag));
	else
		return (print_char(**line));
}

int			func_percent(va_list ptr, const char **line)
{
	int	i;

	i = 0;
	while (**line)
	{
		if (**line == '%')
			i += func_if(ptr, &(*line));
		else
			i += print_char(**line);
		if (**line)
			(*line)++;
	}
	return (i);
}

int			ft_printf(const char *line, ...)
{
	va_list	ptr;
	int		count;

	count = 0;
	va_start(ptr, line);
	count = func_percent(ptr, &line);
	va_end(ptr);
	return (count);
}
