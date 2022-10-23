/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:39:41 by esali             #+#    #+#             */
/*   Updated: 2022/10/23 10:55:08 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save_file;
	char		*ret;
	int			i;

	i = 0;
	if (save_file == 0 || save_file[0] == '\0')
	{
		// printf("\nsave_file inside first if: %s\n", save_file);
		save_file = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!save_file)
			return (NULL);
		i = read(fd, save_file, BUFFER_SIZE);
	}
	// printf("\nsave_file: %s\n", save_file);
	if (i == -1)
		return (NULL);
	ret = "\0";
	while (!has_new_line(save_file) && save_file == 0)
	{
		ret = concat(ret, save_file);
		// printf("\nret: %s\n", ret);
		i = read(fd, save_file, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		// printf("\nsave_file in while: %s\n", save_file);
	}
	// printf("\nafter while");
	if (*save_file != 0)
		ret = concat(ret, save_file);
	else
		free(save_file);
	// printf("\nret at end: %s\n", ret);
	if (*ret == '\0')
		return (NULL);
	return (ret);
}
