/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:22:49 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/01 16:09:35 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include "stdio.h"

/* size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	j = ft_strlen(src);
	i = 0;
	if (!dest || !src)
		return (0);
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
} */

int	count_words(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

int	get_word_length(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

void	copy_word(char **arr, const char *str, int len, int index)
{
	arr[index] = malloc(len + 1);
	if (arr[index] != NULL)
	{
		ft_strlcpy(arr[index], (char *) str, len + 1);
		arr[index][len] = '\0';
	}
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**res;
	int		index;
	int		len;

	words = count_words(s, c);
	if (!words)
		return (NULL);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		len = get_word_length(s, c);
		if (len > 0)
			copy_word(res, s, len, index++);
		s += len;
	}
	res[index] = NULL;
	return (res);
}

/* int main(void)
{
	char *string = "-";
	char c = ' ';
	
	char **tab = ft_split(string, c);
	printf("\nRESULT\n");
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%s\n", tab[i]);
} */