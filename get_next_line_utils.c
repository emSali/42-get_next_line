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

char	last_char(char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	return (str[ft_strlen(str) - 1]);
}

char	*concat(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ret[i] = s2[j];
		if (ret[i] == '\n')
		{
			ret[i + 1] = '\0';
			return (ret);
		}
		j++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	remove_first_line(char *str)
{
	int		i;

	while(str[0] != '\n' && str[0] != 0)
	{
		i = 0;
		while(str[i] != 0)
		{
			str[i] = str[i + 1];
			i++;
		}
		str[i] = 0;
	}
	i = 0;
	if (str[0] == '\n')
	{
		while (str[i] != '\0')
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	str[i] = 0;
}


