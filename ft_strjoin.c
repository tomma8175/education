/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:28:51 by tmkrtchy          #+#    #+#             */
/*   Updated: 2021/01/26 15:29:25 by tmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*space;
// 	size_t	len1;
// 	size_t	len2;

// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	space = malloc(sizeof(char) * len1 * len2 + 1);
// 	if (!space)
// 		return (NULL);
// 	ft_memcpy(space, s1, len1);
// 	ft_memcpy(space + len1, s2, len2);
// 	space[len1 + len2 + 1] = '\0';
// 	return (space);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((result = (char *)malloc(sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	ft_strlcat(ft_strlcpy(result, s1, ft_strlen(s1)), s2, ft_strlen(s2));
	return (result);
}