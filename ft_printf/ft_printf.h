/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:01:35 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/07 15:03:43 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H_
# define _FT_PRINTF_H_

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			minus;
	int			dot;
	int			zero;
	int			width;
	int			precision;
	int			len_list;
	int			num;
	int			sign_w;
}				t_flags;

int				ft_printf(const char *line, ...);
int				func_percent(va_list ptr, const char **line);
int				check_sym(char **list);
int				ft_atoi(const char *str);
t_flags			ft_flags(void);
int				ft_hex(va_list ptr, int base, int flag, t_flags flags);
int				ft_isdigit(int c);
int				ft_itoa(int c, t_flags flag);
int				ft_pointer(unsigned long int number, t_flags flag);
int				ft_precision(const char **line, va_list ptr, t_flags *flag);
int				ft_print_c(char c, t_flags flag);
int				ft_str(char *list, t_flags flag);
int				ft_strlen(const char *s);
int				ft_toupper(int c);
char			*ft_utoa(unsigned int number, int base, int flag);
int				ft_width(const char **line, va_list ptr, t_flags *flag);
int				num_base(unsigned long int c, int base);
t_flags			parse_flags(const char **line, va_list ptr);
int				print_str(char *s, int len);
int				print_char(char c);
int				print_d_i(char *list, t_flags flag);
int				print_pointer(char *list, t_flags flags);
int				spec(int c);
int				wr_char_len(int c, int len);

#endif
