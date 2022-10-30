/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:40:51 by esali             #+#    #+#             */
/*   Updated: 2022/10/29 20:56:39 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>

char	*get_next_line(int fd);
char	*concat(char *str1, char *str2);
int		ft_strlen(char *str);
void	remove_first_line(char *str);
char	*gnl(char *ret, char *save_file, int fd);
int		cpy_ret(char *ret, char *s1);

#endif
