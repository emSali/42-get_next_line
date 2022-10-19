/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:39:41 by esali             #+#    #+#             */
/*   Updated: 2022/10/19 22:16:27 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
Funktion soll eine Zeile lesen bis entweder die BUFFER_SIZE aufgebraucht ist
oder das Ende der Zeile (\n) erreicht ist.
Hierfuer duerfen eigentlich auch nur 6 Funktionen verwendet werden.
*/
char	*get_next_line(int fd)
{
	static char	*save_file;
	char		*ret;

	printf("\nsave_file: %s", save_file);
	//printf("\nBUFFER_SIZE: %i", BUFFER_SIZE);
	if (save_file == NULL) {
		save_file = (char *) malloc(BUFFER_SIZE * sizeof(char));
		if (!save_file)
			return NULL;
	}
	while (!has_new_line(save_file) && save_file != 0)
	{
		read(fd, save_file, BUFFER_SIZE);
		printf("\nSave_file before: %s", save_file);
		ret = concat(ret, save_file);
		printf("\nSave_file after: %s", save_file);
	}
	ret = concat(ret, save_file);
	// if (save_file == 0)
		// free(save_file);
	return (ret);
}
