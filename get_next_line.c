/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:39:41 by esali             #+#    #+#             */
/*   Updated: 2022/10/16 18:40:03 by esali            ###   ########.fr       */
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
	static char	*file;
	static int	i;
	
	printf("\nBUFFER_SIZE: %i", BUFFER_SIZE);
	if (file == 0) {
		file = (char *) malloc(BUFFER_SIZE * sizeof(char));
		if (!file)
			return NULL;
	}
	i = 0;
	while (file[i] != '\n')
	{
		read(fd, file, BUFFER_SIZE);
		i++;
		// TODO: 
		// What is read() returning?
		// Think of and write down overall working logic of program before starting to code!
		// 
	}
	return (file);
}