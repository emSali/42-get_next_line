/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:39:41 by esali             #+#    #+#             */
/*   Updated: 2022/10/24 17:33:02 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//last_char : not reading ret[-1] first loop
char	*get_next_line(int fd)
{
	static char	save_file[BUFFER_SIZE + 1];
	char		*ret;
	int			i;
	char		last_char;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	i = 1;
	ret = (char *)malloc(sizeof(char) * 1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	last_char = ret[0];
	/*
	the while should save new characters until ret[strlen(ret) -1 ] == newline
	CONCAT:
	should make copy of ret and then free ret everytime and reallocate by concatenating the copied version of ret with save_file until
	*/
	while (last_char != '\n')
	{
		if (ft_strlen(save_file) == 0)
		{
			i = read(fd, save_file, BUFFER_SIZE);
			save_file[i] = '\0';
		}
		if (i == -1)
			return (NULL);
		if (i == 0)
			break;
		tmp = ret;
		ret = concat(ret, save_file);
		//making function that is removing first line from save instead of remove first char
		// needs to reallocate memory
		free(tmp);
		last_char = ret[ft_strlen(ret) - 1];
	}
	if (ret[0] == '\0')
	{
		return (NULL);
	}
	return (ret);
}

