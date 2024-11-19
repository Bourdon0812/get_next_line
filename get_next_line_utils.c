/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbonnev <ilbonnev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:58:30 by ilbonnev          #+#    #+#             */
/*   Updated: 2024/11/19 17:32:33 by ilbonnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_has_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*ft_strcat(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*res;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (str1)
	{
		while (str1[i] != '\0')
		{
			res[i] = str1[i];
			i++;
		}
	}
	j = 0;
	while (str2 && str2[j] != '\0')
		res[i++] = str2[j++];
	res[i] = '\0';
	free(str1);
	return (res);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*copy;
	int		i;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (copy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return ;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
}
