/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:38:10 by rlarabi           #+#    #+#             */
/*   Updated: 2022/11/11 13:33:38 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		a_len;
	int		b_len;
	int		i;
	char	*ret;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	a_len = ft_strlen(s1);
	b_len = ft_strlen(s2);
	i = -1;
	ret = (char *)malloc(sizeof(char) * (a_len + b_len + 1));
	if (!ret)
		return (0);
	while (s1[++i])
		ret[i] = s1[i];
	i = -1;
	while (s2[++i])
		ret[a_len + i] = s2[i];
	ret[a_len + i] = '\0';
	free(s1);
	return (ret);
}

char	*ft_update(char *reserve)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	if (!reserve)
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i] || !reserve[i + 1])
	{
		free(reserve);
		return (NULL);
	}
	new = malloc(ft_strlen(reserve) - i + 1);
	if (!new)
		return (NULL);
	j = 0;
	i++;
	while (reserve[i])
		new[j++] = reserve[i++];
	new[j] = '\0';
	free(reserve);
	return (new);
}

char	*remplire(int fd, char *reserve)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	while (end_line(buffer))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(reserve);
			return (NULL);
		}
		if (!i)
			break ;
		buffer[i] = '\0';
		reserve = ft_strjoin(reserve, buffer);
	}
	free(buffer);
	return (reserve);
}

char	*remplire_line(char *reserve)
{
	char	*str;
	int		i;

	i = 0;
	if (!reserve)
		return (NULL);
	str = malloc(ret_line(reserve) + 1);
	if (!str)
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*reserve[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve[fd] = remplire(fd, reserve[fd]);
	if (!reserve[fd])
		return (NULL);
	line = remplire_line(reserve[fd]);
	reserve[fd] = ft_update(reserve[fd]);
	return (line);
}
