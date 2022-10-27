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

char	*get_next_line(int fd)
{
	static char	*save_file;
	char		*ret;
	int			i;

	i = 1;
	printf("\nsave_file at beginning: %s\n", save_file);
	if (save_file == NULL)
	{
		save_file = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!save_file)
			return (NULL);
	}
	ret = (char *)malloc(sizeof(char) * 1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	/*
	the while should save new characters until ret[strlen(ret) -1 ] == newline
	CONCAT:
	should make copy of ret and then free ret everytime and reallocate by concatenating the copied version of ret with save_file until
	*/
	while (ret[ft_strlen(ret)] != '\n')
	{
		printf("\nret length: %i \nret value: %c", ft_strlen(ret), ret[ft_strlen(ret)]);
		i = read(fd, save_file, BUFFER_SIZE);
		// printf("\ni %i:\n", i);
		printf("\nsave_file in while: %s\n", save_file);
		if (i == -1)
		{
			printf("\ni is -1, returns NULL");
			return (NULL);
		}
		if (i == 0)
		{
			printf("\ni is 0, breaks");
			break;
		}
		ret = concat(ret, save_file);
		printf("\nsave_file after concat: %s\n", save_file);
		printf("\nret in while: %s\n", ret);

	}
	if (*ret == '\0')
	{
		free(save_file);
		return (NULL);
	}
	printf("\nreturn: %s\n", ret);
	return (ret);
}

