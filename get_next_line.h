/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarabi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:52:02 by rlarabi           #+#    #+#             */
/*   Updated: 2022/11/10 21:37:22 by rlarabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ret_line(char *str);
size_t	ft_strlen(char *str);
int		end_line(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*remplire_line(char *reserve);
char	*remplire(int fd, char *reserve);
char	*ft_update(char *reserve);
#endif