/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 23:20:08 by minsunki          #+#    #+#             */
/*   Updated: 2021/03/08 01:06:01 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_nl(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static char	*dat;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		rbytes;
	int			nidx;

	if (fd < 0 || !line)
		return (-1);
	while ((rbytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rbytes] = '\0';
		tmp = dat;
		dat = ft_strjoin(dat, buf);
		free(tmp);
		if ((nidx = find_nl(buf)) != -1)
			return (ft_substr(buf, 0, nidx));
	}

}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	len = (ft_strlen(s + start) < len ? ft_strlen(s + start) : len);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
