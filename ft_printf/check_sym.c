/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sym.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:54:15 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 14:54:32 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_sym(char **list)
{
	int	count;

	count = 0;
	if (*list[0] == '-')
		count += print_char(*list[0]);
	if ((*list)[0] == '0' && (*list)[1] == 'x')
		count += print_char('0') + print_char('x');
	(*list) += count;
	return (count);
}
