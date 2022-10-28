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

//while loop into extra function 
char	*get_next_line(int fd)
{
	static char	save_file[BUFFER_SIZE + 1];
	char		*ret;
	char		*tmp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	i = 1;
	ret = (char *)malloc(sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	while (last_char(ret) != '\n')
	{
		if (ft_strlen(save_file) == 0)
		{
			i = read(fd, save_file, BUFFER_SIZE);
			save_file[i] = '\0';
			if (i == -1)
				return (NULL);
			if (i == 0)
				break ;
		}
		tmp = ret;
		ret = concat(ret, save_file);
		free(tmp);
		remove_first_line(save_file);
	}
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
