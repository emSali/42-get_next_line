/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:58:05 by esali             #+#    #+#             */
/*   Updated: 2022/10/24 17:35:11 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	printf("\nft_strlen returns: %i", i);
	return (i);
}

// checks if String str has a new line
int	has_new_line(char *str)
{
	while(*str != '\0')
	{
		if (*str == '\n')
		{
			// printf("\n has_new_line returns: true\n");
			return 1;
		}
		str++;
	}
	// printf("\n has_new_line returns: false\n");
	return 0;
}

//concats two Strings behind each other, the second string is concatenated until a new line is found
char	*concat(char *str1, char *str2)
{
	char	*ret;
	int		i;

	if (str1 == 0)
		ret	= (char *) malloc(sizeof(char) * (ft_strlen(str2) + 1));
	else
		ret	= (char *) malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!ret)
		return NULL;
	i = 0;
	while (str1[i] != 0)
	{
		ret[i] = str1[i];
		i++;
	}
	while (str2[0] != 0)
	{
		ret[i] = str2[0];
		remove_first_char(str2);
		if (ret[i] == '\n')
		{
			ret[i] = '\0';
			return (ret);
		}
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

//removes first char from String
void	remove_first_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = str[i + 1];
		i++;
	}
}


