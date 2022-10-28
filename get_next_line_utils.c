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

//returns lenght -1
int	ft_strlen(char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//concats two Strings behind each other, the second string is concatenated until a new line is found
char	*concat(char *str1, char *str2)
{
	char	*ret;
	int		i;
	int		j;

	ret	= (char *) malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!ret)
		return NULL;
	i = 0;
	while (str1[i] != 0)
	{
		ret[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[0] != 0)
	{
		ret[i] = str2[0];
		remove_first_char(str2);
		if (ret[i] == '\n')
		{
			ret[i + 1] = '\0';
			return (ret);
		}
		i++;
		j++;
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

char	*remove_first_line(char *str)
{
	char	*tmp;
	char	*ret;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	tmp = str;
	i = 0;
	while(tmp[i] != '\n' && tmp[i])
	{
		str[i] = str[i + 1];
		i++;
	}
	if (tmp[i] == '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(tmp) - i));
	j = 0;
	while(tmp[i])
	{
		ret[j] = tmp[i];
		i++;
		j++;
	}
	ret[j] = 0;
	free(tmp);
	return (ret);
}


