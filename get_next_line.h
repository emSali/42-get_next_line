/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:40:51 by esali             #+#    #+#             */
/*   Updated: 2022/10/16 18:12:27 by esali            ###   ########.fr       */
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

char	*get_next_line(int fd);
int		ft_strlen(char *str);

#endif