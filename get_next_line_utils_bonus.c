/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:21:10 by minsunki          #+#    #+#             */
/*   Updated: 2021/03/14 20:54:43 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	while (*str++)
		ret++;
	return (ret);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	slen;

	if (!str)
		return (0);
	slen = ft_strlen(str);
	if (!(ret = (char *)malloc(sizeof(char) * (slen + 1))))
		return (0);
	ft_strlcpy(ret, str, slen + 1);
	return (ret);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;

	if (!dest || !src)
		return (0);
	slen = ft_strlen(src);
	i = 0;
	if (!size)
		return (slen);
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (slen);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	if (!dest || !src)
		return (0);
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = 0;
	if (size < dlen + 1)
		return (size + slen);
	if (size > dlen + 1)
	{
		while (src[i] && dlen + 1 + i < size)
		{
			dest[dlen + i] = src[i];
			i++;
		}
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcat(ret + s1_len, s2, s2_len + 1);
	return (ret);
}
